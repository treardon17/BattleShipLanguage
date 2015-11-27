#ifndef __TYPES_H__
#define __TYPES_H__

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include "gameboat.h"
#include "player.h"

enum Type {Int, Char, String, Bool, PlayerType, ComputerType};
std::string typenames[] = {"int", "char", "string", "bool", "player", "computer"};

enum Op {Add};
typedef enum Type Type;

class Expression{
public:
  Type type;
  void* value;

  virtual ~Expression(){
    switch (type) {
      case Int:
        delete (int*)value;
        value = NULL;
        break;
      case Char:
        delete (char*)value;
        value = NULL;
        break;
      case String:
        delete (std::string*)value;
        value = NULL;
        break;
      case Bool:
        delete (bool*)value;
        value = NULL;
        break;
      case PlayerType:
        delete (Player*)value;
        value = NULL;
        break;
      case ComputerType:
        delete (Computer*)value;
        value = NULL;
        break;
      default:
        //printf("Error freeing memory in Expression destructor\n");
        logError("Error freeing memory in Expression destructor.");
        break;
    }
  }
};

class Variable : public Expression{
public:
	char* name;

	virtual ~Variable(){
    delete name;
    name = NULL;
	}
};


#endif
