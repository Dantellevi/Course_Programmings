

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>



/*
����� �� ����� � ����������
 ������� ��������
(����� ���������� � ������� �������� 00458. ������ ������: ������ ������� � ��������.)

*/
typedef struct
{
	char Name[100];
	long int numberID;
}ShoppingPerson;

/****************������� ������� ���������� �����������**************/
void GetCountPerson(int *N);
/********************������� ���������� ������ �����������***************/
void FillPerson(ShoppingPerson* pers,int *N);
/********************������� ������ ������ �����������***************/
void PrintPerson(ShoppingPerson* pers,int *N);
/**********************����� ���������� �� �����*******************/
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


/****************������� ������� ���������� �����������**************/
void GetCountPerson(int *N)
{
	printf("Input count Person sshopping: ");
	scanf("%d",N);
}

/********************������� ���������� ������ �����������***************/
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


/********************������� ������ ������ �����������***************/
void PrintPerson(ShoppingPerson* pers,int *N)
{
	for(int i=0;i<*N;i++)
	{
		printf("ID:%ld \n",pers->numberID);
		printf(" Name: %s\n",pers->Name);
		
		printf("-------------------------------\n");
	}
}

/**********************����� ���������� �� �����*******************/
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
while (left <= right) // ���� ����� ������� �� "����������" ������
  {
    int mid = (left + right) / 2; // ���� �������� �������
    if (*s ==pers[mid].numberID ) {  // ���� �������� ���� ����� ��������
      search = pers[mid];     // �� ����� ��������� �������,
	 index=mid;
      break;            // ������� �� �����
    }
    if (*s < pers[mid].numberID)     // ���� ������� �������� ���� ������ ��������� ��������
      right = mid - 1;  // ������� ������ �������, ��������� ����� � ����� �����
    else                  // �����
      left = mid + 1;   // ������� ����� �������, ��������� ����� � ������ �����
  }
	return search;
}



