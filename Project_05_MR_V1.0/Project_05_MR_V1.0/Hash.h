// Author:			Michael Robison
// Assignment:		5
// File:			Hash.cpp
// Instructor:		
// Class:			CS 2420
// Date Written:	6/14/2015
// Description:		hash class that meets the course requirements

//I declare that the following source code was written only by me.
//I understand that copying any source code, in whole or in part, constitutes cheating,
//and that I will receive a zero on this project if I am found in violation of this policy

#ifndef HASH_H
#define HASH_H
#include<string>
#include<sstream>

using namespace std;

//constants
enum RETURN_CODE{INSERTED, FULL, DUPLICATE};
const int MAX = 20;

class Hash
{
public:

	//Function Name: Hash constructor
	//Purpose: creates unparameterized Hash objects
	//Parameters: none
	//Returns: none
	Hash();

	//Function Name: getHashValue
	//Purpose: return the location in the array of a specified piece of data should be placed(the parameter)
	//Parameters: the data to find a location for(template type)
	//Returns: one integer indicating the location item should be placed
	int getHashValue(int);

	//Function Name: insert
	//Purpose: attempt to insert a passed piece of data into the table.
	//Parameters: one template item type
	//Returns: one integer indicating the location item should be placed
	string insert(int);

	//Function Name: resolveCollision
	//Purpose: resolve collisions that have occured during insert, insert in next best spot, unless table is full
	//Parameters: one template item type, and an int representing the original hash value
	//Returns: one bool
	RETURN_CODE resolveCollision(int&, int);

	//Function Name: print
	//Purpose: print each array index, and its contents
	//Parameters: none
	//Returns: none
	string show();

private:
	int table[MAX];
	string table2[MAX];
	int empty = -999;
};
#endif