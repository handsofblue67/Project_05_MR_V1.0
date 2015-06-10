#ifndef QHASH_H
#define QHASH_H
#include<string>
#include<sstream>

using namespace std;

//constants
enum Q_RETURN_CODE{ Q_INSERTED, Q_FULL, Q_DUPLICATE };
const int Q_MAX = 20;

class QHash
{
public:

	//Function Name: Hash constructor
	//Purpose: creates unparameterized Hash objects
	//Parameters: none
	//Returns: none
	QHash();

	//Function Name: getHashValue
	//Purpose: return the location in the array of a specified piece of data should be placed(the parameter)
	//Parameters: the data to find a location for(template type)
	//Returns: one integer indicating the location item should be placed
	int getHashValueImproved(string);

	//Function Name: insertImproved
	//Purpose: attempt to insert a passed piece of data into the table.
	//Parameters: one template item type
	//Returns: one integer indicating the location item should be placed
	string insertImproved(string);

	//Function Name: resolveQuadratic
	//Purpose: resolve collisions that have occured during insert using quadratic probing
	//Parameters: one template item type, and an int representing the original hash value
	//Returns: one bool
	Q_RETURN_CODE resolveQuadratic(int&, int);

	//Function Name: print
	//Purpose: print each array index, and its contents
	//Parameters: none
	//Returns: none
	string print();

private:
	int table[Q_MAX];
	int empty = -999;
};
#endif