#pragma once
template<class T>
 void bublesort(T* arr,int n, bool (*comp)(T&,T&))
{
	bool flag = 1;
	T t;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < n - 1; i++)
			if (comp(arr[i], arr[i + 1])) {
				t = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = t;
				flag = true;
			}
	}
}
