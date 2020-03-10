#pragma once
#include <fstream>
using namespace std;
template <class T>
class Array
{
private:
	T* arr;
	int n;
	void copy(T* a, int k);
	
public:
	Array(T* a, int n);
	Array(int n);
	Array();
	Array(const Array& a);
	void setN(int n);
	Array& operator=(const Array& a);
	T& operator[](int n);
	friend ostream& operator <<(ostream& os, const Array& a) 
	{
		for (int i = 0; i < a.n; i++)
		{
			os << a.arr[i] << endl;
		}
		return os;
	}
	void bublesort();
	void sort() { qsort(arr, n, sizeof(T), comp); }
	friend istream& operator >>(istream& os, Array& a)
	{
		os >> a.n;
		a.setN(a.n);
		for (int i = 0; i < a.n; i++)
		{
			os >> a.arr[i];
		}
		return os;
	}

	static int comp(const void* a, const void* b) {
		T* ap = (T*)a;
		T* bp = (T*)b;
		if (*ap > * bp)return 1;
		if (*ap < * bp)return -1;
		else return 0;
	}
};


template<class T>
inline void Array<T>::copy(T* a, int k)
{
	for (int i = 0; i < k; i++)
	{
		arr[i] = a[i];
	}
}

template<class T>
inline void Array<T>::bublesort()
{
	bool flag = 1;
	T t;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < n-1; i++)
		if(arr[i]>arr[i+1]){
			t = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = t;
			flag = true;
		}
	}
}

template<class T>
inline Array<T>::Array(T* a, int n)
{
	arr = new T[n];
	this->n = n;
	copy(a, n);
}

template<class T>
inline Array<T>::Array(int n)
{
	arr = new T[n];
	this->n = n;
}

template<class T>
inline Array<T>::Array()
{
	arr = NULL;
	n = 0;
}

template<class T>
inline Array<T>::Array(const Array& a)
{
	n = a.n;
	arr = new T[n];
	copy(a.arr, n);
}

template<class T>
inline void Array<T>::setN(int n)
{
	if (arr)
		delete[]arr;
	arr = new T[n];
	this->n = n;
}

template<class T>
inline Array<T>& Array<T>::operator=(const Array<T>& a)
{
	this->n = a.n;
	if (arr)
		delete[]arr;
	arr = new T[n];
	copy(a.arr, n);
	return *this;
}

template<class T>
inline T& Array<T>::operator[]( int n)
{
	if (this->n < n)throw "index out of range";
	return arr[n];
}

