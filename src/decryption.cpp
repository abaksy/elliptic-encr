#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;


class decrypt
{
	int seed;
	string data;
	int inv_parabola(int x);

public:
	decrypt();
	void decr(string filename);
};


int decrypt::inv_parabola(int x)
{
	return -1 * sqrt(4 * seed * x);
}


decrypt::decrypt()
{
	seed = 0;
	data = "";
}


void decrypt::decr(string filename)
{
	string temp;
	fstream file;
	int i = 0;
	file.open(filename, ios::in | ios::out);
	while (!file.eof())
	{
		file >> temp;
		if (i == 0)
		{
			seed = stoi(temp);
			i++;
			continue;
		}
		cout << (char)(stoi(temp) + inv_parabola(i - 1));
		i++;
	}
	cout << endl
		 << data;
}


void main()
{
	decrypt p;
	string filename;
	cin >> filename;
	p.decr(filename);
}