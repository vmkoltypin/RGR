#include <iostream>
#include <fstream>
using namespace std;

template <class T >
inline void BubleSort(T* arr, int n, int(*comp)(const void*, const void*))
{
	T t;
	int flag = 1;
	while (flag)
	{
		flag = 0;
		for (int i = 0; i < n - 1; i++)
			if (comp(&arr[i],&arr[i + 1]))
			{
				t = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = t;
				flag = 1;
			}
	}
	/*or (int i = 0; i < n; i++)
		cout << arr[i]<< endl;
	cout << endl;*/
}

template<class T>
inline void InsertSort(T* arr, int n, int(*comp)(const void*, const void*))
{
	T t;
	for (int i = 1; i <n; i++)
	{
		int k = i;
		while (k > 0 && comp(&arr[k - 1], &arr[k]))
		{
			t = arr[k - 1];
			arr[k - 1] = arr[k];
			arr[k] = t;
			k--;
		}
		
	}
}

template<class T>
inline void SelectSort(T* arr, int n, int(*comp)(const void*, const void*))
{
	/*T t;
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (comp(&arr[min],&arr[j]) {min=j;}
		}
		if (min != i)
		{
			t = arr[min];
			arr[min] = arr[i];
			arr[i] = t;
		}
	}*/
	for (int i = 0; i < n - 2; i++)
	{
		int min = i;
		for (int j = i + 1; j < n - 1; j++)
			if (!comp(&arr[min], &arr[j]))
				min = j;
		T tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
	}
}

template<class T>
inline void ShelSort(T* arr, int l,int r, int(*comp)(const void*, const void*))
{
	for (int d = (r - l) / 2; d != 0; d /= 2)
		for (int i = l + d; i != r; ++i)
			for (int j = i; j - l >= d && !comp(&arr[j], &arr[j - d]); j -= d) {
				T tmp = arr[j];
				arr[j] = arr[j - d];
				arr[j - d] = tmp;
			}
}



//template<class T>
//static int comp(const void* a, const void* b) {
//	Array<T*> ap = (Array<T*>)a;
//	Array<T*> bp = (Array<T*>)b;
//	if (*ap > * bp)return 1;
//	if (*ap < *bp)return -1;
//	else return 0;
//}

//template<class T>
//inline void QuickSort(Array<T> arr, int n)
//{
//	qsort(arr, n, sizeof(T), comp);
//	for (int i = 0; i < n; i++)
//		cout << arr[i] << endl;
//	cout << endl;
//}


template <class T>
inline void QuickSort(T* A, int l, int r, int (*comp)(const void*, const void*))
{
	if (l < r) {
		int q = partition(A, l, r, comp);
		QuickSort(A, l, q, comp);
		QuickSort(A, q + 1, r, comp);
	}
}

template <class T>
inline int partition(T* A, int l, int r, int (*comp)(const void*, const void*))
{
	T v = A[(l + r) / 2];
	int i = l;
	int j = r;

	while (i <= j) {
		while (comp(&v, &A[i]))
			i++;

		while (comp(&A[j], &v))
			j--;

		if (i >= j)
			break;

		T tmp = A[i++];
		A[i++] = A[j--];
		A[j--] = tmp;
	}
	return	j;
}