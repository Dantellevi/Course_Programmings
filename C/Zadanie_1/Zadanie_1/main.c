#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/****************************************************************************
 *          ���������!!!!                                                                *
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
/*-----------------------������� �������������� �������--------*/
void Mass_Operation(int *mass,int size);


int main(int argc, char *argv[])
{
   int k;
	printf("input massive Size-k: " );
	scanf("%d",&k);
	int mass[k];
	Mass_fill(mass,k);
	Mass_print(mass,k);
	Mass_Operation(mass,k);
	printf("-------------------------\n");
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


/*-----------------------������� �������������� �������--------*/
void Mass_Operation(int *mass,int size)
{
	int size_minus=0;//������ ��� ������� � �����. �������
	int size_plus=0;//������ ��� ������� � �����.�������

	for(int i=0;i<size;i++)
	{
		if(mass[i]<0)
		{
			size_minus++;
		}
	}

	// ==========��� ��� �������=======
		//printf("Size minus=%d\n",size_minus);
	//=================================
	size_plus=size-size_minus;
	// ==========��� ��� �������=======
		//printf("Size plus=%d\n",size_plus);
	//=================================


	int mass_M[size_minus];
	int mass_P[size_plus];
	
	int index_c_M=0;//������ ��� ������� � ���.�������
	int index_c_P=0;//������ ��� ������� � ���.�������
	for(int j=0;j<size;j++)
	{
		if(mass[j]<0)
		{
			mass_M[index_c_M]=mass[j];
			index_c_M++;
		}
		else if(mass[j]>=0)
		{
			mass_P[index_c_P]=mass[j];
			index_c_P++;
		}
	}
	

// ==========��� ��� �������=======
	//printf("------------------------\n");
	//Mass_print(mass_M,size_minus);
	//printf("------------------------\n");
	//printf("------------------------\n");
	//Mass_print(mass_P,size_plus);
	//printf("------------------------\n");
	//=================================

	int ind_count=0;
	
	for(int i=0;i<size;i++)
	{
		mass[i]=0;
	}
	for(int k=0;k<size;k++)
	{
		
		if(ind_count<size_minus)
		{
			mass[k]=mass_M[ind_count];
			ind_count++;
		}
		
	}
// ==========��� ��� �������=======
	//printf("------------------------\n");
	//Mass_print(mass,size);
	//printf("------------------------\n");
	//=================================


	int ind_count_2=size_plus;
	for(int m=size;m>=size_minus;m--)
	{
		mass[m]=mass_P[ind_count_2];
		--ind_count_2;
	}
	
// ==========��� ��� �������=======
	//printf("------------------------\n");
	//Mass_print(mass,size);
	//printf("------------------------\n");
	//=================================



}




