#include "Battleship.h"
#include <iostream>
using namespace std;

Grid::Grid() //Constructing and initializing all of the grids//
{
	initializeGrid(playerShipGrid);
	initializeGrid(playerShotGrid);
	initializeGrid(computerShipGrid);
	initializeGrid(computerShotGrid);
}

void Grid::placeShip(int x, int y, int size, bool isHorizontal)
{
	if (isHorizontal) //If statement for setting ship horizontally//
	{
		for (int i = 0; i < size; i++)
		{
			playerShipGrid[x][y + i] = '#';
		}
	}
	else //Else statement for setting ship vertically//
	{
		for (int i = 0; i < size; i++)
		{
			playerShipGrid[x + i][y] = '#';
		}
	}
}

void Grid::outputGrids() //Function that calls on all 4 of the outputting grid functions//
{
	cout << "Player Ship Grid" << endl;
	outputGrid(playerShipGrid);
	cout << endl;

	cout << "Player Shot Grid" << endl;
	outputGrid(playerShotGrid);
	cout << endl;

	cout << "Computer Ship Grid" << endl;
	outputGrid(computerShipGrid);
	cout << endl;

	cout << "Computer Shot Grid" << endl;
	outputGrid(computerShotGrid);
	cout << endl;
}

void Grid::outputGrid(char grid[10][10]) //Outputs a grid using two dimensional array//
{
	cout << "  "; //Makes so the grid is formatted properly//
	for (int i = 0; i < 10; i++)
	{
		cout << i << " "; //Spaces the characters out in the first line properly//
	}

	cout << endl;

	for (int i = 0; i < 10; i++) //For loop for making the 10 by 10 array//
	{
		cout << i << " ";
		for (int j = 0; j < 10; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

void Grid::initializeGrid(char grid[10][10])
{
	for (int i = 0; i < 10; i++) //For loop that replaces that empty spaces with water symbols//
	{
		for (int j = 0; j < 10; j++)
		{
			grid[i][j] = '~';
		}
	}
}



Ship::Ship()
{
	hp = -1; //Setting the ship data//
	length = -1;
	xLoc = -1;
	yLoc = -1;
	isHorizontal = false;
	name = "";
}


int Ship::getHp() //Returns the hp of the ships//
{
	return hp;
}

int Ship::getLength() //Returns the lengths of the ships//
{
	return length;
}

int Ship::getXLoc() //Returns the y location of the ship//
{
	return xLoc;
}

int Ship::getYLoc() //Returns the x location of the ship//
{
	return yLoc;
}

bool Ship::getIsHorizontal() //Returns whether or not the ship is horizontal//
{
	return isHorizontal;
}

std::string Ship::getName() //Returns the name of the ship//
{
	return name;
}

void Ship::setHp(int hp_) //Sets the hp of the ships//
{
	hp = hp_;
}

void Ship::setLength(int length_) //Sets the length of the ships//
{
	length = length_;
}

void Ship::setXLoc(int xLoc_) //Sets the x location of the ship//
{
	xLoc = xLoc_;
}

void Ship::setYLoc(int yLoc_) //Sets the y location of the ship//
{
	yLoc = yLoc_;
}

void Ship::setIsHorizontal(bool isHorizontal_) //Sets the bool value the user inputs//
{
	isHorizontal = isHorizontal_;
}

void Ship::setName(std::string name_) //Sets the name of the ship//
{
	name = name_;
}



Battleship::Battleship() //Initializes the computers and players ships//
{
	initializeFleet(playerFleet);
	initializeFleet(computerFleet);
}

void Battleship::placeShip()
{
	for (int i = 0; i < 5; i++) //For loop that places each ship in the index//
	{
		cout << "Place " << playerFleet[i].getName() << endl; //Prompting the user to set the initial location of the first ship//
		cout << "Enter starting coordinates (x, y): ";
		int x, y;
		cin >> x >> y;
		cout << "Enter direction (0 = vertical, 1 = horizontal): "; //Checking if user wants the ship to be horizontal or vertical//
		int direction;
		cin >> direction;

		playerFleet[i].setXLoc(x); //Uses all of the users inputs to initialze the ship and output it on the grid//
		playerFleet[i].setYLoc(y);
		playerFleet[i].setIsHorizontal(bool(direction));

		gameGrid.placeShip(playerFleet[i].getXLoc(), playerFleet[i].getYLoc(), playerFleet[i].getLength(),
			playerFleet[i].getIsHorizontal());
	}
}

void Battleship::outputGrids()
{
	gameGrid.outputGrids(); //Outputs all of the user-set data onto the grid//
}

void Battleship::initializeFleet(Ship fleet[5]) //Index for the 5 types of battleships//
{
	fleet[0].setName("Carrier"); //Sets the name of the first ship to carrier and sets the hp and length to 5//
	fleet[0].setHp(5);
	fleet[0].setLength(5);

	fleet[1].setName("Battleship"); //Sets the name of the second ship to battleship and sets the hp and length to 4//
	fleet[1].setHp(4);
	fleet[1].setLength(4);

	fleet[2].setName("Cruiser"); //Sets the name of the third ship to cruiser and sets the hp and length to 3//
	fleet[2].setHp(3);
	fleet[2].setLength(3);

	fleet[3].setName("Submarine"); //Sets the name of the fourth ship to submarine and sets the hp and length to 3//
	fleet[3].setHp(3);
	fleet[3].setLength(3);

	fleet[4].setName("Destroyer"); //Sets the name of the fifth ship to destroyer and sets the hp and length to 2//
	fleet[4].setHp(2);
	fleet[4].setLength(2);
}
