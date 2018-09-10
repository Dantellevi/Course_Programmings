#include <iostream>
#include <ctime>

using namespace std;



/*********************Функция инициализации двумерного массива***********************/
void FillMatrix(int **data, int *N, int *M);
/*********************************Функция вывода матрицы в консоль**********************/
void PrintMatrix(int **data, int *N, int *M);




int main()
{
	setlocale(LC_ALL, "ru");

	int  N;
	cout << "Введите размерность матрицы N: ";
	cin >> N;
	int  M;
	cout << "Введите размерность матрицы M: ";
	cin >> M;

	int **p_P_mas = new int*[N];
	FillMatrix(p_P_mas, &N, &M);
	PrintMatrix(p_P_mas, &N, &M);

	delete *p_P_mas;
	system("pause");
	return 0;
}



/*********************Функция инициализации двумерного массива***********************/
void FillMatrix(int **data, int *N, int *M)
{
	for (int i = 0; i < *N; i++)
	{
		data[i] = new int[*M];
	}

	for (int i = 0; i < *N; i++)
	{
		for (int j = 0; j < *M;j++)
		{
			data[i][j] = 1 + rand()% 100;
		}
	}




}

/*********************************Функция вывода матрицы в консоль**********************/
void PrintMatrix(int **data, int *N, int *M)
{
	for (int i = 0; i < *N; i++)
	{
		for (int j = 0; j < *M; j++)
		{
			cout << data[i][j] << "\t";
		}
		cout << "\n";
	}
}

