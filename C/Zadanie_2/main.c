#include <malloc.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

/****************************************************************************
 *     ВЫПОЛНЕНО!!!                                                                     *
 	Задание 2(динамическое выделение памяти для двумерных массивов с использованием указателей):
-Из матрицы размером NxM получить матрицу размером (N–1) x (M–1) путем удаления из исходной матрицы 
строки и столбца, на пересечении которых 
расположен элемент с наибольшим по модулю значением.
 *                                                                          *
 ****************************************************************************/

/*----------------------Функция заполнения матрицы---------------*/
void Fill_Matrix(int *Matrix,int Rows,int Columns);
/*----------------------Функция вывода в консоль матрицы---------------*/
void Print_Matrix(int *Matrix,int Rows,int Columns);
/*----------------------Функция поиска максим. по модулю значения---------------*/
void Search_Mod_Max(int *Matrix,int Rows,int Columns,int *row_Mmax,int *column_Mmax);
/*-------------------------Функция удаления строки и столбца из исходной матрицы------------*/
void Delete_Data(int *mass,int sizeR,int sizeC,int *massN,int sizeRn,int sizeCn,int row_Mmax,int col_Mmax);


int main(int argc, char *argv[])
{
	int *matrix;
	int *matrix_New;
	int N;
	printf("Input number Row: ");
	scanf("%d",&N);
  	
	int M;
	printf("Input number Columns: ");
	scanf("%d",&M);

	//выделение памяти под матрицу
	matrix=(int*)malloc(N*M*sizeof(int));
	
	Fill_Matrix(matrix,N,M);//заполнение матрицы
   Print_Matrix(matrix,N,M);//вывод матрицы
	int index_row_Mmax=0;
	int index_Col_Mmax=0;
	Search_Mod_Max(matrix,N,M,&index_row_Mmax,&index_Col_Mmax);//поиск макс. значение по модулю
	printf("|Max[%d][%d]|=%d\n",index_row_Mmax,index_Col_Mmax,*(matrix+index_row_Mmax*M+index_Col_Mmax));
    //выделение памяти под новую матрицу
	matrix_New=(int*)malloc((N-1)*(M-1)*sizeof(int));
	Delete_Data(matrix,N,M,matrix_New,(N-1),(M-1),index_row_Mmax,index_Col_Mmax);
	Print_Matrix(matrix,N,M);//вывод матрицы
	//-------------------Получение новой матрицы---------------------
	printf("-------------------New Matrix---------------------\n");
	Print_Matrix(matrix_New,N-1,M-1);//вывод новой матрицы
	return 0;
}

/*----------------------Функция заполнения матрицы---------------*/
void Fill_Matrix(int *Matrix,int Rows,int Columns)
{
	for(int i=0;i<Rows;i++)
	{
		for(int j=0;j<Columns;j++)
		{
			*(Matrix+i*Columns+j)=-25+rand()%100;
		}
	}

	//==========вывод для отладки=======
	printf("==========Out for Debug=======\n");
	for(int i=0;i<Rows;i++)
	{
		for(int j=0;j<Columns;j++)
		{
			printf("%d\t",*(Matrix+i*Columns+j));
		}

		printf("\n");
	}
//==========вывод для отладки=======
}


/*----------------------Функция вывода в консоль матрицы---------------*/
void Print_Matrix(int *Matrix,int Rows,int Columns)
{
	printf("==================OutPut Matrix==================\n");
	for(int i=0;i<Rows;i++)
	{
		for(int j=0;j<Columns;j++)
		{
			printf("%d\t",*(Matrix+i*Columns+j));
		}

		printf("\n");
	}

}
/*----------------------Функция поиска максим. по модулю значения---------------*/
void Search_Mod_Max(int *Matrix,int Rows,int Columns,int *row_Mmax,int *column_Mmax)
{
	int max=1;
	int i_max=0;
	int j_max=0;
	for(int i=0;i<Rows;i++)
	{
		for(int j=0;j<Columns;j++)
		{
			if(abs(*(Matrix+i*Columns+j))>max)
			{
				max=(*(Matrix+i*Columns+j));
				i_max=i;
				j_max=j;
			}
			
		}
	}

	*row_Mmax=i_max;
	*column_Mmax=j_max;

}

/*-------------------------Функция удаления строки и столбца из исходной матрицы------------*/
void Delete_Data(int *mass,int sizeR,int sizeC,int *massN,int sizeRn,int sizeCn,int row_Mmax,int col_Mmax)
{
	
		
			for(int j=0;j<sizeC;j++)
			{
				*(mass+row_Mmax*sizeC+j)=0;
			}

			for(int j=0;j<sizeR;j++)
			{
				*(mass+j*sizeC+col_Mmax)=0;
			}

	
//*(massN+m*sizeCn+n)=*(mass+k*sizeC+j);
	for(int k=0,n=0;k<sizeR;k++,n++)
	{
		if (k == row_Mmax) { n--; continue; } 

		for(int j=0,m=0;j<sizeC;j++,m++)
		{
			if(j==col_Mmax)
			{
				--m;
				continue;
			}
			*(massN+n*sizeCn+m)=*(mass+k*sizeC+j);

		}
	}


		


	

	


}


