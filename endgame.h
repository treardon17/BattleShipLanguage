#ifndef __ENDGAME_H__
#define __ENDGAME_H__

#include <iostream>
#include <stdexcept>

//to end the game if a player does not have any boats left
class EndGame: public std::exception
{
  virtual const char* what() const throw()
  {
    return "\n\nGame Ended\n\n";
  }
} endGame;


//for syntax errors
class SyntaxError: public std::exception
{
  virtual const char* what() const throw()
  {
    return "\n\nError in syntax.\n\n";
  }
} syntaxError;

#endif
