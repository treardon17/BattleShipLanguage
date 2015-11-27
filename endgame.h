#ifndef __ENDGAME_H__
#define __ENDGAME_H__

#include <iostream>
#include <stdexcept>

class EndGame: public std::exception
{
  virtual const char* what() const throw()
  {
    return "\n\nGame Ended\n\n";
  }
} endGame;

#endif
