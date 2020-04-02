// file_decryption.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;
class decrypt
{
	int seed;
	string data;
	int inv_parabola(int x);
public:
	decrypt();
	void decr();
};

int decrypt::inv_parabola(int x)
{
	return -1 * sqrt(4 * seed*x);
}
decrypt::decrypt()
{
	seed = 0;
	data = "";
}
void decrypt::decr()
{
	string temp;
	fstream file;
	int i = 0;
	file.open("y.txt", ios::in | ios::out);
	while (!file.eof())
	{
		file >> temp;
		if (i == 0)
		{
			seed = stoi(temp);
			i++;
			continue;
		}
		//cout << endl <<"temp:"<< stoi(temp)<<" "<<"i:"<<i-1<<"inv_parabola:"<<inv_parabola(i-1);
		cout << (char)(stoi(temp) + inv_parabola(i - 1));
		i++;
	}
	cout << endl << data;
}

void main()
{
	decrypt p;
	p.decr();
	_getch();
}