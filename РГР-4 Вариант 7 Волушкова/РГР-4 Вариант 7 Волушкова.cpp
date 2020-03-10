#include <string>  
#include <iostream>
#include "TRAIN.h"
#include "Header.h"
using namespace std;
int main()
{
	Array<Train> vokz(8);
	ifstream in("Rasp.txt");
	in >> vokz;
	vokz.bublesort();
	cout << vokz;
}
