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
	void BubleSort();
	void InsertSort();
	void SelectSort();
	void ShelSort();
	void QuickSort();
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
inline void Array<T>::BubleSort()
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
inline void Array<T>::InsertSort()
{
	T t;
	for (int i = 1; i <n; i++)
	{
		int k = i;
		while (k > 0 && arr[k - 1] > arr[k])
		{
			t = arr[k - 1];
			arr[k - 1] = arr[k];
			arr[k] = t;
			k--;
		}
		
	}
	
}

template<class T>
inline void Array<T>::SelectSort()
{
	T t;
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min]) min=j;
		}
		if (min != i)
		{
			t = arr[min];
			arr[min] = arr[i];
			arr[i] = t;
		}
	}

}

template<class T>
inline void Array<T>::ShelSort()
{
	T t;
	for (int step = n / 2; step > 0; step /= 2)
	{
		for (int i = step; i < n; i++)
		{
			for (int j = i - step; j >= 0 && arr[j] > arr[j + step]; j -= step)
			{
				t = arr[j];
				arr[j] = arr[j + step];
				arr[j + step] = t;
			}
		}
	}
}

template<class T>
inline void Array<T>::QuickSort()
{
	qsort(arr, n, sizeof(T), comp);
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

