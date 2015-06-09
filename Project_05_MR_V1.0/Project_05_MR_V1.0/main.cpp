#include<iostream>
#include<fstream>
#include<string>
#include "Hash.h"

using namespace std;

int main()
{
	cout << "Michael Robison\nCS2810\nProject 05\n\n";

	ifstream in;
	string answer;
	string file;
	int data;
	Hash hash;
	Hash hashImproved;
	string dataImproved;
	
	do
	{
		cout << "Enter the name of the file\n";
		cin >> file;
		in.open(file);

		if (in.fail())
		{
			cout << "Failed to open file.\n'y' to try again\n";
			cin >> answer;
		}

		else
		{

			cout << "\nUsing mod hash\n\n"; //mod hashing function
			while (in >> data)
			{
				cout << hash.insert(data) << endl;

			}
			cout << hash.print();
		
			in.clear(); //return to beginning of file
			in.seekg(0, ios::beg); 
			
			cout << "\nUsing improved hash\n\n"; //print to mark new hashing function
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