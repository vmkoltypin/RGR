#include "TRAIN.h"
#include <string>  
using namespace std;

Train::Train()
{
	num = 0;
	time = 0;
	dest = "";
}

Train::Train(string dest,  int num,  int time)
{
	this->num = num;
	this->time = time;
	this->dest=dest;
}

bool Train::operator>(const Train& a)
{
	return this->num>a.num;
}

bool Train::operator<(const Train& a)
{
	return this->num < a.num;
}
bool Train::operator==(const Train& a)
{
	return this->num == a.num;
}

bool Train::operator!=(const Train& a)
{
	return this->num != a.num;
}

Train& Train::operator=(const Train& a)
{
	this->dest = a.dest;
	this->num = a.num;
	this->time = a.time;
	return *this;
}

ostream& operator<<(ostream& os, const Train& a)
{
	return os  << a.dest <<" "<< a.num << " " << a.time;
}

istream& operator>>(istream& os, Train& a)
{
	return os >> a.dest >> a.num >> a.time;
}
