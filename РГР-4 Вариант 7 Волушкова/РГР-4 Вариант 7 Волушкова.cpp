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
	//vokz.BubleSort(); //пузырьковая сортировка
	//vokz.InsertSort(); //сортировка вставками
	///vokz.SelectSort(); //сортировка выбором
	//vokz.ShelSort(); //сортировка Шелла
	//vokz.QuickSort(); //сортировка Хора
	cout << vokz;
}
