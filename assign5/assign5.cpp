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


class Encrypt : public Crypt
{
private:
	char hash(char c)
	{
		char a = c + 5;
		return a;
	}
};

class Decrypt : public Crypt
{
private:
	char hash(char c)
	{
		char a = c - 5;
		return a;
	}
};


class Engine {
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
	cout << "please enter action to perfrom\n";
	string perform;
	cin >> perform;
	string filename;
	cout << "Please enter path to file\n";
	getline(cin, filename);
	ifstream file(filename, ios::binary);
	string outfile = "new";
	outfile.append("filename");
	ofstream ofile(outfile, ios::binary);
	Engine e;
	e.GetHandler(perform)->execute(file, ofile);
}
