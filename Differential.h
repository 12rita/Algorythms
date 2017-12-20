#pragma once
#include "Header.h"
using namespace std;

class Differential
{
	string input, output;
	static int count;

	string mult(string, string);
	string div(string, string);
	string pow(string, string);
	string logariphm(string, string);
	string flog(string, int);
	string fcos(string, int);
	string fsin(string, int);
	string ftg(string, int);
	string fctg(string, int);
	string farccos(string, int);
	string farcsin(string, int);
	string farctg(string, int);
	string farcctg(string, int);

	string  dif(string);
	void handling();
public:
	Differential();
	~Differential();

	void sinput(string);
	string soutput();	
	void difer();	
};

