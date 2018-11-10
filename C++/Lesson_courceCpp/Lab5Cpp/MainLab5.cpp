#include <iostream>
#include <ctime>
#include <string.h>
#include <string>
using namespace std;


/*

������ ������� �������� NxM. ���������� ���������� �������� ���������
�������, ������ ������� �������, ���� � ������ ����� �� ���� ���������
��������, ������� ���, � ������ � �������.


*/


int main()
{
	setlocale(LC_ALL, "ru");
	int N;
	int M;
	cout << "������� ���������� �����: ";
	cin >> N;
	cout << "������� ���������� ��������: ";
	cin >> M;
	int **matrix = new int*[N];
	for (int count = 0; count < N; count++)
		matrix[count] = new int[M]; 
	
	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			matrix[i][j] = rand() % 50 ;
		}

	}*/

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> matrix[i][j];
		}

	}
	
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;

	}
	

	int target_count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			bool flag = true;
			for (int k = j + 1; k <M; k++)
			{
				if (matrix[i][j] >= matrix[i][k])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				for (int k = j - 1; k >= 0; k--)
				{
					if (matrix[i][j] <= matrix[i][k])
					{
						flag = false;
						break;
					}
				}
			}
			else
			{
				continue;
			}
			if (flag)
			{
				target_count++;
			}
		}
	}



	cout << "���������� ������ ���������: " << target_count << endl;
	delete matrix;



	system("pause");
	return 0;
}



