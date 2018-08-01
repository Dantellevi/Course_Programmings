#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/****************************************************************************
 *                                                                          *
 * ����� ������ �� k �����. 
������������� ������ ��������� �������: 
��� ������������� �������� ������� ��������� � ������, � ��� ��������� � � �����, 
�������� �������� �������� ������������ ��� ����� �������������, ��� � ����� ������������� ���������.                                          *
 *                                                                          *
 ****************************************************************************/
/*---------------������� ���������� �������----------*/
void Mass_fill(int *mass,int size);
/*---------------������� ������ �������----------*/
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


/*---------------������� ���������� �������----------*/
void Mass_fill(int *mass,int size)
{
	for(int i=0;i<size;i++)
	{
		mass[i]=-10+rand()%20;
	}
}
/*---------------������� ������ �������----------*/
void Mass_print(int mass[],int size)
{
	for(int i=0;i<size;i++)
	{
		printf("mass[%d]=%d\n",i,mass[i]);
	}
}

