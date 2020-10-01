#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <math.h>
using namespace std;


class secret
{
	int seed_store;
	int sum_store;

public:
	secret();
	int seed()
	{
		return seed_store;
	}
	int sum()
	{
		return sum_store;
	}
};


secret::secret()
{
	int local_seed = (int)time(NULL);
	seed_store = local_seed;
	double seed_arr[10];
	int i = 0;
	while (local_seed)
	{
		int temp = local_seed % 10;
		local_seed /= 10;
		seed_arr[i++] = temp;
	}
	int sum = 0;
	for (i = 0; i < 9; i += 1)
		sum += seed_arr[i];
	sum_store = sum;
}


class encrypt : protected secret
{
	int Seed;
	int SEED;
	string encrypted_data;

public:
	encrypt();
	int parabola(int x);
	void encr(string name);
};


void encrypt::encr(string name)
{
	fstream file;
	file.open(name, ios::in | ios::out);
	string data;
	while (!file.eof())
	{
		file >> data;
		cout << endl
			 << data << endl;
		int i = 0;
		while (i != data.length())
		{

			encrypted_data += to_string(data[i] + parabola(i));
			encrypted_data += " ";
			i++;
		}
	}

	cout << endl
		 << data << endl
		 << encrypted_data;
	file.close();
	ofstream encrfile("y.txt");
	encrfile << sum() << "\n"
			 << encrypted_data;
}


encrypt::encrypt()
{
	Seed = sum();
	SEED = seed();
	encrypted_data = "";
}


int encrypt::parabola(int x)
{
	return (int)sqrt(4 * Seed * x);
}


string operator>>(fstream &file, string &data)
{
	getline(file, data);
	return data;
}


int main()
{
	encrypt a;
	string filename;
	cin >> filename;
	a.encr(filename);
}
