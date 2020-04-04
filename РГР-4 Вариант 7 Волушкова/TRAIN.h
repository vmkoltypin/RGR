#pragma once
#include <string>  
#include <fstream>
using namespace std;
class Train
{
private:
	string dest;
	int num;
	int time;
public:
	Train();
	Train(string dest, int num,int time);
	bool operator>(const Train& a);
	bool operator<(const Train& a);
	bool operator==(const Train& a);
	bool operator!=(const Train& a);
	Train& operator=(const Train& a);
	friend ostream& operator << (ostream& os, const Train& a);
	friend istream& operator >>(istream& os, Train& a);
};

