

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>



/*
ПОИСК ПО КЛЮЧУ В ОДНОМЕРНОМ
 МАССИВЕ СТРУКТУР
(Найти покупателя с номером карточки 00458. Методы поиска: полный перебор и двоичный.)

*/
typedef struct
{
	char Name[100];
	long int numberID;
}ShoppingPerson;

/****************Функция задания количество покупателей**************/
void GetCountPerson(int *N);
/********************Функция заполнения данных покупателей***************/
void FillPerson(ShoppingPerson* pers,int *N);
/********************Функция вывода данных покупателей***************/
void PrintPerson(ShoppingPerson* pers,int *N);
/**********************Поиск покупателя по ключю*******************/
ShoppingPerson SearchPerson(ShoppingPerson* pers,long int *s,int *N);
ShoppingPerson SearchPersonBin(ShoppingPerson* pers,long int *s,int *N);


int main(int argc, char *argv[])
{
	int N;
	GetCountPerson(&N);
	ShoppingPerson *persons=(ShoppingPerson*)malloc(N*sizeof(ShoppingPerson));
	printf("Count Person Shhoping : %d\n",N);
	FillPerson(persons,&N);
	PrintPerson(persons,&N);

   
    return 0;
}


/****************Функция задания количество покупателей**************/
void GetCountPerson(int *N)
{
	printf("Input count Person sshopping: ");
	scanf("%d",N);
}

/********************Функция заполнения данных покупателей***************/
void FillPerson(ShoppingPerson* pers,int *N)
{
	for(int i=0;i<*N;i++)
	{
		printf("Input Name: ");
		scanf("%s",&(pers->Name));
		printf("Input ID: ");
		scanf("%ld",&(pers->numberID));
		printf("-------------------------------\n");
	}
}


/********************Функция вывода данных покупателей***************/
void PrintPerson(ShoppingPerson* pers,int *N)
{
	for(int i=0;i<*N;i++)
	{
		printf("ID:%ld \n",pers->numberID);
		printf(" Name: %s\n",pers->Name);
		
		printf("-------------------------------\n");
	}
}

/**********************Поиск покупателя по ключю*******************/
ShoppingPerson SearchPerson(ShoppingPerson* pers,long int *s,int *N)
{
	for(int i=0;i<*N;i++)
	{
		if(pers[i].numberID==*s)
		{
			return pers[i];
		}
	}
}


ShoppingPerson SearchPersonBin(ShoppingPerson* pers,long int *s,int *N)
{
	int left=0;
	int right=*N-1;
	ShoppingPerson search;
	int index=-1;
while (left <= right) // пока левая граница не "перескочит" правую
  {
    int mid = (left + right) / 2; // ищем середину отрезка
    if (*s ==pers[mid].numberID ) {  // если ключевое поле равно искомому
      search = pers[mid];     // мы нашли требуемый элемент,
	 index=mid;
      break;            // выходим из цикла
    }
    if (*s < pers[mid].numberID)     // если искомое ключевое поле меньше найденной середины
      right = mid - 1;  // смещаем правую границу, продолжим поиск в левой части
    else                  // иначе
      left = mid + 1;   // смещаем левую границу, продолжим поиск в правой части
  }
	return search;
}



