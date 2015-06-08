#include<iostream>
#include<fstream>
#include<string>
#include "Hash.h"

using namespace std;

int main()
{
	cout << "Michael Robison\nCS2810\nProject 05\n\n";

	ifstream in;
	string answer = "y";
	string file;
	int data;
	Hash<T> hash;

	while (answer == "y")
	{
		cout << "Enter the name of the file\n";
		cin >> file;
		in.open(file);

		if (in.fail());
		{
			cout << "Failed to open file.\n'y' to try again\n";
			cin >> answer;
		}
		while (in >> data)
		{
			hash.insert(data);
		}

	}

}