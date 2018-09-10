#include <iostream>
#include <ctime>

using namespace std;


void foo(void)
{
	cout << "ВЫзов функции!!!" << endl;

}


int Sum(int x, int y)
{
	return (x + y);
}

int foo_Inc(int a)
{
	return ++a;
}


void Fill_Array(int mass[],const int N)
{
	for (int i = 0; i < N; i++)
	{
		mass[i] = 1 + rand() % 10;

	}
}


void Print_Array(int mass[], const int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << "mass[" << i << "]=" << mass[i] << "\t";
	}
	cout << endl;
}


//--------------------Шаблоны функций ------------------
template <typename T1,typename T2>
T1 Sumator(T1 a, T2 b)
{
	return a + b;
}
//------------------------------------------------------


void main()
{
	setlocale(LC_ALL, "ru");
	int a = Sum(10, 12);
	cout << "Результат:" << a << endl;
	int s = 1;
	s = foo_Inc(s);
	cout << "S=" << s << endl;
	const int N = 10;
	int array[N];
	Fill_Array(array, N);
	Print_Array(array, N);
	//-----------------Шаблоны функций-----------------
	cout << Sumator(5, 10.0) << endl;
	cout << Sumator(5.2, 10.1) << endl;
	cout << Sumator(5, 10.1) << endl;


	system("pause");
}