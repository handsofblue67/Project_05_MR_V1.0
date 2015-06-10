#include "QHash.h"

QHash::QHash()
{
	for (int i = 0; i < Q_MAX; i++)
	{
		table[i] = empty;
	}
}

int QHash::getHashValueImproved(string data) //an improved hashing function that will result if fewer collisions, especially in larger tables
{
	unsigned int value = 0;
	for (unsigned int i = 0; i < data.length(); i++)
	{
		value += data[i];
	}

	return ((value * data.length()) % Q_MAX) - 1;
}

string QHash::insertImproved(string data) //improved insert function that takes advantage of the improved hasing function
{
	ostringstream oss;
	int index = getHashValueImproved(data);

	if (table[index] == empty)
	{
		table[index] = stoi(data);
		oss << "Inserted " << data << " at " << index << endl;
	}

	else
	{
		oss << "Collision detected while inserting " << data << " at location " << index << "... ";

		Q_RETURN_CODE inserted = resolveQuadratic((index), stoi(data));

		if (inserted == 0)
		{
			oss << " Inserted at " << index << endl;
		}

		else if (inserted == 1)
		{
			oss << " Failed to insert. Reason: Table is full\n";
		}

		else
		{
			oss << " Failed to insert. Reason: Table already the value " << data << " at location " << index << endl;
		}

	}

	return oss.str();
}

Q_RETURN_CODE QHash::resolveQuadratic(int& index, int data)
{
	int count = 0; //keeps track of the fullness of table
	int i = 1; //the quadratic element
	
	while (table[index] != -999 && count != Q_MAX) //as long as the current index is occupied, and the loop has not made a complete rotation (full array). Cycle through array.  
	{
		if (table[index] == data) //duplicate
		{
			return Q_DUPLICATE;
		}

		if (index >= (Q_MAX)) //if index is 19 (end of array), go to begining of array
		{
			index = 0;
		}

		if (table[index] != -999)//if no duplicate, and array is not full, move to next index in array
		{
			index += (i * i) % (Q_MAX);
			i++;
		}
		
		if (index >= Q_MAX)
		{
			index -= Q_MAX;
		}
		count++;
	}

	if (count == (Q_MAX)) //if array is full (made a full rotation)
	{
		return Q_FULL;
	}

	else //if found an empty index, add element
	{
		table[index] = data;
		return Q_INSERTED;
	}
}

string QHash::print()
{
	ostringstream oss;

	for (int i = 0; i < Q_MAX; i++)
	{
		oss << table[i] << endl;
	}

	return oss.str();
}