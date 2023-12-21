#include <string>
using namespace std;


#ifndef GRID_H
#define GRID_H

class Grid //Making a grid class
{
public:
	Grid(); //constructing grid class//

	void placeShip(int x, int y, int size, bool isHorizontal); //function for placing a ship//
	//reference parameters for xy coords, the size of ship, and checking if it is vertical or horizontal//

	void outputGrids(); //function for outputting all grids//

private:
	void outputGrid(char grid[10][10]); //function for outputing individual grids//
	void initializeGrid(char grid[10][10]); //function for initializing the grids// 

	char playerShipGrid[10][10]; //Ship grid for user//
	char playerShotGrid[10][10]; //Shot grid for user//
	char computerShipGrid[10][10]; //Ship grid for computer//
	char computerShotGrid[10][10]; //Shot grid for computer//
};

#endif // !GRID_H


#ifndef SHIP_H
#define SHIP_H


class Ship //Making a ship class//
{
public:
	Ship(); //Constructing ship class//
	Ship(int hp, int length, int xLoc, int yLoc, bool isHorizontal, string name); //Assigning attributes to the ship//

	int getHp(); //Get functions for the attributes of the ship//
	int getLength(); 
	int getXLoc();
	int getYLoc();
	bool getIsHorizontal(); //Get function for checking if ship if horizontal or vertical//
	string getName(); //Get function for type of ship//

	void setHp(int hp); //Sets the attributes of the ship//
	void setLength(int length);
	void setXLoc(int xLoc);
	void setYLoc(int yLoc);
	void setIsHorizontal(bool isHorizontal); //Sets ship vertically or horizontally//
	void setName(string name); //Sets the name of the ship//

private:
	int hp; //Attributes of each battleship//
	int length;
	int xLoc;
	int yLoc;
	bool isHorizontal;
	string name;
};

#endif // !SHIP_H


#ifndef BATTLESHIP_H
#define BATTLESHIP_H

class Battleship //Making a Battleship game class//
{
public:
	Battleship(); //Constructing the game class//

	void placeShip(); //Function for placing ships on the grids//

	void outputGrids(); //Function for outputting grids with modifications//

private:
	Grid gameGrid; //Grid data that will have ship placing and grid outputting functions applied to it//
	Ship playerFleet[5]; //Index of the 5 user ships//
	Ship computerFleet[5]; //Index of the 5 computer ships//

	void initializeFleet(Ship fleet[5]); //Functioon for initializing the ships//
};

#endif // !BATTLESHIP_H

