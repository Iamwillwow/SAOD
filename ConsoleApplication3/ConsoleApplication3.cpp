// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//kkk

#include "pch.h"
#include <iostream>
#include <cmath>
#include <ctime>


using namespace std;

int main()
{
	int sizeOfArray;
	cout << "Enter n:";
	cin >> sizeOfArray;
	int *a = new int[sizeOfArray];
	srand(time_t(NULL));
	for (int i = 0; i < sizeOfArray; i++)
	{
		a[i] = rand();
	}

	for (int i = 0; i < sizeOfArray; i++)
	{
		cout << "Elem " << i << " is  " << a[i] << endl;
	}
	//int a[7] = { -1, -3, 4, -3, -55, 5, 6 };

	int max = a[0]; // 1
	for (int i = 0; i < sizeOfArray; i++) { // 1 + N + N = 2N + 1
		if (abs(a[i]) > abs(max)) { // 0 or N
			max = a[i]; //0 or N
		}
	}
	//Final Best Result = 2N + 2 = 2N = N = O(n)
	//Final Worst Result = 2N + 2 + 2N => 4N + 2 => 4N => N => O(n)
	cout << "Max abs el:" << max << endl;





	;
	int numMaxFirst, sum = 0; // 2

	// ищем первый положительный
	for (int i = 0; i < sizeOfArray; i++) //1 2n
	{
		if (a[i] > 0) //0 or N
		{ // если элемент больше положительный запоминаем его для сравнения      			
			numMaxFirst = i;// и запоминаем его позицию //0 or 1
			break;
		}
	}

	// ищем с конца положительный элемент
	for (int i = sizeOfArray; i >= 0; --i) // 1 + 2n
	{
		if (a[i] > 0) // нашли положительный элемент //0 or 1
		{
			if (i == numMaxFirst) // позиция совпала с уже имеющимся значит // 0 or 1
			{ //  положительный элемент один
				cout << "\none positive element: 0";
			}
			else  // иначе
			{ // считаем количество
				for (int j = numMaxFirst + 1; j < i; j++) // 2  N N
					sum += a[j]; //N
				cout << "sum between positive element: " << sum;
			}
			break; //FBResult = 3 + 2n + 0 + 0 + 2n + 0 + 0 + 2 + 2N = 6n + 5 = n = O(n) 
 			//FWResult1 = 3 + 2n + N + 1 + 1 + 2n + 1 + 1 + 2 + 2n = 7n + 9 = O(n)
		} 
	}

	return 0;
}

