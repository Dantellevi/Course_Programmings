#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <malloc.h>

/*
��������� ������������, ������� ������������� ��������
 � �����������, �������� ��� �����������, ������.
 ���������� ������� ���� �� ������������ � ������� ������
 ������������, ������� ���� ������� ���� �������� ����� �� ������������.
 ������� � ������ ������ ���� ��������, ������� ��� �������� �� 10.(��� ������������� ����������)
-� ����������� �������� ��������� � ������� � ������ ���������������. 
������ ��������� �������� ��������� ����������:
 ������������ ������ ������� (����������, �������������� � �. �.),
 ����� �������, ���� ������� � ������,
 ��������� ���������� ������ (��������, �� ��������).
 ������� ���������� � ��������� ������� �� ������� �����
 ��� �������� ������ �������.(������������ ��������� � ������������ ��������� ������ ��� ���������).


*/



typedef struct 
{ 
	char SerName[50]; 
	char Name[50]; 
	char SecondName[50]; 
	int make[5]; 

}STUDENTdef; 


/*----------------------Ooieoey caiieiaiey eenoa ni nooaaioaie------------------*/ 
void Fill_StudentsList(STUDENTdef *students,int *N); 
/*---------------------Ooieoey auaiaa aaiiuo nooaaioia----------------*/ 
void PrintArray(STUDENTdef *students,int *N); 
/*------------------------Ooieoey iaoi?aaiey n?aaiaai aaeea ii oieaa?neoaoo------------*/ 
double MidleMake(STUDENTdef *students,int *N); 
/*--------------------------------Ooieoey iaoi?aaiey nooaaioia o eioi?uo n?aaiee aae auoa n?aaiaai aaea ii oieaa?neoaoo--------------*/ 
void Serch_Students(STUDENTdef *students,int *N,double *mUn); 
/*--------------------------------Ooieoey iaoi?aaiey nooaaioia o eioi?uo ca ana yecaiaiu 10--------------*/ 
void Serch_10STUDENTS(STUDENTdef *students,int *N,STUDENTdef *students_10); 
/*--------------------------------Ooieoey auaiaa oaaeeou ni nooaaioaie--------------*/ 
void Print_TableStudents(STUDENTdef *students,int *N,double *mUn);




int main(int argc, char *argv[]) 
{ 
int N; 
printf("Input count students: "); 
scanf("%d",&N); 
printf("==========================\n "); 
STUDENTdef *students=(STUDENTdef*)malloc(N*sizeof(STUDENTdef)); 
Fill_StudentsList(students,&N); 
PrintArray(students,&N); 
printf("==========================\n "); 
double midleMake=MidleMake(students,&N); 
printf("Middle Make University: %lf\n",midleMake); 
printf("==========================\n "); 
Serch_Students(students,&N,&midleMake); 
return 0; 
} 

/*----------------------Ooieoey caiieiaiey eenoa ni nooaaioaie------------------*/ 
void Fill_StudentsList(STUDENTdef *students,int *N) 
{ 
for(int i=0;i<*N;i++) 
{ 
printf("Input Name:"); 
scanf("%s",&((students+i)->Name)); 

printf("Input SerName:"); 
scanf("%s",&((students+i)->SerName)); 

printf("Input SecondName:"); 
scanf("%s",&((students+i)->SecondName)); 

printf("Input Make: \n"); 
for(int j=0;j<5;j++) 
{ 
printf(" Make: \n"); 
scanf("%d",&(students[i].make[j])); 
} 
printf("-------------------------------------\n "); 


} 
} 


/*---------------------Ooieoey auaiaa aaiiuo nooaaioia----------------*/ 
void PrintArray(STUDENTdef *students,int *N) 
{ 
for(int i=0;i<*N;i++) 
{ 
printf(" Name: "); 
puts((students+i)->Name); 
printf("\n"); 
printf(" SerName: "); 
puts((students+i)->SerName); 
printf("\n"); 
printf("SecondName: "); 
puts((students+i)->SecondName); 
printf("\n"); 
printf("Make:\n "); 
for(int j=0;j<5;j++) 
{ 

printf("%d\n",students[i].make[j]); 
} 
printf("-------------------------------------\n "); 

} 
} 


/*------------------------Ooieoey iaoi?aaiey n?aaiaai aaeea ii oieaa?neoaoo------------*/ 
double MidleMake(STUDENTdef *students,int *N) 
{ 
int count_del=*N*5; 
int sum=0; 
for(int i=0;i<*N;i++) 
{ 
for(int j=0;j<5;j++) 
{ 
sum+=students[i].make[j]; 
} 
} 

return ((double)sum/(double)count_del); 

} 

/*--------------------------------Ooieoey iaoi?aaiey nooaaioia o eioi?uo n?aaiee aae auoa n?aaiaai aaea ii oieaa?neoaoo--------------*/ 
void Serch_Students(STUDENTdef *students,int *N,double *mUn) 
{ 
double mass_middleMake[*N]; 
for(int i=0;i<*N;i++) 
{ 
mass_middleMake[i]=0; 
} 
for(int i=0;i<*N;i++) 
{
	for(int j=0;j<5;j++) 
{ 
mass_middleMake[i]+=students[i].make[j]; 
} 
mass_middleMake[i]/=5; 
} 

for(int i=0;i<*N;i++) 
{ 
printf("mid_St[%d]=%lf\n",i,mass_middleMake[i]); 
} 




//ii?aaaeyai eie. nooaaioia n iaiaoiaeiui aaeeii
//nicaaai iannea ni no?oeoo?ie n iaeaai.eieee?anoaii nooaaioia
//caienuaaai aaiiua ec iaiie no?oeoo?u a a?oao? i?e niioaaonoaee n?aaieo aaeeia
//ni?oe?oai iiao? no?oeoo?o ii n?aaiaio aaeeo
//auaiaei a eiinieu

 int count_st=0;
for(int i=0;i<*N;i++) 
{ 
 if(mass_middleMake[i]>=*mUn)
		{
			count_st++;
		}
}

STUDENTdef *students_n=(STUDENTdef*)malloc(count_st*sizeof(STUDENTdef));
	int index_nStruct=0;
	for(int i=0;i<*N;i++)
	{
		if(mass_middleMake[i]>=*mUn)
		{
			students_n[index_nStruct]=students[i];
			index_nStruct++;
		}
	}

	printf("-------------------------TEST-------------------------\n");
	Print_TableStudents(students_n,&count_st,mUn);
	//Ooieoey auaiaa yeaiaioia iiaiai ianneaa no?oeoo?
	//PrintArray(students_n,&count_st);


}

/*--------------------------------Ooieoey auaiaa oaaeeou ni nooaaioaie--------------*/ 
void Print_TableStudents(STUDENTdef *students,int *N,double *mUn)
{
	double mid[*N];
	for(int i=0;i<*N;i++)
	{
		for(int j=0;j<5;j++)
		{
			mid[i]+=students[i].make[j];
		}
		mid[i]/=5;
	}
	printf("=======List student with make >middle make for University=========\n"); 
			printf(" SerName         | Name       | SecondName        | Make         |\n ");
	for(int i=0;i<*N;i++)
	{
		if(mid[i]>=10)
		{
			printf("%s               %s    	    %s                  %lf   \n",students[i].SerName,students[i].Name,students[i].SecondName,mid[i]);
		}
	}
	for(int i=0;i<*N;i++)
	{
		if(mid[i]>=*mUn && mid[i]<10)
		{
			printf("%s               %s    	    %s                  %lf   \n",students[i].SerName,students[i].Name,students[i].SecondName,mid[i]);
		}
	}



	
} 
