#include <iostream>
#include <string>  
#include "TRAIN.h"
#include "Header.h"
#include "sort.h"
using namespace std;

template <class T>
void import(T* A, int n);
template <class T>
void download(ifstream& in, T* A, int n);



template <class T>
void import(T* A, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i]<<endl;
	}
}
template <class T>
void download(ifstream& in, T* A, int n)
{
	for (int i = 0; i < n; i++)
		in >> A[i];
}



int main()
{
	ifstream in("Rasp.txt", ios_base::in);

	int n;
	in >> n;
	//Array<Train> vokz(8);
	Train* vokz = new Train[n];

	//загружаем из файла
	download(in, vokz, n);
	cout << "\n\nInitial:\n" << endl;
	import(vokz, n);
	

	BubleSort(vokz, n, Train::compNum);//пузырьковая сортировка
	cout << "\n\nBubble:\n" << endl;

	import(vokz, n);


	download(in, vokz, n);
	cout << "\n\nInsert: " << endl;
	InsertSort(vokz, n, Train::compNum); //сортировка вставками
	import(vokz, n);


	download(in, vokz, n);
	cout << "\n\nSelect:\n" << vokz << endl;
	SelectSort(vokz, n, Train::compNum); //сортировка выбором
	import(vokz, n);


	download(in, vokz, n);
	cout << "\n\nShell: \n" << vokz << endl;
	ShelSort(vokz,0,n-1, Train::compNum); //сортировка Шелла
	import(vokz, n);

	download(in, vokz, n);
	cout << "\n\nqsort: \n" << vokz << endl;
	qsort(vokz, n, sizeof(Train), Train::compNum);
	import(vokz, n);

	download(in, vokz, n);
	cout << "\n\nQuick: \n " << vokz << endl;
	QuickSort(vokz,0, n-1, Train::compNum); //сортировка Хора
	import(vokz, n);
	
}
