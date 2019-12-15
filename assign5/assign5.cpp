// assign5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Crypt
{
private:
	virtual char hash(char c) = 0;
public:
	void execute(ifstream in, ofstream out)
	{
		while (in.good())
		{
			char ne = hash(in.get());
			out << ne;
		}
	}
};


class Encrypt : public Crypt //encryption class algorithm
{
private:
	char hash(char c)
	{
		char a = c + 5;
		return a;
	}
};

class Decrypt : public Crypt //decryption class algorithm
{
private:
	char hash(char c)
	{
		char a = c - 5;
		return a;
	}
};


class Engine { //engine class algorithm
public:
	Crypt * GetHandler(string k)
	{
		if (k == "encrypt")
		{
			static Encrypt E;
			return &E;
		}
		else
		{
			static Decrypt D;
			return &D;
		}
	}
};

int main()
{
	cout << "please enter action to perfrom\n";//user selects action to be performed
	string perform;
	cin >> perform;
	string filename;
	cout << "Please enter path to file\n";
	getline(cin, filename); //they enter the file path
	ifstream file(filename, ios::binary);
	string outfile = "new";// the file is recreated in the directory with "new" in front of it
	outfile.append("filename");
	ofstream ofile(outfile, ios::binary);
	Engine e;
	e.GetHandler(perform)->execute(file, ofile);//Couldn't figure out handler. Had to watch youtube videos, but this was never taught in class.
}
