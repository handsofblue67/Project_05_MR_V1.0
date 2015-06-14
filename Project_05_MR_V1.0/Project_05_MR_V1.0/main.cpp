#include<iostream>
#include<fstream>
#include<string>
#include "Hash.h"
#include "QHash.h"

using namespace std;

int main()
{
	cout << "Michael Robison\nCS2810\nProject 05\n\n";

	ifstream in;
	string answer;
	string file;
	int data;
	Hash hash;
	QHash hashImproved; //improved hash table with quadratic probing and better hash function
	string dataImproved;
	
	do
	{
		cout << "Enter the name of the file\n";
		file = "p5datafile.txt";
		//cin >> file;
		in.open(file);

		if (in.fail())
		{
			cout << "Failed to open file.\n'y' to try again\n";
		}

		else
		{

			cout << "\n--------------------------------------------------------------------------------";
			cout << "\nUsing mod hash\n--------------------------------------------------------------------------------\n"; //mod hashing function
			while (in >> data)
			{
				hash.getHashValue(data);
				cout << hash.insert(data) << endl;

			}

			in.clear(); //return to beginning of file
			in.seekg(0, ios::beg); 
	
			cout << hash.print() << endl;
			
			cout << "--------------------------------------------------------------------------------";
			cout << "\nUsing improved hash\n--------------------------------------------------------------------------------\n"; //improved hashing function and quadratic probing
			while (in >> dataImproved)
			{
				cout << hashImproved.insertImproved(dataImproved) << endl;
			}
			
			in.close();
			cout << hashImproved.print();
		}

		cout << "Enter 'y' if you want to use another file.\n";
		cin >> answer;
	
	} while (answer == "y");

	system("PAUSE");
	return 0;
}