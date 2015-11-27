#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <stdlib.h>
#include <time.h>
#include "gameboat.h"
#include "errorLogger.h"

//these are formatting colors for the show functions
std::string sunkColor = "\e[1;91m";
std::string hitColor = "\e[1;32m";
std::string missColor = "\e[97m";
std::string boatColorSink = "\e[1;31m";
std::string colAndRowColor = "\e[2;32m";
std::string outlineColor = "\e[1;32m";
std::string boatColorFloat = "\e[1;33m";
std::string theOceanColor = "\e[2;90m";
std::string endFormatColor = "\e[0m";
//end formatting colors

enum Direction {SeekDirection, Left, Right, Up, Down};
typedef enum Direction Direction;

class Player {
protected:
  bool personPlayer; //specifies whether or not the player is a person and requires input
  bool locatedBoat;

//PUBLIC MEMBER FUNCTIONS-------------------------------------------------------------
public:
  std::string playerName;             //holds the player's identifying name
	std::vector<GameBoat> playerBoats;  //holds all of the player's boats
  Grid opponentGrid;                  //shows where the player has attempted to hit
  Grid playerGrid;                    //shows where the player has placed their boats

  //Opponent Stats
  int successfulHits;       //the number of successful attacks
  int successfulSinks;      //the number of successful boat sinks
  int unsuccessfulHits;     //the number of misses
  int numOpponentBoats;     //number of boats the opponent has
  std::string opponentName; //the name of the player's adversary

  //Personal stats
  int personalHits; //the number of hits the current player has received
  int personalSinks; //the number of sinks player has taken

  Player(std::string playerName){
    this->playerName = playerName;
    this->opponentName = "Opponent";
    personPlayer = true;
    personalHits = 0;
    personalSinks = 0;

    successfulHits = 0;
    successfulSinks = 0;
    unsuccessfulHits = 0;
    numOpponentBoats = 0;

    locatedBoat = false;
  }

  //GET FUNCTIONS
  bool isPerson(){ return personPlayer; }
  bool didLocateBoat(){ return locatedBoat; }

  //SET FUNCTIONS
  void setLocatedBoat(bool locatedBoat) { this->locatedBoat = locatedBoat; }

  //Checks to see if there was a winner --> whoever has zero boats loses
  bool checkIfWon(){
    if((numOpponentBoats - successfulSinks) <= 0){
      std::cout << playerName << " won the game!" << std::endl;
      throw endGame;
      return true; //will never reach this line
    }else{
      return false;
    }
    return false;
  }

  //Adds the specified amount of boats to random places on the grid
  void randomAddBoats(int numBoats){
    //make sure the user doesn't put any more than 99 boats in the grid
    if(numBoats > 99){
      //printf("Cannot exceed 99 boats due to formatting constraints\n");
      logError("Cannot exceed 99 boats due to formatting constraints. Number of boats set to 99.");
      numBoats = 99;
    }
    int randBoatRow;
    int randBoatCol;
    int randBoatType;
    int randVertical;

    //loop until the player has the correct number of boats
    while(playerBoats.size() < numBoats){
      randBoatRow = rand() % playerGrid.GridDimensions + 1; //get random number between 1 and the grid size
      randBoatCol = rand() % playerGrid.GridDimensions + 1; //get random number between 1 and the grid size
      randBoatType = rand() % numBoatTypes; //get random number between 0 and the number of boat types
      randVertical = rand() % 2; //random number between 0 and 1
      //try to add the boat
      addBoat(boatnames[randBoatType], (char)(randBoatCol+97), randBoatRow, randVertical, false);
    }
  }

	//Adds a boat to the person's vector of boats and then places it on their grid
	bool addBoat(std::string boatName, char scolumn, int srow, bool vertical, bool notifications){
    //make sure user doesn't add any more than 99 boats to grid
    if(playerBoats.size() > 99){
      //printf("Cannot exceed 99 boats due to formatting constraints\n");
      logError("Cannot exceed 99 boats due to formatting constraints. Number of boats set to 99.");
      return false;
    }
		//make new boat here and then push it back to the vector
		//need boat name
		GameBoat newBoat(boatName);
    //adds a new boat to the player's vector if the boat type was valid
		if(newBoat.assignedValue){
			playerBoats.push_back(newBoat);
      if(notifications) { printf("Player %s has %d boats\n", playerName.c_str(), (int)playerBoats.size());}

      if(!placeBoat(playerBoats.size()-1, scolumn, srow, vertical, notifications)){
				if(notifications) { printf("Boat could not be placed.\n");}
        return false;
			}else{ return true; }
		}else{
			if(notifications) { printf("Could not add boat to player.\n"); }
      return false;
		}
		return false;
	}

//places boat at column and row specified and orients it horizontally or vertically
//specified by the boolean vertical
//starting position refers to the top of the ship (if vertical)
//or the left of the ship (if horizontal)
//Boolean return value specifies whether or not the function was able to complete the task
bool placeBoat(int boatNum, char scolumn, int srow, bool vertical, bool notifications){
  //Error checking-----------------------------------------------------------------------
  if(boatNum > playerBoats.size() - 1){
    if(notifications) { std::cout << "Invalid boat number.  Out of bounds." << std::endl;}
    return false;
  }else if(!playerBoats[boatNum].assignedValue){
    if(notifications) { std::cout << "Error loading boat... Removing boat." << std::endl;}
    if(playerBoats.size() > 0){
      playerBoats.pop_back();
    }
    return false;
  }
  //Error checking-----------------------------------------------------------------------

  //Variables to help find the right placement
  bool validPlacement = false;              //for determining if boats are overlapping
  bool goodCoordinates = false;
  bool boatFitsOnGrid = false;
  std::vector<std::string> gridpoints;      //stores the valid grid keys
  scolumn = tolower(scolumn);               //make all letters the same case

  //checks to see if the input fits within the range specified on the grid
  if((int)scolumn >= 'a' && (int)scolumn <= playerGrid.GridDimensions+96 &&
   srow >= 1 && srow <= playerGrid.GridDimensions){
    goodCoordinates = true;
  }else{
    if(notifications) {std::cout << "Valid columns are A-" << (char)(playerGrid.GridDimensions+64) << " and valid rows are 1-" << playerGrid.GridDimensions << std::endl; }
    if(playerBoats.size() > 0){ playerBoats.pop_back(); }
    //bad coordinates
    return false;
  }

  //checks to see if the boat will fit on the grid given the coordinates and the boat length
  if((vertical && playerBoats[boatNum].boatLength <= (playerGrid.GridDimensions-srow))
    || (!vertical && playerBoats[boatNum].boatLength <= (playerGrid.GridDimensions - ((int)scolumn - 96)))){
      boatFitsOnGrid = true;
    }

  if(goodCoordinates && boatFitsOnGrid){
    //looks for boats already placed on the grid
    for(int i = 0; i<playerBoats[boatNum].boatLength; i++){
      //creates the string that will be stored in the player's grids as the key
      //as well as the locations the boat is associated with
      std::ostringstream colAndRow;
      colAndRow << scolumn << srow;
      if(vertical){ srow++; }else{ scolumn++; } //if the boat is vertical, increment the row, otherwise increment the column
      gridpoints.push_back(colAndRow.str()); //adds the location to the gridpoints vector

      //checks to see if a boat has been placed on specified grid point yet
      //if the grid point is equal to -1, no boat has been placed there yet
      //if the grid point is not -1, a boat is there,
      //so a new boat cannot be placed on that point
      if(playerGrid.grid[colAndRow.str()] == -1){ validPlacement = true; }
      else{ validPlacement = false; break; }
    }//end for loop
  }//end goodCoordinates && boatFitsOnGrid

  //if the coordinates were bad or the boat didnt fit on the grid, give an error message
  else{
    //user can specify whether they want an error message
    if(notifications){
      std::cout << playerName << "'s boat #" << boatNum << " of length " << playerBoats[boatNum].boatLength << " could not be placed." << std::endl;
      std::cout << "Last coordinates attempted: ";
      for(int i = 0; i < gridpoints.size(); i++){
        std::cout << gridpoints[i] << " ";
      }
      std::cout << std::endl;
      std::cout << "Out of bounds. Could not place boat." << std::endl;
    }
    //remove the boat from the vector of playerBoats because it couldn't be placed
    if(playerBoats.size() > 0){ playerBoats.pop_back(); }
    //the boat could not be placed
    return false;
  }//end else

  //if the boat had a valid placement
  if(validPlacement){
    for(int i = 0; i<gridpoints.size(); i++){
      //Gives boat a location
      //False means that the boat has not yet been hit
      playerBoats[boatNum].locations.insert(std::pair<std::string, bool>(gridpoints[i], false));
      //References the boat number on the master grid
      playerGrid.grid[gridpoints[i]] = boatNum;
    }
    //specifies that boat has been placed on the player's grid
    playerBoats[boatNum].hasPlaceOnGrid = true;
    //boat placement succeeded
    return true;
  }

  //if the boat did not have valid placement
  else{
    if(notifications){
      std::cout << "Invalid boat placement: cannot have two boats intersect." << std::endl;
      std::cout << playerName << "'s current boat of " << boatnames[(int)playerBoats[boatNum].boatType] << " type with proposed coordinates of: ";
      for(int i = 0; i<gridpoints.size(); i++){ std::cout << gridpoints[i] << " "; }
      std::cout << "intersect with boat of " << boatnames[(int)playerBoats[playerGrid.grid[gridpoints[gridpoints.size()-1]]].boatType];
      std::cout << " type which has coordinates: ";
      std::map<std::string, bool>::iterator it;
      for(it = playerBoats[playerGrid.grid[gridpoints[gridpoints.size()-1]]].locations.begin(); it != playerBoats[playerGrid.grid[gridpoints[gridpoints.size()-1]]].locations.end(); it++){
        std::cout << it->first << " ";
      }
    }
    if(playerBoats.size() > 0){ playerBoats.pop_back(); }
    //boat placement failed
    return false;
  }

  //catch all return false if function did not succeeded
  return false;
}

//Allows a player to try attacking a boat at the specified gridPoint
//if there is a boat there and the boat has more life left, the function returns a hit
//if there is a boat there and the boat does not have more life left, the function returns a sink
//if there is no boat there, the function returns a miss
BoatStatus attackBoat(std::string gridPoint){

    //if the given key is invalid, don't continue
    if(gridPoint == "" || !playerGrid.grid.count(gridPoint)){
      return BoatMiss;
    }

    int boatNum = playerGrid.grid[gridPoint];
    if(boatNum != -1){
      //if the boat hasn't been hit yet
      if(!playerBoats[boatNum].locations[gridPoint]){
        std::cout << playerName << "'s Boat #" << boatNum << " of type " << boatnames[(int)playerBoats[boatNum].boatType] << " hit." << std::endl;
        playerBoats[boatNum].locations[gridPoint] = true;
        playerBoats[boatNum].lifePoints--;
        if(playerBoats[boatNum].lifePoints <= 0){
          std::cout << playerName << "'s boat #" << boatNum << " sunk." << std::endl;
          playerBoats[boatNum].sunk = true;
          personalHits++;
          personalSinks++;
          return BoatSunk;
        }
        std::cout << "Boat #" << boatNum << " has " << playerBoats[boatNum].lifePoints << " life points left." << std::endl;
        personalHits++;
        return BoatHit;
      }else{
        return BoatMiss; // boat already in that location
      }
    }
    return BoatMiss; // no boat in that location
  }

//SHOW FUNCTIONS
//Shows the coordinates the boat was added to
  void showBoatLocation(int boatNum){
    std::cout << "Boat #" << boatNum << " has " << playerBoats[boatNum].locations.size() << " grid points." << std::endl;
    std::cout << "Showing grid points of boat #" << boatNum << ":" << std::endl;
    std::map<std::string, bool>::iterator it;
    for(it = playerBoats[boatNum].locations.begin(); it != playerBoats[boatNum].locations.end(); it++){
      std::cout << it->first << ": " << it->second << std::endl;
    }
  }

//Shows the grid containing the player's boats
  std::string getPlayerGrid(){
    std::ostringstream playerGridString;
    int maxRowNumberLength = (int)floor(log10((float)playerGrid.GridDimensions)) + 1; //the max row number "string" length
    int currentRowNumberLength = 0; //the current row number "string" length (to be calculated further down)
    int maxGridCharacterWidth = (int)floor(log10((float)playerBoats.size())) + 1;
    int currentGridCharacterWidth = 0;

    std::string properSpacing = " ";
    for(int i = 0; i<maxGridCharacterWidth - 1; i++){properSpacing += " ";}
    //Makes top column header
    for(int col = 0; col < playerGrid.GridDimensions; col++){
      if(col == 0){playerGridString << "    ";}
      playerGridString << colAndRowColor << (char)(col+65) << endFormatColor << properSpacing; //gets the ascii value for the capital letters of the alphabet
    }
    playerGridString << std::endl;
    //Begin rows
    for(int row = 0; row < playerGrid.GridDimensions; row++){
      //Makes rows
      currentRowNumberLength = (int)floor(log10((float)row + 1)) + 1;
        playerGridString << colAndRowColor << "|" << row + 1;
        //makes all row numbers have the same width
        for(int i = 0; i<maxRowNumberLength - currentRowNumberLength; i++){playerGridString << " ";}
        playerGridString << "|" << endFormatColor;
      //Prints datapoints
      for(int col = 0; col < playerGrid.GridDimensions; col++){
        std::ostringstream colAndRow;
        colAndRow << (char)(col+97) << row + 1;
        if(playerGrid.grid[colAndRow.str()] != -1){ //if the grid point has a boat assigned to it
          int currentBoatNum = playerGrid.grid[colAndRow.str()];
          int currentBoatSize = playerBoats[currentBoatNum].boatLength;
          std::string properSpacing2 = " ";
          currentGridCharacterWidth = (int)floor(log10((float)currentBoatNum + 1)) + 1;
          for(int i = 0; i<maxGridCharacterWidth - currentGridCharacterWidth; i++){properSpacing2 += " ";}

          for(int i = 0; i < currentBoatSize; i++){
            if(playerBoats[currentBoatNum].locations[colAndRow.str()] == false){
              //make the parts of the boats that haven't been hit yellow
              playerGridString << boatColorFloat << playerGrid.grid[colAndRow.str()] + 1 << endFormatColor << properSpacing2;
              break;
            }else{
              //make the parts of the boat that have been hit red
              playerGridString << boatColorSink << playerGrid.grid[colAndRow.str()] + 1 << endFormatColor << properSpacing2;
              break;
            }
          }
        }else{
          std::string properSpacing3 = " ";
          for(int i = 0; i<maxGridCharacterWidth - 1; i++){properSpacing3 += " ";}
          playerGridString << theOceanColor << "\u25D9" << endFormatColor << properSpacing3; //prints a ◙
        }
      }
      playerGridString << std::endl;
    }
    return playerGridString.str();
  }

//shows where you've attempted or succeeded in hitting your opponent's ships
  std::string getOpponentGrid(){
    std::ostringstream opponentGridString;
    int maxRowNumberLength = (int)floor(log10((float)opponentGrid.GridDimensions)) + 1; //the max row number "string" length
    int currentRowNumberLength = 0; //the current row number "string" length (to be calculated further down)

    //Makes top column header
    for(int col = 0; col < opponentGrid.GridDimensions; col++){
      if(col == 0){opponentGridString << "    ";}
      opponentGridString << colAndRowColor << (char)(col+65) << endFormatColor << " "; //gets the ascii value for the capital letters of the alphabet
    }
    opponentGridString << std::endl;
    //Begin rows
    for(int row = 0; row < opponentGrid.GridDimensions; row++){
      //Makes rows
      currentRowNumberLength = (int)floor(log10((float)row + 1)) + 1;
        opponentGridString << colAndRowColor << "|" << row + 1;
        //makes all row numbers have the same width
        for(int i = 0; i<maxRowNumberLength - currentRowNumberLength; i++){opponentGridString << " ";}
        opponentGridString << "|" << endFormatColor;
      //Prints datapoints
      for(int col = 0; col < opponentGrid.GridDimensions; col++){
        std::ostringstream colAndRow;
        colAndRow << (char)(col+97) << row + 1;
        if(opponentGrid.grid[colAndRow.str()] < 0){
          opponentGridString << theOceanColor << "\u25D9" << endFormatColor << " "; //if no try, put a ◙
        }else if(opponentGrid.grid[colAndRow.str()] == (int)BoatMiss){
          opponentGridString << missColor << "\u25CA" << endFormatColor << " "; //if missed put a ◊
        }else if(opponentGrid.grid[colAndRow.str()] == (int)BoatHit){
          opponentGridString << hitColor << "\u25C8" << endFormatColor << " "; //if hit
        }else if(opponentGrid.grid[colAndRow.str()] == (int)BoatSunk){
          opponentGridString << sunkColor << "\u25C9" << endFormatColor << " "; //if boat sunk, put a ◉
        }
      }
      opponentGridString << std::endl;
    }
    return opponentGridString.str();
  }


  std::string getPlayerStats(){
    std::ostringstream playerStats;
    int gridOutline = playerGrid.GridDimensions*2.5; //specifies the number of dashes at the top and bottom of the grid
    //display formatted name
    for(int i = 0; i<gridOutline; i++){playerStats << outlineColor << "-" << endFormatColor;}
    playerStats << std::endl;
    playerStats << "Player name: " << playerName << std::endl;
    playerStats << std::endl;
    playerStats << getOpponentGrid();
    playerStats << getPlayerGrid();
    for(int i = 0; i<gridOutline; i++){playerStats << theOceanColor << "_" << endFormatColor;}
    playerStats << std::endl;
    playerStats << playerName << "'s Stats:" << std::endl;
    playerStats << hitColor << "Successful Hits: " << successfulHits << endFormatColor << std::endl;
    playerStats << sunkColor << "Successful Sinks: " << successfulSinks << endFormatColor << std::endl;
    playerStats << missColor << "Misses: " << unsuccessfulHits << endFormatColor << std::endl;
    playerStats << opponentName << " has " << numOpponentBoats << " boats" << std::endl;
    playerStats << opponentName << " has " << numOpponentBoats - successfulSinks << " boats left" << std::endl;
    for(int i = 0; i<gridOutline; i++){playerStats << theOceanColor << "_" << endFormatColor;}
    playerStats << std::endl;
    playerStats << opponentName << " hit you " << boatColorSink << personalHits << endFormatColor << " time(s)" << std::endl;
    playerStats << opponentName << " sank " << boatColorSink << personalSinks << endFormatColor << " of your boats" << std::endl;
    playerStats << "You have " << boatColorFloat << playerBoats.size() << endFormatColor << " boat(s)" << std::endl;
    playerStats << "You have " << hitColor << playerBoats.size() - personalSinks << endFormatColor << " boat(s) left" << std::endl;
    for(int i = 0; i<gridOutline; i++){playerStats << outlineColor << "_" << endFormatColor;}
    playerStats << std::endl;
    return playerStats.str();
  }
};//End Player Class


//COMPUTER CLASS-----------------------------------------------------------------------------------------------------------------


class Computer : public Player{
private:
  std::string mostRecentTry;        //records the most recent attempt
  std::stack<Coordinate> trackBack; //when the computer hits a boat initially, the gridPoint is recorded
  Direction currentDirection;       //records the current seek direction
  int randBoatRow;                  //row the computer generates
  char randBoatCol;                 //column the computer generates
  int seekDistance;                 //records the current seek distance (space between attacks for computer)

public:
	Computer(std::string playerName) : Player(playerName){
    personPlayer = false;
    mostRecentTry = "";
    //trackBack = "none"; //notifies whether or not the trackBack gridPoint is set
    randBoatRow = rand() % playerGrid.GridDimensions + 1;                 //get random number between 1 and the grid size
    randBoatCol = (char)((rand() % playerGrid.GridDimensions + 1) + 96);  //get random char between a and the grid size
    currentDirection = SeekDirection;
  }

  //void setTrackBack(std::string trackBack){ this->trackBack = trackBack; }
  //std::string getTrackBack(){ return trackBack; }

  void emptyTrackBack(){
    while(trackBack.size() > 0){trackBack.pop();
    }
  } //empty trackBack
  void setTrackBack(Coordinate coord){
    emptyTrackBack();
    trackBack.push(coord);
  } //set new trackBack
  void addTrackBack(Coordinate coord){
    trackBack.push(coord);
  }
  void goToInitialTrackBack(){
    while(trackBack.size() > 1){trackBack.pop();
    }
  } //empty trackBack except for first value (which is where the first hit was) }

  std::stack<Coordinate> getTrackBack(){return trackBack;}

  //returns the gridPoint for the next valid place in the seek pattern
  std::string seek(int seekDistance){

    //make sure the seek distance isn't too big or too small
    if(seekDistance > playerGrid.GridDimensions / 2){
      seekDistance = playerGrid.GridDimensions / 2;
      printf("Too large of seek distance. Setting seek distance to %d.\n", seekDistance);
    }else if(seekDistance <= 0){ seekDistance = 1; }
    //make the column and row a string
    std::ostringstream colAndRow;
    colAndRow << randBoatCol << randBoatRow;
    //look for places the computer hasn't tried yet
    while(opponentGrid.grid[colAndRow.str()] != -1){
      colAndRow.str("");
      colAndRow.clear();
      //if adding 1 exceeds the bounds of the grid, set the column to 'a'
      if(((int)randBoatCol - 96) + 1 > playerGrid.GridDimensions){ randBoatCol = 'a'; randBoatRow++; }
      //otherwise, set the seeker to the next point
      else{ randBoatCol++; }
      //set the row to 1 if the row exceeds the bounds of the grid
      if(randBoatRow > playerGrid.GridDimensions){ randBoatRow = 1; }
      colAndRow << randBoatCol << randBoatRow;
    }
    //insert the gridPoint and its success status into the previousTries map
    mostRecentTry = colAndRow.str();
    //if the seek distance exceeds the bounds of the grid, set the column to 'a'
    if(((int)randBoatCol - 96) + seekDistance > playerGrid.GridDimensions){ randBoatCol = 'a'; randBoatRow += seekDistance; }
    //otherwise, set the seeker to the next point
    else{ randBoatCol = randBoatCol + seekDistance; }
    //set the row to 1 if the row exceeds the bounds of the grid
    if(randBoatRow > playerGrid.GridDimensions){ randBoatRow = 1; }

    return mostRecentTry;
  }

  //determines/guesses which direction to seek if a hit was made
  //  direction is the the direction the user specifies: up down left right
  //afterHitSeekDistance is the user specified interval the computer will look
  //  in the specified direction after a hit was made
  std::string tryToSinkBoat(Direction newDirection, int afterHitSeekDistance){
    //if the most recent try was a success...
    if(trackBack.size() > 0){
      currentDirection = newDirection; //set the direction of the attack
      //make the column and row a string
      std::ostringstream colAndRow;

      //depending on the direction specified
      switch (currentDirection) {
        case SeekDirection:
          return seek(1);
          break;
        case Left:
          if(canMoveLeft(afterHitSeekDistance) && shouldMoveLeft(afterHitSeekDistance)){
            mostRecentTry = moveLeft(afterHitSeekDistance);
            return mostRecentTry;
          }
          break;
        case Right:
          if(canMoveRight(afterHitSeekDistance) && shouldMoveRight(afterHitSeekDistance)){
            mostRecentTry = moveRight(afterHitSeekDistance);
          }
          break;
        case Up:
          std::cout << "randBoatCol: " << randBoatCol << std::endl; ///------------------------
          std::cout << "randBoatRow: " << randBoatRow << std::endl; ///------------------------
          if(canMoveUp(afterHitSeekDistance) && shouldMoveUp(afterHitSeekDistance)){
            mostRecentTry = moveUp(afterHitSeekDistance);
          }
          std::cout << "randBoatCol: " << randBoatCol << std::endl; ///------------------------
          std::cout << "randBoatRow: " << randBoatRow << std::endl; ///------------------------
          break;
        case Down:
          if(canMoveDown(afterHitSeekDistance) && shouldMoveDown(afterHitSeekDistance)){
            mostRecentTry = moveDown(afterHitSeekDistance);
          }
          break;
        default:
          //printf("Could not perform seek and destroy action. Bad direction.\n");
          logError("Could not perform seek and destroy action. Bad direction.");
          return seek(1);
          break;
      }
      return mostRecentTry;
    }

    printf("\n\n\nSeeking...\n\n\n"); ///------------------------------------------
    //if there wasn't actually a hit, return a seek
    return seek(1);
  }

//UP-------------------------------------------
  bool canMoveUp(int afterHitSeekDistance){
    if((trackBack.top().getRow() - afterHitSeekDistance) < 1){
      //printf("Vertical out of bounds. Row number was too small.\n");
      logError("Vertical out of bounds. Row number was too small.");
      return false;
    }
    return true;
  }

  bool shouldMoveUp(int afterHitSeekDistance){
    std::ostringstream colAndRow;
    colAndRow << trackBack.top().getCol() << (trackBack.top().getRow() - afterHitSeekDistance);
    if(opponentGrid.grid[colAndRow.str()] == -1){ return true; }
    else { return false;}
  }

  std::string moveUp(int afterHitSeekDistance){
    //make the column and row a string
    std::ostringstream colAndRow;
    colAndRow << trackBack.top().getCol() << (trackBack.top().getRow() - afterHitSeekDistance);
    trackBack.push(colAndRow.str());
    return colAndRow.str();
  }

//DOWN-------------------------------------------
  bool canMoveDown(int afterHitSeekDistance){
    if((trackBack.top().getRow() + afterHitSeekDistance) > playerGrid.GridDimensions){
      //printf("Vertical out of bounds. Row number was too large.\n");
      logError("Vertical out of bounds. Row number was too small.");
      return false;
    }
    return true;
  }

  bool shouldMoveDown(int afterHitSeekDistance){
    std::ostringstream colAndRow;
    colAndRow << trackBack.top().getCol() << (trackBack.top().getRow() + afterHitSeekDistance);
    if(opponentGrid.grid[colAndRow.str()] == -1){ return true; }
    else { return false;}
  }

  std::string moveDown(int afterHitSeekDistance){
    //make the column and row a string
    std::ostringstream colAndRow;
    colAndRow << trackBack.top().getCol() << (trackBack.top().getRow() + afterHitSeekDistance);
    trackBack.push(colAndRow.str());
    return colAndRow.str();
  }

//LEFT-------------------------------------------
  bool canMoveLeft(int afterHitSeekDistance){
    if((trackBack.top().getCol() - afterHitSeekDistance) < 'a'){
      //printf("Horizontal out of bounds. Column too far left.\n");
      logError("Horizontal out of bounds. Row number was too small.");
      return false;
    }
    return true;
  }

  bool shouldMoveLeft(int afterHitSeekDistance){
    std::ostringstream colAndRow;
    colAndRow << (trackBack.top().getCol() - afterHitSeekDistance) << randBoatRow;
    if(opponentGrid.grid[colAndRow.str()] == -1){ return true; }
    else { return false;}
  }

  std::string moveLeft(int afterHitSeekDistance){
    //make the column and row a string
    std::ostringstream colAndRow;
    colAndRow << (trackBack.top().getCol() - afterHitSeekDistance) << randBoatRow;
    trackBack.push(colAndRow.str());
    return colAndRow.str();
  }

//RIGHT-------------------------------------------
  bool canMoveRight(int afterHitSeekDistance){
    if((trackBack.top().getCol() + afterHitSeekDistance) > playerGrid.GridDimensions + 97){
      //printf("Horizontal out of bounds. Column too far right\n");
      logError("Horizontal out of bounds. Row number was too small.");
      return false;
    }
    return true;
  }

  bool shouldMoveRight(int afterHitSeekDistance){
    std::ostringstream colAndRow;
    colAndRow << (trackBack.top().getCol() + afterHitSeekDistance) << randBoatRow;
    if(opponentGrid.grid[colAndRow.str()] == -1){ return true; }
    else { return false;}
  }

  std::string moveRight(int afterHitSeekDistance){
    //make the column and row a string
    std::ostringstream colAndRow;
    colAndRow << (trackBack.top().getCol() + afterHitSeekDistance) << randBoatRow;
    trackBack.push(colAndRow.str());
    return colAndRow.str();
  }

};

#endif
