#ifndef __ERRORLOGGER_H__
#define __ERRORLOGGER_H__

#include <iostream>
#include <stdlib.h>
#include "errorLogger.h"

std::ostringstream errorLog;
int numErrorsGlobal = 0;
int lineNumberGlobal;

void logError(std::string message){
  errorLog << "line " << lineNumberGlobal << ": " << message << std::endl;
  ++numErrorsGlobal;
}

void displayUserErrors(){
  std::cout << "Number of errors: " << numErrorsGlobal << std::endl;
  std::cout << errorLog.str() << std::endl;
}

#endif
