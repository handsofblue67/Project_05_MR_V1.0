#include "Hash.h"

Hash::Hash()
{
	for (int i = 0; i < MAX; i++)
	{
		table[i] = empty;
	}
}

int Hash::getHashValue(int data)
{
	return data % MAX;
}

string Hash::insert(int data)
{
	ostringstream oss;

	int index = getHashValue(data);
	if (table[index] == empty)
	{
		table[index] = data;
		oss << "Inserted at" << index;
	}

	if (table[index] != empty)
	{
		bool inserted = resolveCollision((index), data);
		
		if (inserted == 0)
		{
			oss << "Inserted";
		}

		else if (inserted == 1)
		{
			oss << "Failed to insert\nReason: Table is full";
		}

		else
		{
			oss << "Failed to insert\nReason: Table already the value" << data << "at location" << index;
		}

	}
	
	return oss.str();
}

RETURN_CODE Hash::resolveCollision(int index, int data)
{
	int count = 0;
	while (table[index] != -999 && count != MAX) //as long as the current index is occupied, and the loop has not made a complete rotation (full array). Cycle through array.  
	{
		if (table[index] == data) //duplicate
		{
			return DUPLICATE;
		}

		if (index == (MAX - 1)) //if index is 19 (end of array), go to begining of array
		{
			index = 0;
		}
		
		else //if no duplicate, and array is not full, move to next index in array
		{
			index++; 
		}
	
		count++;
	}

	if (index == (index - 1)) //if array is full (made a full rotation)
	{
		return FULL;
	}

	if (table[index] == -999) //if found an empty index, add element
	{
		table[index] = data;
		return INSERTED;
	}
}

string Hash::print()
{
	ostringstream oss;
	
	for (int i = 0; i < MAX; i++)
	{
		oss << table[i] << endl;
	}
	
	return oss.str();
}