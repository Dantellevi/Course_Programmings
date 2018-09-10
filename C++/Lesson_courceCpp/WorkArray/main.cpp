#include <iostream>
#include <ctime>


using namespace std;

/*--------------------Функция вывода массива---------------*/
void Print_Array(int *mass, int N);
/*-----------------Проверка на инверсию ---------------------*/
int  Check_Invert(int *mass, int N);


void main()
{
	setlocale(LC_ALL, "ru");

	const int k=10;

	

	int arr[k];

	for (int i = 0; i < k; i++)
	{
		
		cin >> arr[i];
	}

	Print_Array(arr, k);
	int count_inv ;
	count_inv=Check_Invert(arr, k);

	cout << "Количество пар элементов с инверсией=" << count_inv/2 << endl;

	
	system("pause");
}


/*--------------------Функция вывода массива---------------*/
void Print_Array(int *mass, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << "mass[" << i << "]=" << mass[i] << endl;
	}
}

/*-----------------Проверка на инверсию ---------------------*/
int  Check_Invert(int *mass, int N)
{
	int c = 0;
	for (int i = 0; i < N; i++)
	{
		if (i!=0)
		{
			if (mass[i]<mass[i-1])
			{
				c++;
				
			}
		}
	}

	return c+1;
}