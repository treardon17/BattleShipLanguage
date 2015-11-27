#ifndef __BOAT_H__
#define __BOAT_H__

#include <iostream>
#include <string>
#include <map>

enum BoatType {AircraftCarrier, Battleship, Submarine, Destroyer, PatrolBoat};
std::string boatnames[] = {"aircraftcarrier", "battleship", "submarine", "destroyer", "patrolboat"};
int numBoatTypes = sizeof(boatnames)/sizeof(boatnames[0]);
typedef enum BoatType BoatType;

enum BoatStatus {BoatMiss, BoatHit, BoatSunk};
typedef enum BoatStatus BoatStatus;


class Coordinate{
private:
  char col;
  int row;
public:
  Coordinate(std::string gridPoint){
      if(gridPoint.size() >= 2){
        //get the char value
        if((int)tolower(gridPoint[0]) >= 97 && (int)tolower(gridPoint[0]) <= 122){
          this->col = tolower(gridPoint[0]);
        }
        //get the integer value
        std::string intString = gridPoint.substr(1, gridPoint.size() - 1);
        int endValue = 0;
      	int numZeros = intString.size()-1;
      	for (int i = 0; i<intString.size(); i++){
          if((int)intString[i] >= 48 && (int)intString[i] <= 57){
            endValue += ((pow(10, numZeros))*((int)intString[i] - '0'));
            numZeros--;
          }
        this->row = endValue;
      }
    }
  }
  
  char getCol(){ return col; }
  char getRow(){ return row; }
};

//The grid players use to put their boats as well as guess where other boats are
//The int value in the map is associated with the index of the boats vector in the player class
class Grid{
public:
  int GridDimensions;
  std::map<std::string,int> grid;

  //creates a map of columns and rows
  //the integer value of the map represents the vector index of the boat
  Grid(){
    GridDimensions = 15;

    if(GridDimensions > 26){
      GridDimensions = 26;
    }

    std::vector<int> rows;
    std::vector<char> columns;
    for(int i = 0; i < GridDimensions; i++){
      if(GridDimensions <= 26)
        rows.push_back(i+1);
      else break;
    }
    for(int i = 0; i < GridDimensions; i++){
      if(GridDimensions <= 26)
        columns.push_back((char)(i+97));
      else break;
    }

    for(int i = 0; i<columns.size(); i++){
      for(int j = 0; j<rows.size(); j++){
        std::ostringstream colAndRow;
        colAndRow << columns[i] << rows[j];
        grid.insert(std::pair<std::string, int>(colAndRow.str(),-1));
      }
    }
  }
};

class GameBoat {
public:
	BoatType boatType;
	int boatLength;
  int lifePoints;
  bool hasPlaceOnGrid;
  bool assignedValue;
  bool sunk;
	std::map<std::string,bool> locations;

	//creates a boat from the string inputted
	//takes in starting column and row as well as ending column and row
	GameBoat(std::string boatName){
		boatLength = 0;
    lifePoints = 0;
    hasPlaceOnGrid = false;
    assignedValue = false;
    sunk = false;
    bool foundType = false;

    //looks for types of boats in the boatnames array
		for(int i = 0; i<numBoatTypes; i++){
			if(boatnames[i] == boatName){
				boatType = (BoatType)i;
				foundType = true;
				break;
			}
		}
    //if boat type is not found, output the available boat types
		if(!foundType){
      std::cout << "////////////////////////////////////////" << std::endl;
			std::cout << "Invalid boat type specified: "<< boatName << ". Valid types are:" << std::endl;
			for(int i = 0; i<numBoatTypes; i++){
				std::cout << boatnames[i] << std::endl;
			}
      std::cout << "////////////////////////////////////////" << std::endl;
			return;
		}

    //chooses the length of the boat based on the type of the boat
    switch (boatType) {
			case AircraftCarrier:
				boatLength = 5;
        assignedValue = true;
				break;
			case Battleship:
				boatLength = 4;
        assignedValue = true;
				break;
			case Submarine:
				boatLength = 3;
        assignedValue = true;
				break;
			case Destroyer:
				boatLength = 3;
        assignedValue = true;
				break;
			case PatrolBoat:
				boatLength = 2;
        assignedValue = true;
				break;
			default:
				std::cout << "Error creating boat..." << std::endl;
				break;
		}
    lifePoints = boatLength;
  }
};

#endif
