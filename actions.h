#ifndef __ACTIONS_H__
#define __ACTIONS_H__

#include <math.h>
#include "types.h"


///////////////////////////////////////////////////////////////////////////////////////
//HELPER FUNCTIONS/////////////////////////////////////////////////////////////////////
//These functions help get the arguments for the action functions//////////////////////
///////////////////////////////////////////////////////////////////////////////////////

//Takes in a string and converts it into an integer
int getIntegerValue(std::string intString){
	int endValue = 0;
	int numZeros = intString.size()-1;
	for (int i = 0; i<intString.size(); i++){
    if((int)intString[i] >= 48 && (int)intString[i] <= 57){
      endValue += ((pow(10, numZeros))*((int)intString[i] - '0'));
      numZeros--;
    }else{
      std::cout << "Invalid integer." << std::endl;
      return -1;
    }
	}
	return endValue;
}

char getCharValue(std::string charString){
  if(charString.size() > 0 && (int)tolower(charString[0]) >= 97 && (int)tolower(charString[0]) <= 122){
    return tolower(charString[0]);
  }else{
    std::cout << "Invalid char." << std::endl;
    return -1;
  }
}

std::string getUserInput(Player* myPlayer){
  std::cout << myPlayer->getPlayerStats() << std::endl;
  std::cout << myPlayer->playerName << ": " << std::endl;
  int gridSize = myPlayer->playerGrid.GridDimensions;
  int userRow;
  char userCol;
  std::string input;

  do{
    std::cout << "Column ( A - " << (char)(gridSize+64) << " ): ";
    std::cin >> input;
    userCol = getCharValue(input);
  } while(userCol == -1);

  do{
    std::cout << "Row ( 1 - " << gridSize << " ): ";
    std::cin >> input;
    userRow = getIntegerValue(input);
  } while(userRow == -1 || userRow > gridSize);

  std::ostringstream colAndRow;
  colAndRow << userCol << userRow;
  return colAndRow.str();
}

//Takes in a vector of strings, converts it into it's correct data type
//Returns a vector of expressions
//The data is stored in a void pointer in the Expression*
//The type of the variable is also stored in the Expression
std::vector<Expression*> typifyArgs(std::vector<std::string> argumentList){
  std::vector<Expression*> typedArgs;
  for(int i = 0; i<argumentList.size(); i++){
    //look if there are double quotes at index 0 --> if there are, then it's a string
    if(argumentList[i][0] == '\"'){
      Expression* var = new Expression();
      var->type = String;
      std::string* myString = new std::string(argumentList[i].substr(1, argumentList[i].size()-2));
      var->value = (void*)(myString);
      typedArgs.push_back(var);
      //look if there are single quotes at index 0 --> if there are, then it's a char
    }else if (argumentList[i][0] == '\''){
      Expression* var = new Expression();
      var->type = Char;
      int* myChar = new int(argumentList[i][1]); //get the second character in the string and cast it as an int for the ascii value
      var->value = (void*)((char*)myChar); //cast the character as a char* and then a void*
      typedArgs.push_back(var);
      //look for characters with the ascii values that correspond to numbers
    }else if(argumentList[i][0] >= 48 && argumentList[i][0] <= 57){
      Expression* var = new Expression();
      var->type = Int;
      var->value = (void*) new int(getIntegerValue(argumentList[i]));
      typedArgs.push_back(var);
    }
  }
  return typedArgs;
}

//takes in a string containing commas
//splits the string on the commas
//returns a vector of strings containing only the arguments (not the commas)
std::vector<std::string> getArguments(std::string arguments){
  std::vector<std::string> argumentList;
  std::stringstream ss(arguments);
  while(ss.good()){
    std::string substr;
    if(ss.peek() == ' '){
      ss.ignore();
    }
    getline( ss, substr, ',' );
    argumentList.push_back(substr);
  }
  return argumentList;
}

//allows easy conversion from void* to string
std::string exprToString(Expression* expr){
  switch (expr->type) {
    case String:
      return *((std::string*)(expr->value));
      break;
    default:
      printf("Invalid type.  Must be string.\n");
      return NULL;
      break;
  }
}

//allows easy conversion from void* to char
char exprToChar(Expression* expr){
  switch (expr->type) {
    case Char:
      return *((char*)(expr->value));
      break;
    default:
      printf("Invalid type.  Must be char.\n");
      return 0;
      break;
  }
}

//allows easy conversion from void* to int
int exprToInt(Expression* expr){
  switch (expr->type) {
    case Int:
      return *((int*)(expr->value));
      break;
    default:
      printf("Invalid type.  Must be int.\n");
      return (int)NULL;
      break;
  }
}

bool exprToBool(Expression* expr){
	switch (expr->type) {
		case Bool:
			return *((bool*)(expr->value));
			break;
		default:
			printf("Invalid type.  Must be bool.\n");
			return (bool)NULL;
			break;
	}
}

///////////////////////////////////////////////////////////////////////////////////////
//END HELPER FUNCTIONS/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////


#endif
