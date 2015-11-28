%{
	#include <algorithm>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <typeinfo>
	#include <stack>
	#include <vector>
	#include <math.h>
	#include <sstream>
	#include <iterator>
	#include "endgame.h"
	#include "types.h"
	#include "symtbl.h"
	#include "actions.h"
	#include "statement.h"

int errors;
char errormsg[255];
int yydebug;
Type tCurr;

std::stack<Expression*> exprs;
std::stack< std::vector<Expression*> > args;
std::vector<Statement*> statements;

Action CurrentAction = NoAction;
BoolCond CurrentBool = NoBool;

int yylex(void);
void yyerror(const char *s);


#define YYDEBUG 0

%}

%union { /* SEMANTIC RECORD */
		char* sval;
		char* id;
		char* action;
    char* loop;
		char* ifval;
		char* whenval;
		char* tryval;
	}

%token<action> STATEMENTNUMSYMBOL
%token<action> STATEMENTNUMSYMBOLSTART

%token<loop> BEGINLOOP
%token<loop> ENDLOOP

%token<action> ACTIONSYMBOL
%token<sval> TRYSINKACTION
%token<sval> SHOWVARACTION
%token<sval> ADDBOATACTION
%token<sval> ATTACKBOATACTION
%token<sval> RANDOMADDBOATACTION
%token<sval> SEEKACTION

%token<action> BEGINIFCOND
%token<action> ENDIFCOND
%token<sval> FINDSBOAT
%token<ifval> BEGINELSE
%token<ifval> ENDELSE

%token<whenval> WHENSTATEMENT
%token<tryval> TRYSTATEMENT
%token<tryval> BEGINTRYSTATEMENT
%token<tryval> ENDTRYSTATEMENT

%token<sval> COMPUTERLITERAL
%token<sval> PLAYERLITERAL
%token<sval> GRIDLITERAL
%token<sval> STRINGLITERAL
%token<sval> CHARLITERAL
%token<sval> INTLITERAL

%token<id> IDENTIFIER
%token INTTYPE CHARTYPE STRINGTYPE GRIDTYPE PLAYERTYPE COMPUTERTYPE
%token ASSIGNOP
%left '+' '-'
%left '*' '/'


%error-verbose

%%

input : /* empty */
	| input line	{ lineNumberGlobal++; }
;

line : IDENTIFIER ASSIGNOP expr
			{
        CurrentAction = AssignAction;
        Expression* newExpr = exprs.top();
        AssignToVar* assign = new AssignToVar($1, newExpr);
        statements.push_back(assign);
			}
	| typedecl IDENTIFIER
			{
        CurrentAction = DeclareAction;
				VarDeclare* myVar = new VarDeclare($2, tCurr);
        statements.push_back(myVar);
			}
	| IDENTIFIER ACTIONSYMBOL action
	{
    switch(CurrentAction){
      case NoAction:
        printf("Error: No action selected.\n");
        break;
      case AddBoatAction:
          //adds statement to vector
          {Boat* boat = new Boat($1, args.top());
          statements.push_back(boat);}
        break;
      case AttackBoatAction:
          //adds statement to vector
          {Attack* attack = new Attack($1, exprToString(args.top()[0]), strdup(exprToString(exprs.top()).c_str()));
          statements.push_back(attack);}
        break;
      case ShowVarAction:
          {ShowVar* showVar = new ShowVar($1);
          statements.push_back(showVar);}
        break;
      case RandomAddBoatAction:
          {RandBoat* randBoat = new RandBoat($1, args.top()[0]);
          statements.push_back(randBoat);}
        break;
			case SeekAction:
					{Seek* seek = new Seek($1, exprToInt(args.top()[0]), strdup(exprToString(args.top()[1]).c_str()));
					statements.push_back(seek);}
				break;
			case TrySinkAction:
				//												 		varName, 			varAttackedName, 																		direction, 							afterHitSeekDistance
				//															vv							vv																									vv												vv
				{TrySink* trySink = new TrySink($1, strdup(exprToString(args.top()[2]).c_str()), exprToString(args.top()[0]), exprToInt(args.top()[1]));
				statements.push_back(trySink);}
				break;
      default:
        //printf("Error: Invalid Action. Action %d does not exist.\n", (int)CurrentAction);
				{std::string actionNumber = std::to_string((int)CurrentAction);
				std::string errorMessage = "Invalid Action. Action ";
				errorMessage += actionNumber;
				errorMessage += " does not exist.";
				logError(errorMessage);}
        break;
      }
	}
  | BEGINLOOP STATEMENTNUMSYMBOLSTART
      {
        BeginLoop* bLoop = new BeginLoop(lineNumberGlobal, true);
        statements.push_back(bLoop);
      }
  | ENDLOOP
      {
        EndLoop* eLoop = new EndLoop();
        statements.push_back(eLoop);
      }
	| BEGINIFCOND boolcond STATEMENTNUMSYMBOLSTART
			{
				BeginIfCond* bIfCond = new BeginIfCond(strdup(exprToString(exprs.top()).c_str()), CurrentBool);
				statements.push_back(bIfCond);
				CurrentBool = NoBool;
			}
	| ENDIFCOND
			{
				EndIfCond* eIfCond = new EndIfCond();
				statements.push_back(eIfCond);
			}
	| BEGINELSE STATEMENTNUMSYMBOLSTART
		{
			BeginElse* bElse = new BeginElse();
			statements.push_back(bElse);
		}
	| ENDELSE
		{
			EndElse* eElse = new EndElse();
			statements.push_back(eElse);
		}
	| BEGINTRYSTATEMENT STATEMENTNUMSYMBOLSTART
			{
				BeginTryStatement* bTry = new BeginTryStatement();
				statements.push_back(bTry);
			}
	| ENDTRYSTATEMENT
		{
				EndTryStatement* eTry = new EndTryStatement();
				statements.push_back(eTry);
		}
	| INTLITERAL STATEMENTNUMSYMBOL TRYSTATEMENT STATEMENTNUMSYMBOLSTART line
		{
			TryStatement* myTry = new TryStatement(getIntegerValue(std::string($1)), statements.back());
			statements.pop_back();
			statements.push_back(myTry);
		}
	| WHENSTATEMENT
		{

		}
;

boolcond : IDENTIFIER ACTIONSYMBOL FINDSBOAT
	{
		Expression* varName = new Expression();
		varName->type = String;
		varName->value = (void*) new std::string($1);

		CurrentBool = FindsBoatBool;
		exprs.push(varName);
	}

action : ADDBOATACTION
	{
    CurrentAction = AddBoatAction;
    args.push(typifyArgs(getArguments(std::string($1))));
	}
| ATTACKBOATACTION ACTIONSYMBOL IDENTIFIER
  {
    CurrentAction = AttackBoatAction;

    //store name of boat in expression
    Expression* myExpr = new Expression();
    myExpr->type = String;
    myExpr->value = (void*) new std::string($3);

    exprs.push(myExpr); //name of the attacked boat
    args.push(typifyArgs(getArguments(std::string($1)))); //gridpoint to be attacked
  }
| SEEKACTION ACTIONSYMBOL IDENTIFIER
	{
		CurrentAction = SeekAction;

		Expression* seeknumber = new Expression();
		seeknumber->type = Int;
		seeknumber->value = (void*) new int(getIntegerValue(std::string($1)));

		Expression* varAttackedName = new Expression();
		varAttackedName->type = String;
		varAttackedName->value = (void*) new std::string($3);

		std::vector<Expression*> myArgs;
		myArgs.push_back(seeknumber);
		myArgs.push_back(varAttackedName);

		args.push(myArgs);
	}
| SHOWVARACTION
	{
	  CurrentAction = ShowVarAction;
	}
| RANDOMADDBOATACTION
	{
	  CurrentAction = RandomAddBoatAction;
	  args.push(typifyArgs(getArguments(std::string($1))));
	}
| TRYSINKACTION ACTIONSYMBOL IDENTIFIER
	{
		CurrentAction = TrySinkAction;
		args.push(typifyArgs(getArguments(std::string($1)))); //get direction and afterHitSeekDistance

		Expression* myExpr = new Expression();
		myExpr->type = String;
		myExpr->value = (void*) new std::string($3); //get varAttackedName
		args.top().push_back(myExpr);
	}

expr : INTLITERAL
		{
			int r = getIntegerValue(std::string($1));
      Variable* l = new Variable();
			l->type = Int;
			l->value = (void*) new int(r);
			exprs.push(l);
		}
	| CHARLITERAL
		{
			Variable* l = new Variable();
			l->type = Char;
			l->value = (void*) new char($1[0]);
			exprs.push(l);
		}
	| STRINGLITERAL
		{
			Variable* l = new Variable();
			l->type = String;
			l->value = (void*)(strdup($1));
			exprs.push(l);
		}
	| PLAYERLITERAL
	{
    Variable *l = new Variable();
		Player* p = new Player($1);
		l->type = PlayerType;
    l->value = p;
		exprs.push(l);
	}
	| COMPUTERLITERAL
	{
    Variable *l = new Variable();
    Computer* c = new Computer($1);
    l->type = ComputerType;
    l->value = c;
    exprs.push(l);
	}
	| IDENTIFIER
		{
			Variable* v = get_symbol($1);
			if (v == NULL) {
				sprintf(errormsg, "symbol not found: %s", $1);
				yyerror(errormsg);
			}
			else {
				exprs.push(v);
			}
		}
;


typedecl : INTTYPE { tCurr = Int; }
	| CHARTYPE { tCurr = Char; }
	| STRINGTYPE { tCurr = String; }
	| PLAYERTYPE { tCurr = PlayerType; }
	| COMPUTERTYPE { tCurr = ComputerType; }
;

%%

void setLoopIDs(){
	int loopID = 0; //start initial loopID at 0
	//set all beginning loop ID's
	for(int i = 0; i < statements.size(); i++){
		if(statements[i]->getAction() == BeginLoopAction){
			dynamic_cast<BeginLoop*>(statements[i])->setLoopID(++loopID);
		}
	}
	//set all end loop ID's
	for(int i = statements.size() - 1; i > 0; i--){
		if(statements[i]->getAction() == EndLoopAction){
			dynamic_cast<EndLoop*>(statements[i])->setLoopID(loopID--);
		}
	}
}

void setIfCondIDs(){
	std::map<int, Statement*> ifConds;
	int ifCondID = 0;

	//set all beginning ifCondIDs
	for(int i = 0; i < statements.size(); i++){
		if(statements[i]->getAction() == BeginIfCondAction){
			dynamic_cast<BeginIfCond*>(statements[i])->setIfCondID(++ifCondID);
			ifConds.insert(std::pair<int, Statement*>(ifCondID, statements[i]));
		}
	}

	//set all ending ifCondIDs
	for(int i = statements.size() - 1; i > 0; i--){
		BeginIfCond* bIfCond = dynamic_cast<BeginIfCond*>(ifConds[ifCondID]);

		if(statements[i]->getAction() == EndIfCondAction){
			//look for else statements
			for(int j = i; j < statements.size(); j++){

				//if there is an if condition before the else statement, the else doesn't apply to current statement
				if(statements[j]->getAction() == BeginIfCondAction){
					j = statements.size() - 1; //exit the loop
				}

				//if an else statement comes after the if statement, it applies
				else if(statements[j]->getAction() == BeginElseAction){
					dynamic_cast<BeginElse*>(statements[j])->setIfCondID(ifCondID); //associate the else statement with the if statement
					bIfCond->setElseLine(j); //let the if statement know where the else statement begins

					//look for the end of the else statement
					for(int k = j; k < statements.size(); k++){
						if(statements[k]->getAction() == EndElseAction){
							bIfCond->setElseExitLine(k); //let the if statement know where the else statement ends
							break;
						}
					}
				} //end else if
			} //end for

			bIfCond->setExitLine(i); //set the if statement exit line
			EndIfCond* eIfCond = dynamic_cast<EndIfCond*>(statements[i]); //get the end of the if statement
			eIfCond->setElseExitLine(bIfCond->getElseExitLine()); //let the end of the if statement know where the end of the else statement is
			eIfCond->setIfCondID(ifCondID--); //associate the beginning of the if with the end of the if
		} //end if
	} //end for
}

void setElseIDs(){
	std::map<int, Statement*> elses;
	int elseID = 0;

	for(int i = 0; i < statements.size(); i++){
		if(statements[i]->getAction() == BeginElseAction){
			dynamic_cast<BeginElse*>(statements[i])->setExitLine(++elseID);
			elses.insert(std::pair<int, Statement*>(elseID, statements[i]));
		}
	}

	for(int i = statements.size() - 1; i > 0; i--){
		if(statements[i]->getAction() == EndElseAction){
			dynamic_cast<BeginElse*>(elses[elseID])->setExitLine(i);
			dynamic_cast<EndElse*>(statements[i])->setElseID(elseID--);
		}
	}
}

void setTryStatementIDs(){
	int tryStatementID = 0;
	for(int i = 0; i < statements.size(); i++){

		//look for the beginning of the try statement
		if(statements[i]->getAction() == BeginTryStatementAction){

			//set the try statement ID
			BeginTryStatement* bTry = dynamic_cast<BeginTryStatement*>(statements[i]);
			bTry->setTryStatementID(++tryStatementID);

			//look for the try statement commands between the beginning of the try statement and the end of the try statement
			for(int j = i; j < statements.size(); j++){
				if(statements[j]->getAction() == TryStatementAction){
					TryStatement* myTry = dynamic_cast<TryStatement*>(statements[j]);
					myTry->setTryStatementID(tryStatementID);
				}else if(statements[j]->getAction() == EndTryStatementAction){
					bTry->setTryStatementExitLine(i);
					dynamic_cast<EndTryStatement*>(statements[j])->setTryStatementID(tryStatementID--);
					j = statements.size() - 1; //exit the loop when the end of the try statement is found
				}
			}
		}
	}
}

void runGame(){

	bool debug = true; //turns on debug notifications

  //a map containing the loopID as the key, and the statement number as the value
	std::map<int, int> loopIDs;
  bool continueLoop = true;
	bool skipElse = false;

	int currentStatementNum = 0;
	while(currentStatementNum < statements.size()){
		if(debug){
			printf("Statement Number: %d --> ", currentStatementNum); ///---------------------------------------
			printf("Action: %s\n", strdup(actionnames[(int)statements[currentStatementNum]->getAction()].c_str())); ///----------------------------
		}

		try{
      switch(statements[currentStatementNum]->getAction()){
        case NoAction:
          printf("No action selected.\n");
          currentStatementNum++;
          break;
        case AddBoatAction:
          dynamic_cast<Boat*>(statements[currentStatementNum])->execute();
					currentStatementNum++;
          break;
        case RandomAddBoatAction:
          dynamic_cast<RandBoat*>(statements[currentStatementNum])->execute();
					currentStatementNum++;
          break;
        case AttackBoatAction:
          dynamic_cast<Attack*>(statements[currentStatementNum])->execute();
					currentStatementNum++;
          break;
        case ShowVarAction:
          dynamic_cast<ShowVar*>(statements[currentStatementNum])->execute();
					currentStatementNum++;
          break;
        case AssignAction:
          dynamic_cast<AssignToVar*>(statements[currentStatementNum])->execute();
					currentStatementNum++;
          break;
        case DeclareAction:
          dynamic_cast<VarDeclare*>(statements[currentStatementNum])->execute();
					currentStatementNum++;
          break;
				case SeekAction:
					dynamic_cast<Seek*>(statements[currentStatementNum])->execute();
					currentStatementNum++;
					break;
        case BeginLoopAction:
	        {
	          BeginLoop* bLoop = dynamic_cast<BeginLoop*>(statements[currentStatementNum]);
	          if(loopIDs.count(bLoop->getLoopID()) == 0){
	            loopIDs.insert(std::pair<int, int>(bLoop->getLoopID(), currentStatementNum));
	          }
	          if(!continueLoop){
	            currentStatementNum = bLoop->getExitLine();
	            continueLoop = true;
	          }else{
							bLoop->execute();
							currentStatementNum++;
						}
	        }
          break;
        case EndLoopAction:
	        {
	          EndLoop* eLoop = dynamic_cast<EndLoop*>(statements[currentStatementNum]);
	          if(loopIDs.count(eLoop->getLoopID())){

	            //tells the beginning of the loop what line to exit
	            dynamic_cast<BeginLoop*>(statements[loopIDs[eLoop->getLoopID()]])->setExitLine(currentStatementNum);

	            //goes to the beginning of the loop again
	            currentStatementNum = loopIDs[eLoop->getLoopID()];
	          }
	        }
          break;
				case BeginIfCondAction:
					{
						BeginIfCond* bIfCond = dynamic_cast<BeginIfCond*>(statements[currentStatementNum]);
						bIfCond->execute();

						//check if the condition is true --> if it is, go through the statements that follow
						//	if it's not, then exit the IfCond and go to the else exit line
						if(bIfCond->getCondition() && bIfCond->getElseLine() != -1){
							skipElse = true;
							currentStatementNum++;
						}else if(bIfCond->getCondition()){
							currentStatementNum++;
						}else if(bIfCond->getElseLine() != -1){
							//if an else statement is associated with the if statement, go to the else statement
							currentStatementNum = bIfCond->getElseLine();
						}else{
							currentStatementNum = bIfCond->getExitLine();
						}
					}
					break;
				case EndIfCondAction:
					{
						if(skipElse){
							currentStatementNum = dynamic_cast<EndIfCond*>(statements[currentStatementNum])->getElseExitLine(); //skip the else statement
							skipElse = false;
						}else{
							currentStatementNum++;
						}
					}
					break;
				case BeginElseAction:
					dynamic_cast<BeginElse*>(statements[currentStatementNum])->execute();
					currentStatementNum++;
					break;
				case EndElseAction:
					dynamic_cast<EndElse*>(statements[currentStatementNum])->execute();
					currentStatementNum++;
					break;
				case BeginTryStatementAction:
					currentStatementNum++;
					break;
				case TryStatementAction:
					{
						TryStatement* tStatement = dynamic_cast<TryStatement*>(statements[currentStatementNum]);

						//check if the statement should be executed (if it hasn't been tried yet)
						if(tStatement->getTried()){
							tStatement->execute();
						}
					}
					currentStatementNum++;
					break;
				case EndTryStatementAction:
					currentStatementNum++;
					break;
				case TrySinkAction:
					printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nTry sink action called...\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); ///------------------------------------------------
					dynamic_cast<TrySink*>(statements[currentStatementNum])->execute();
					currentStatementNum++;
					break;
        default:
          //printf("Could not execute statement.\n");
					logError("Could not execute statement in runGame.");
          currentStatementNum = statements.size() - 1; //quit game
          break;
      }
    }catch(std::exception& e){
      continueLoop = false;
      std::cout << e.what() << std::endl;
			currentStatementNum++;
    }
	}
}

int main (int argc, char *argv[]) {
  srand(time(NULL)); //seed the random

  extern FILE *yyin;
  ++argv; --argc;
  yyin = fopen(argv[0], "r");
  yydebug = 1;
  errors = 0;
  yyparse();

	setLoopIDs();
	setIfCondIDs();
	setElseIDs();
	setTryStatementIDs();

  printf("\n-----------------START GAME-----------------\n");
  runGame();
  printf("\n--------------------Exit--------------------\n");

  cleanupTable();
  printf("Parse Completed: %d errors.\n", errors);
	displayUserErrors();
}

void yyerror(const char *s) {
	errors++;
	printf("%d: syntax error: %s\n", lineNumberGlobal, s);
}
