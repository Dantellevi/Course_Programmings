#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/****************************************************************************
 *                                                                          *
 * Задан массив из k чисел. 
Преобразовать массив следующим образом: 
все отрицательные элементы массива перенести в начало, а все остальные – в конец, 
сохранив исходное взаимное расположение как среди отрицательных, так и среди положительных элементов.                                          *
 *                                                                          *
 ****************************************************************************/
/*---------------Функция заполнения массива----------*/
void Mass_fill(int *mass,int size);
/*---------------Функция вывода массива----------*/
void Mass_print(int mass[],int size);



int main(int argc, char *argv[])
{
   int k;
	printf("input massive Size-k: " );
	scanf("%d",&k);
	int mass[k];
	Mass_fill(mass,k);
	Mass_print(mass,k);
    return 0;
}


/*---------------Функция заполнения массива----------*/
void Mass_fill(int *mass,int size)
{
	for(int i=0;i<size;i++)
	{
		mass[i]=-10+rand()%20;
	}
}
/*---------------Функция вывода массива----------*/
void Mass_print(int mass[],int size)
{
	for(int i=0;i<size;i++)
	{
		printf("mass[%d]=%d\n",i,mass[i]);
	}
}

