#ifndef __STATEMENT_H__
#define __STATEMENT_H__

#include <iostream>
#include <queue>
#include "actions.h"
#include "symtbl.h"

enum Action {NoAction, AddBoatAction,
  AttackBoatAction, ShowVarAction,
  AssignAction, DeclareAction,
  BeginTryStatementAction, EndTryStatementAction,
  TryStatementAction, TrySinkAction,
  BeginIfCondAction, EndIfCondAction,
  BeginElseAction, EndElseAction,
  BeginLoopAction, EndLoopAction,
  RandomAddBoatAction, SeekAction};

std::string actionnames[] = {"NoAction", "AddBoatAction",
  "AttackBoatAction", "ShowVarAction",
  "AssignAction", "DeclareAction",
  "BeginTryStatementAction", "EndTryStatementAction",
  "TryStatementAction", "TrySinkAction",
  "BeginIfCondAction", "EndIfCondAction",
  "BeginElseAction", "EndElseAction",
  "BeginLoopAction", "EndLoopAction",
  "RandomAddBoatAction", "SeekAction"};

enum BoolCond {NoBool, FindsBoatBool};

typedef enum Action Action;
typedef enum BoolCond BoolCond;

//STATEMENTS
class Statement{
protected:
    Action action;

public:
    virtual ~Statement(){}
    virtual Statement *Clone() = 0;
    virtual void execute() = 0;
    Action getAction() { return action; }
};


//TYPE DECLARE VAR
class VarDeclare : public Statement{
private:
  char* varName;
  Type tCurr;

public:
  VarDeclare(char* varName, Type tCurr){
    this->action = DeclareAction;
    this->varName = varName;
    this->tCurr = tCurr;
  }

  ~VarDeclare(){
    delete varName;
    varName = NULL;
  }

  //deep copy constructor
  Statement *Clone() { return new VarDeclare(*this); }

  void execute(){
    Variable* t = add_symbol(varName, tCurr);
    if (t == NULL) {
      //printf("symbol %s already exists", varName);
      std::string message = "symbol ";
      message += std::string(varName);
      message += " already exists.";
      logError(message);
      throw syntaxError;
    }
  }
};

//ASSIGN TO VAR
class AssignToVar : public Statement{
private:
  char* varName;
  Expression* exprAssigned;

public:
  AssignToVar(char* varName, Expression* exprAssigned){
    this->action = AssignAction;
    this->varName = varName;
    this->exprAssigned = exprAssigned;
  }

  ~AssignToVar(){
      delete varName;
      varName = NULL;
      delete exprAssigned;
      exprAssigned = NULL;
  }

  //deep copy constructor
  Statement *Clone() { return new AssignToVar(*this); }

  void execute(){
    Variable* var = get_symbol(varName);
    if (var == NULL) {
      //printf("%s not found.\n", varName);
      std::string message = "symbol ";
      message += std::string(varName);
      message += " not found.";
      logError(message);
      throw syntaxError;
    }
    // type checking
    if (var->type != exprAssigned->type) {
      printf("incompatible types. Assigning %d to %d\n\n", exprAssigned->type, var->type);
    }else{
      //stores the value given in the void* inside the variable
      var->value = (void*)(exprAssigned->value);
    }
  }
};

//LOOPS----------------------------------------------------------
class BeginLoop : public Statement{
private:
  int loopID;
  int lineNumber;
  int repetitions;
  int loopExitLine;
  bool condition;

public:
  BeginLoop(int lineNumber, bool condition){
    this->action = BeginLoopAction;
    this->lineNumber = lineNumber;
    this->repetitions = 0;
    this->condition = condition;
    this->loopExitLine = -1;
  }

  ~BeginLoop(){}

  //deep copy constructor
  Statement *Clone() { return new BeginLoop(*this); }

  int getLoopID() { return loopID; }
  int getExitLine() { return loopExitLine; }
  bool getCondition() { return condition ; }
  void setExitLine(int loopExitLine) { this->loopExitLine = loopExitLine + 1; }
  void setLoopID(int loopID){ this->loopID = loopID; }
  void setCondition(bool condition) { this->condition = condition; }
  void execute(){ repetitions++; }
};

class EndLoop : public Statement{
private:
  int loopID;
  int lineNumber;

public:
  EndLoop(){
    this->action = EndLoopAction;
  }
  ~EndLoop(){}

  //deep copy constructor
  Statement *Clone() { return new EndLoop(*this); }

  int getLoopID(){ return loopID; }
  void setLoopID(int loopID){ this->loopID = loopID; }
  void execute(){ }
};

//If CONDITIONS-----------------------------------------------

class BeginIfCond : public Statement{
private:
  int ifCondID;
  int ifCondExitLine;
  int elseLine;
  int elseExitLine;
  bool condition;
  BoolCond boolType;
  char* varName;

public:
  BeginIfCond(char* varName, BoolCond boolType){
    this->action = BeginIfCondAction;
    this->boolType = boolType;
    this->varName = varName;
    this->elseLine = -1;
  }

  ~BeginIfCond(){
    delete varName;
    varName = NULL;
  }

  //deep copy constructor
  Statement *Clone() { return new BeginIfCond(*this); }

  bool getCondition(){ return condition; }
  int getExitLine() { return ifCondExitLine; }
  int getIfCondID() { return ifCondID; }
  int getElseLine() { return elseLine; }
  int getElseExitLine() { return elseExitLine; }
  void setIfCondID(int ifCondID){ this->ifCondID = ifCondID; }
  void setElseLine(int elseLine){ this->elseLine = elseLine; }
  void setElseExitLine(int elseExitLine){ this->elseExitLine = elseExitLine; }
  void setExitLine(int ifCondExitLine) { this->ifCondExitLine = ifCondExitLine + 1; }

  void execute() {
    Variable* var = get_symbol(varName);
    if(var == NULL){
      //printf("%s not found.\n", varName);
      std::string message = "symbol ";
      message += std::string(varName);
      message += " not found.";
      logError(message);
      throw syntaxError;
    }else{
      //check if the players are of the right type
      if(var->type == PlayerType || var->type == ComputerType){
        switch (boolType) {
          case FindsBoatBool:
            condition = static_cast<Player*>(var->value)->didLocateBoat();
            break;
          case NoBool:
            //printf("Bool type not assigned\n");
            logError("Bool type not assigned.");
            throw syntaxError;
            break;
          default:
            //printf("Could not perform bool action\n");
            logError("Could not perform bool action");
            throw syntaxError;
            break;
        }
      }
    }
  }
};

class EndIfCond : public Statement{
private:
  int ifCondID;
  int elseExitLine;

public:
  EndIfCond(){
    this->action = EndIfCondAction;
  }

  ~EndIfCond(){}
  //deep copy constructor
  Statement *Clone() { return new EndIfCond(*this); }

  int getIfCondID() { return ifCondID; }
  int getElseExitLine() { return elseExitLine; }
  void setIfCondID(int ifCondID){ this->ifCondID = ifCondID; }
  void setElseExitLine(int elseExitLine){this->elseExitLine = elseExitLine;}
  void execute() { }
};

//Begin Else
class BeginElse : public Statement{
private:
  int ifCondID;
  int elseID;
  int elseExitLine;

public:
  BeginElse(){
    this->action = BeginElseAction;
  }
  ~BeginElse(){}
  //deep copy constructor
  Statement *Clone() { return new BeginElse(*this); }

  int getIfCondID() {return ifCondID; }
  int getElseID() { return elseID; }
  void setIfCondID(int ifCondID){ this->ifCondID = ifCondID; }
  void setElseID(int elseID){ this->elseID = elseID; }
  void setExitLine(int elseExitLine){ this->elseExitLine = elseExitLine; }
  void execute() { }
};

//End else
class EndElse : public Statement{
private:
  int elseID;

public:
  EndElse(){
    this->action = EndElseAction;
  }
  ~EndElse(){}
  //deep copy constructor
  Statement *Clone() { return new EndElse(*this); }

  int getElseID() { return elseID; }
  void setElseID(int elseID){ this->elseID = elseID; }
  void execute() { }
};

//SHOW----------------------------------------------------------
class ShowVar : public Statement{
private:
  char* varName;

public:
  ShowVar(char* varName){
    this->action = ShowVarAction;
    this->varName = varName;
  }

  ~ShowVar(){
    delete varName;
    varName = NULL;
  }

  //deep copy constructor
  Statement *Clone() { return new ShowVar(*this); }

  void execute(){

    Variable* myVar = get_symbol(varName);

    if(myVar == NULL){
      //printf("Var does not exist\n");
      std::string message = "symbol ";
      message += std::string(varName);
      message += " not found.";
      logError(message);
      throw syntaxError;
      return;
    }

    switch (myVar->type) {
      case Int:
        std::cout << exprToInt(myVar) << std:: endl;
        break;
      case Char:
        std::cout << exprToChar(myVar) << std::endl;
        break;
      case String:
        std::cout << exprToString(myVar) << std::endl;
        break;
      case PlayerType:
        std::cout << static_cast<Player*>(myVar->value)->getPlayerStats() << std::endl;
        break;
      case ComputerType:
        std::cout << static_cast<Player*>(myVar->value)->getPlayerStats() << std::endl;
        break;
      default:
        //printf("Display is not supported for this type\n");
        logError("Display not supported for this type.");
        throw syntaxError;
        break;
    }
  }
};

//BOAT STUFF----------------------------------------------------------
class Boat : public Statement{
private:
  char* varName;
  std::vector<Expression*> typedArgs;

public:
  Boat(char* varName, std::vector<Expression*> typedArgs){
    this->action = AddBoatAction;
    this->varName = varName;
    this->typedArgs = typedArgs;
  }

  ~Boat(){
    delete varName;
    varName = NULL;

    for(int i = 0; i < typedArgs.size(); i++){
      delete typedArgs[i];
      typedArgs[i] = NULL;
    }
  }

  //deep copy constructor
  Statement *Clone() { return new Boat(*this); }

  //adds a boat to the specified variable
  void execute(){
    Variable* var = get_symbol(varName);

    if(var == NULL){
      //printf("Variable %s not found\n", varName);
      std::string message = "symbol ";
      message += std::string(varName);
      message += " not found.";
      logError(message);
      return;
    }

    //Figures out if the boat should be vertical or not
    if(typedArgs.size() == 4){
      bool vertical = false; //determines whether or not the boat will be placed vertically or horizontally

      //if the value is 'v', it's supposed to be vertical
      if(exprToChar(typedArgs[3]) == 'v'){
        vertical = true;
      }
      //adds a boat to the specified types
      if(var->type == PlayerType || var->type == ComputerType){
        static_cast<Player*>(var->value)->addBoat(exprToString(typedArgs[0]), exprToChar(typedArgs[1]), exprToInt(typedArgs[2]), vertical, true);
      }
    }else{
      //printf("addBoat() needs 4 arguments but %d were given.\n", (int)typedArgs.size());
      logError("Incorrect number of arguments in addBoat().");
      throw syntaxError;
    }
  }
};

class RandBoat : public Statement{
private:
  char* varName;
  int numBoats;

public:
  RandBoat(char* varName, Expression* myExpr){
    this->action = RandomAddBoatAction;
    this->varName = varName;

    if(myExpr->type == Int){
      this->numBoats = exprToInt(myExpr);
    }else{
      //printf("Incorrect expression type. Must be Int.\n");
      logError("Incorrect expression type. Must be Int.");
      throw syntaxError;
      this->numBoats = 5;
    }
  }

  ~RandBoat(){
    delete varName;
    varName = NULL;
  }

  //deep copy constructor
  Statement *Clone() { return new RandBoat(*this); }

  void execute(){
    Variable* var = get_symbol(varName);
    if(var == NULL){
      //printf("Variable %s not found\n", varName);
      std::string message = "symbol ";
      message += std::string(varName);
      message += " not found.";
      logError(message);
      throw syntaxError;
      return;
    }

    if(var->type == PlayerType || var->type == ComputerType){
      static_cast<Player*>(var->value)->randomAddBoats(numBoats);
    }
  }

};

//ATTACK----------------------------------------------------------
class Attack : public Statement{
private:
  char* varName;
  char* varAttackedName;
  std::string gridPoint;

public:
  Attack(char* varName, std::string gridPoint, char* varAttackedName){
    this->action = AttackBoatAction;
    this->varName = varName;
    this->varAttackedName = varAttackedName;
    this->gridPoint = gridPoint;
  }

  ~Attack(){
    delete varName;
    varName = NULL;
    delete varAttackedName;
    varAttackedName = NULL;
  }

  //deep copy constructor
  Statement *Clone() { return new Attack(*this); }

  //Attacks a player at specified gridPoint
  void execute(){
    Variable* var = get_symbol(varName);
    Variable* varAttacked = get_symbol(varAttackedName); //the player who is attacked

    //prevents player from attacking him or herself
    if(var->name == varAttacked->name){
      //std::cout << "Player cannot attack its own ships." << std::endl;
      logError("Player cannot attack its own ships.");
      throw syntaxError;
      return;
    }

    int numVarAttackedBoats = 0;

    BoatStatus hitStatus = BoatMiss; //keeps track of status, so attacking player's stats can be updated
    std::vector<std::string> sunkBoatCoords; //for updating the attacking player's map

    if((varAttacked->type == PlayerType || varAttacked->type == ComputerType) && (var->type == PlayerType || var->type == ComputerType)){
      Player* myPlayer = static_cast<Player*>(var->value);
      Player* thePlayerAttacked = static_cast<Player*>(varAttacked->value);

      if(myPlayer->isPerson()){
        gridPoint = getUserInput(myPlayer);
      }

      //the actual attack
      //if thePlayerAttacked exists...
      if(thePlayerAttacked){
        myPlayer->numOpponentBoats = thePlayerAttacked->playerBoats.size(); //tell the attacker the number of boats the opponent has
        myPlayer->opponentName = thePlayerAttacked->playerName;             //tell the attacker the name of the opponenet
        hitStatus = thePlayerAttacked->attackBoat(gridPoint);               //record the success/failure of the attack
        if(hitStatus == BoatSunk){
          std::map<std::string, bool>::iterator it;
          for(it = thePlayerAttacked->playerBoats[thePlayerAttacked->playerGrid.grid[gridPoint]].locations.begin(); it != thePlayerAttacked->playerBoats[thePlayerAttacked->playerGrid.grid[gridPoint]].locations.end(); it++){
            myPlayer->opponentGrid.grid[it->first] = (int)BoatSunk;

            //if the player is a computer
            if(var->type == ComputerType){
              Computer* myComputer = static_cast<Computer*>(myPlayer);
              //myComputer->setTrackBack("none"); //if the boat was sunk, forget the trackBack location
              myComputer->emptyTrackBack(); //if the boat was sunk, forget the trackBack locations
            }

          }
        }else if(hitStatus == BoatHit){
          myPlayer->opponentGrid.grid[gridPoint] = (int)BoatHit;
          //if the player is a computer
          if(var->type == ComputerType){
            Computer* myComputer = static_cast<Computer*>(myPlayer);
            //if(myComputer->getTrackBack() == "none"){ myComputer->setTrackBack(gridPoint); } //enables the computer to know where it started trying to sink the boat
            if(myComputer->getTrackBack().size() == 0){
              Coordinate coord(gridPoint);
              myComputer->setTrackBack(coord);
            } //enables the computer to know where it started trying to sink the boat
          }

        }else if(hitStatus == BoatMiss){
          if(var->type == ComputerType){
            Computer* myComputer = static_cast<Computer*>(myPlayer);
            myComputer->goToInitialTrackBack(); //if there was a miss, go to the gridPoint where the first hit was
          }
          //if the user has already hit a boat in that location, don't change the marking on the graph to a miss
          if(myPlayer->opponentGrid.grid[gridPoint] == -1){
            myPlayer->opponentGrid.grid[gridPoint] = (int)hitStatus; //updates the opponentGrid status
          }
        }else{
          logError("Invalid hitstatus called.");
          throw syntaxError;
        }
      }

      //update stats
      switch (hitStatus) {
        case BoatMiss:
          myPlayer->unsuccessfulHits++;
          break;
        case BoatHit:
          myPlayer->setLocatedBoat(true);
          myPlayer->successfulHits++;
          break;
        case BoatSunk:
          myPlayer->setLocatedBoat(false);
          myPlayer->successfulHits++;
          myPlayer->successfulSinks++;
          break;
      }
    }
    static_cast<Player*>(var->value)->checkIfWon();
  }
};

//COMPUTER STUFF-----------------------------------------------------------------------

//try to sink boat
class TrySink : public Statement{
private:
  Direction direction;
  char* varName;
  char* varAttackedName;
  int afterHitSeekDistance;
  bool changeDirections;

public:
  TrySink(char* varName, char* varAttackedName, std::string myDirection, int afterHitSeekDistance){
    this->action = TrySinkAction;
    this->varName = varName;
    this->varAttackedName = varAttackedName;
    this->afterHitSeekDistance = afterHitSeekDistance;
    this->changeDirections = false;

    for(int i = 0; i < myDirection.size(); i++){
      myDirection[i] = tolower(myDirection[i]); //make sure all characters are lowercase
    }

    if(myDirection == "seek"){
      direction = SeekDirection;
    }else if(myDirection == "left"){
      direction = Left;
    }else if(myDirection == "right"){
      direction = Right;
    }else if(myDirection == "up"){
      direction = Up;
    }else if(myDirection == "down"){
      direction = Down;
    }else{
      logError("Invalid direction string.");
      throw syntaxError;
    }
  }

  ~TrySink(){
    delete varName;
    varName = NULL;
    delete varAttackedName;
    varAttackedName = NULL;
  }

  //deep copy constructor
  Statement *Clone() { return new TrySink(*this); }

  bool getChangeDirections(){return changeDirections;}
  Direction getDirection(){return direction;}

  void execute(){
    Variable* var = get_symbol(varName);
    Variable* varAttacked = get_symbol(varAttackedName);

    if(var == NULL){
      //printf("Variable %s not found\n", varName);
      std::string message = "symbol ";
      message += std::string(varName);
      message += " not found.";
      logError(message);
      throw syntaxError;
      return;
    }

    if(varAttacked == NULL){
      std::string message = "symbol ";
      message += std::string(varAttackedName);
      message += " not found.";
      logError(message);
      throw syntaxError;
      return;
    }

    if(var->type == ComputerType){
        Computer* myComputer = static_cast<Computer*>(var->value);
        std::string gridPoint = myComputer->tryToSinkBoat(direction, afterHitSeekDistance);
        Attack attack(strdup(varName), gridPoint, strdup(varAttackedName));
        attack.execute();
        if(myComputer->getTrackBack().size() > 1){changeDirections = false;} //if having success
        else{changeDirections = true;} //otherwise change directions
    }else{
      logError("Can only perform TrySink Action on Computer type.");
      throw syntaxError;
    }
  }
};

//Seek action

class Seek : public Statement{
private:
char* varName;
char* varAttackedName;
int seekDistance;

public:
  Seek(char* varName, int seekDistance, char* varAttackedName){
    this->action = SeekAction;
    this->varName = varName;
    this->varAttackedName = varAttackedName;
    this->seekDistance = seekDistance;
  }

  ~Seek(){
    delete varName;
    varName = NULL;
    delete varAttackedName;
    varAttackedName = NULL;
  }

  //deep copy constructor
  Statement *Clone() { return new Seek(*this); }

  void execute(){
    Variable* var = get_symbol(varName);
    Variable* varAttacked = get_symbol(varAttackedName);
    std::string gridPoint = "";

    if(var == NULL){
      //printf("Var is NULL\n");
      std::string message = "symbol ";
      message += std::string(varName);
      message += " not found.";
      logError(message);
      throw syntaxError;
      return;
    }
    if(varAttacked == NULL){
      //printf("varAttacked is NULL\n");
      std::string message = "symbol ";
      message += std::string(varAttackedName);
      message += " not found.";
      logError(message);
      throw syntaxError;
      return;
    }

    if(var->type == ComputerType){
      Computer* myComputer = static_cast<Computer*>(var->value);
      Player* myOpponent = static_cast<Player*>(var->value);

      gridPoint = myComputer->seek(seekDistance);
      Attack attack(strdup(varName), gridPoint, strdup(varAttackedName));
      attack.execute();
    }else if(var->type != ComputerType){
      //printf("Can only perform seek action on Computer.\n");
      logError("Can only perform seek action on Computer.");
      throw syntaxError;
      return;
    }
  }
};

//TRY STATEMENTS

class TryStatement : public Statement {
private:
  int tryStatementID;
  int tryStatementPriority;
  bool tried;
  int tryStatementExitLine;
  Statement* myStatement;

public:
  TryStatement(int tryStatementPriority, Statement* myStatement){
    this->action = TryStatementAction;
    this->myStatement = myStatement;
    this->tried = false;
  }

  ~TryStatement(){
    delete myStatement;
    myStatement = NULL;
  }

  //deep copy constructor
  Statement *Clone() { return new TryStatement(*this); }

  void setTried(){this->tried = true;}
  void setNotTried(){this->tried = false;}
  void setTryStatementID(int tryStatementID){this->tryStatementID = tryStatementID;}
  void setTryStatementExitLine(int tryStatementExitLine){this->tryStatementExitLine = tryStatementExitLine + 1;}
  int getTryStatementID(){return tryStatementID;}
  int getTryStatementPriority(){return tryStatementPriority;}
  int getTryStatementExitLine(){return tryStatementExitLine;}
  bool getTried(){return tried;}

  void execute(){
    switch (myStatement->getAction()) {
        case NoAction:
          printf("No action selected.\n");
          tried = true;
          break;
        case AddBoatAction:
          dynamic_cast<Boat*>(myStatement)->execute();
          tried = true;
          break;
        case RandomAddBoatAction:
          dynamic_cast<RandBoat*>(myStatement)->execute();
          tried = true;
          break;
        case AttackBoatAction:
          dynamic_cast<Attack*>(myStatement)->execute();
          tried = true;
          break;
        case ShowVarAction:
          dynamic_cast<ShowVar*>(myStatement)->execute();
          tried = true;
          break;
        case AssignAction:
          dynamic_cast<AssignToVar*>(myStatement)->execute();
          tried = true;
          break;
        case DeclareAction:
          dynamic_cast<VarDeclare*>(myStatement)->execute();
          tried = true;
          break;
        case SeekAction:
          dynamic_cast<Seek*>(myStatement)->execute();
          tried = true;
          break;
        case TrySinkAction:
        {
          TrySink* tSink = dynamic_cast<TrySink*>(myStatement);
          tSink->execute();
          tried = tSink->getChangeDirections();
        }
          break;
        default:
          logError("Could not execute statement try.");
          throw syntaxError;
          break;
        }
      }
};

//begin
class BeginTryStatement : public Statement{
private:
  int tryStatementID;
  int tryStatementExitLine;
  std::vector<TryStatement*> tryStatements;

public:
  BeginTryStatement(){
    this->action = BeginTryStatementAction;
  }

  ~BeginTryStatement(){}

  //deep copy constructor
  Statement *Clone() { return new BeginTryStatement(*this); }

  void addTryStatement(TryStatement* tryStatement){this->tryStatements.push_back(tryStatement);}
  void setTryStatementExitLine(int tryStatementExitLine){this->tryStatementExitLine = tryStatementExitLine + 1;}
  void setTryStatementID(int tryStatementID){this->tryStatementID = tryStatementID;}
  int getTryStatementID(){return tryStatementID;}
  int getTryStatementExitLine(){return tryStatementExitLine;}

  bool allAreTried(){
    bool allTried = true;
    for(int i = 0; i < tryStatements.size(); i++){
      //if not all statements are tried
      if(!tryStatements[i]->getTried()){
        allTried = false;
        break;
      }
    }
    return allTried;
  }

  void setTriesToFalse(){
    for(int i = 0; i < tryStatements.size(); i++){
      tryStatements[i]->setNotTried();
    }
  }

  void execute(){ }
};

//end
class EndTryStatement : public Statement{
private:
  int tryStatementID;

public:
  EndTryStatement(){
    this->action = EndTryStatementAction;
  }
  ~EndTryStatement(){}
  //deep copy constructor
  Statement *Clone() { return new EndTryStatement(*this); }

  void setTryStatementID(int tryStatementID){this->tryStatementID = tryStatementID;}
  int getTryStatementID(){return tryStatementID;}
  void execute(){ }
};



#endif
