
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


/****************************************************************************
 *                                                                          *
 * ��������� �� ����� ���������� �������� ��������
(����: ����� �������� ��������. ������ ����������: QuickSort � ���������� ��������.)                                          *
 *                                                                          *
 ****************************************************************************/
typedef struct
{
	char Name[50];
	long int number;
}Abonentsdef;

/**************************������� ��������� ����������� ������� ��������*****************/
void Get_Size_Array(int *Size);
/**************************������� ��������� ������� ������� ���������*****************/
void Get_ArrayAbonents(Abonentsdef* Aabonents,int *N);
/**************************������� ������ ��������� � �������*****************/
void Print_Information(Abonentsdef* Aabonents,int *N);
/**********************������� ����������*****************/
void QuickSort(Abonentsdef* Aabonents,int left,int right);
/**********************���������� ���������***********************/
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


/**************************������� ��������� ����������� ������� ��������*****************/
void Get_Size_Array(int *Size)
{
	printf("Input Size Massive for Sort: ");
	scanf("%d",&(*Size));

}

/**************************������� ��������� ������� ������� ���������*****************/
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
/**************************������� ������ ��������� � �������*****************/
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

/**********************������� ����������*****************/
void QuickSort(Abonentsdef* Aabonents,int left,int right)
{
	Abonentsdef pivot; // ����������� �������
	int pivot_index;
	int l_hold = left; //����� �������
  	int r_hold = right; // ������ �������
	pivot=Aabonents[left];
	
	while(left<right)//���� ������� �� ���������
	{
		while((Aabonents[right].number>=pivot.number)&&(left<right))
		{
			right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]

		}
		if (left != right) // ���� ������� �� ����������
    	{
    	  Aabonents[left] = Aabonents[right]; // ���������� ������� [right] �� ����� ������������
    	  left++; // �������� ����� ������� ������ 
   		}
		while ((Aabonents[left].number <= pivot.number) && (left < right))
      		left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
		
		if (left != right) // ���� ������� �� ����������
    	{
      		Aabonents[right] = Aabonents[left]; // ���������� ������� [left] �� ����� [right]
      		right--; // �������� ������ ������� ������ 
    	}
	}

	Aabonents[left] = pivot; // ������ ����������� ������� �� �����
  	pivot_index = left;
  	left = l_hold;
  	right = r_hold;
  	if (left < pivot_index) // ���������� �������� ���������� ��� ����� � ������ ����� �������
    QuickSort(Aabonents, left, pivot_index - 1);
  	if (right > pivot_index)
    QuickSort(Aabonents, pivot_index + 1, right);
}

/**********************���������� ���������***********************/
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




