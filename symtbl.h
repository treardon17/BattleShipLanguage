#ifndef __SYMTBL_H__
#define __SYMTBL_H__

#include <map>
#include <string>
#include <iterator>
#include "types.h"

std::map<std::string, Variable*> symbol_table;

Variable* add_symbol(std::string name, Type t);
Variable* get_symbol(std::string name);
void display_all();

//adds a variable to the symbol_table map of t type
Variable* add_symbol(std::string name, Type t){
	if(symbol_table.count(name)){
		//printf("Symbol already exists\n");
		logError("Symbol already exists");
		return symbol_table[name];
	}else{
		Variable* newVar = new Variable();
		newVar->type = t;
		newVar->name = strdup(name.c_str());
		printf("Adding variable %s of type %d\n", newVar->name, t);
		symbol_table.insert(std::pair<std::string, Variable*>(name, newVar));
		return symbol_table[name];
	}
}

Variable* get_symbol(std::string name){
  //for debugging purposes
	//display_all();
	return symbol_table[name];
}

//For debugging --> shows every available key in the symbol_table
void display_all(){
	printf("symbol_table size: %d\n", (int)symbol_table.size());
	std::map<std::string, Variable*>::iterator it;
	for(it = symbol_table.begin(); it != symbol_table.end(); it++){
		std::cout << "key: " << it->first << std::endl;
	}
}

//Deletes all the pointers from the symbol_table
void cleanupTable(){
  printf("Cleaning up symbol_table.\n");
  std::map<std::string, Variable*>::iterator it;
	for(it = symbol_table.begin(); it != symbol_table.end(); it++){
    delete it->second;
    it->second = NULL;
    symbol_table.erase(it);
	}
  printf("Done.\n");
}

#endif
