
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


/****************************************************************************
 *                                                                          *
 * ОРТИРОВКА ПО КЛЮЧУ ОДНОМЕРНЫХ МАССИВОВ СТРУКТУР
(Ключ: номер телефона абонента. Методы сортировки: QuickSort и сортировка вставкой.)                                          *
 *                                                                          *
 ****************************************************************************/
typedef struct
{
	char Name[50];
	long int number;
}Abonentsdef;

/**************************Функция получения размерности массива структур*****************/
void Get_Size_Array(int *Size);
/**************************Функция получения задания массива абонентов*****************/
void Get_ArrayAbonents(Abonentsdef* Aabonents,int *N);
/**************************Функция печати абонентов в консоль*****************/
void Print_Information(Abonentsdef* Aabonents,int *N);
/**********************Быстрая сортировка*****************/
void QuickSort(Abonentsdef* Aabonents,int left,int right);
/**********************Сортировка вставками***********************/
void Insert_Sort(Abonentsdef* Aabonents,int length);


int main(int argc, char *argv[])
{
    int N;
	Get_Size_Array(&N);
	printf("Size Array=%d\n",N);
	Abonentsdef *abonents=(Abonentsdef*)malloc(N*sizeof(Abonentsdef));
	Get_ArrayAbonents(abonents,&N);
	//QuickSort(abonents,0,N-1);
	Print_Information(abonents,&N);
	Insert_Sort(abonents,N);
	printf("-------------------------------\n");
	Print_Information(abonents,&N);

    return 0;
}


/**************************Функция получения размерности массива структур*****************/
void Get_Size_Array(int *Size)
{
	printf("Input Size Massive for Sort: ");
	scanf("%d",&(*Size));

}

/**************************Функция получения задания массива абонентов*****************/
void Get_ArrayAbonents(Abonentsdef* Aabonents,int *N)
{
	for(int i=0;i<*N;i++)
	{
		printf("Input Name Abonent: ");
		scanf("%s",&(Aabonents[i].Name));

		printf("Input Number abonents: ");
		scanf("%d",&(Aabonents[i].number));
	}
}
/**************************Функция печати абонентов в консоль*****************/
void Print_Information(Abonentsdef* Aabonents,int *N)
{
	printf("Table Abonents\n\n\n");
	printf("Abonent\t|\tNumber\t\n");
	printf("_________________________________________\n");
	for(int i=0;i<*N;i++)
	{
		printf("%d)%s			%d\n",i,Aabonents[i].Name,Aabonents[i].number);

	}
}

/**********************Быстрая сортировка*****************/
void QuickSort(Abonentsdef* Aabonents,int left,int right)
{
	Abonentsdef pivot; // разрешающий элемент
	int pivot_index;
	int l_hold = left; //левая граница
  	int r_hold = right; // правая граница
	pivot=Aabonents[left];
	
	while(left<right)//пока границы не сомкнутся
	{
		while((Aabonents[right].number>=pivot.number)&&(left<right))
		{
			right--; // сдвигаем правую границу пока элемент [right] больше [pivot]

		}
		if (left != right) // если границы не сомкнулись
    	{
    	  Aabonents[left] = Aabonents[right]; // перемещаем элемент [right] на место разрешающего
    	  left++; // сдвигаем левую границу вправо 
   		}
		while ((Aabonents[left].number <= pivot.number) && (left < right))
      		left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
		
		if (left != right) // если границы не сомкнулись
    	{
      		Aabonents[right] = Aabonents[left]; // перемещаем элемент [left] на место [right]
      		right--; // сдвигаем правую границу вправо 
    	}
	}

	Aabonents[left] = pivot; // ставим разрешающий элемент на место
  	pivot_index = left;
  	left = l_hold;
  	right = r_hold;
  	if (left < pivot_index) // Рекурсивно вызываем сортировку для левой и правой части массива
    QuickSort(Aabonents, left, pivot_index - 1);
  	if (right > pivot_index)
    QuickSort(Aabonents, pivot_index + 1, right);
}

/**********************Сортировка вставками***********************/
void Insert_Sort(Abonentsdef* Aabonents,int length)
{
	Abonentsdef temp;
	int item;
	for(int counter=1;counter<length;counter++)
	{
		temp=Aabonents[counter];
		item=counter-1;
		while(item>=0 && Aabonents[item].number>temp.number)
		{
			Aabonents[item+1]=Aabonents[item];
			Aabonents[item]=temp;
			item--;

		}
	}
}




