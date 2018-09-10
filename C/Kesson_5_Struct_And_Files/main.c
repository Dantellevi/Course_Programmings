#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdint.h>


/*
На АТС информация о разговорах содержит номер телефона абонента, 
время разговора и тариф. Вывести для заданного абонента сумму, 
которую ему следует оплатить за разговоры.

*/

typedef enum
{
	Tarif_1,
	Tarif_2,
	Tarif_3,
	Tarif_4
}TarifPhone;


typedef struct
{
	char NameAbonent[50];
	char PhoneNumber[10];
	char TimeSpeek[50];
	TarifPhone Tf;
}SpeekPhonedef;




/**********************Функция заполнения массива структур**************/
void FillStructs(SpeekPhonedef * str,int *N);
/**********************Функция вывода массива структур**************/
void Printt_Structs(SpeekPhonedef * str,int *N);
/***********************Функция поиска необходимого обонента******************/
void Search_AbonentData(SpeekPhonedef * str,int *N,FILE *fl);



int main(int argc, char *argv[])
{
	FILE *file;
	char NameFile[50];
	printf("Input NameFile: ");
	scanf("%s",&NameFile);

	int N;
   	printf("Input count Abonent: ");
	scanf("%d",&N);
	printf("Count Abonent=%d\n",N);
	SpeekPhonedef *abonents=(SpeekPhonedef *)malloc(N*sizeof(SpeekPhonedef));
	FillStructs(abonents,&N);
	Printt_Structs(abonents,&N);
	Search_AbonentData(abonents,&N,file);
    return 0;
}


/**********************Функция заполнения массива структур**************/
void FillStructs(SpeekPhonedef * str,int *N)
{
	for(int i=0;i<*N;i++)
	{
		printf("Input Name Abonent: ");
		scanf("%s",&(str[i].NameAbonent));

		printf("Input PhoneNumber Abonent: ");
		scanf("%s",&(str[i].PhoneNumber));

		printf("Input TimeSpeek Abonent: ");
		scanf("%s",&(str[i].TimeSpeek));

		int n=0;
		printf("Input Tarif Abonent: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
			{
				str[i].Tf=Tarif_1;
				break;
			}
			case 2:
			{
				str[i].Tf=Tarif_2;
				break;
			}
			case 3:
			{	
				str[i].Tf=Tarif_3;
				break;
			}
			case 4:
			{
				str[i].Tf=Tarif_4;
				break;
			}
		}
		printf("*****************************************\n");
		
	}

	printf("===============================================\n");
}


/**********************Функция вывода массива структур**************/
void Printt_Structs(SpeekPhonedef * str,int *N)
{
	printf("OutPut Array : ");
	for(int i=0;i<*N;i++)
	{
		printf(" Name Abonent: %s\n",str[i].NameAbonent);
		

		printf(" PhoneNumber Abonent: %s\n",str[i].PhoneNumber);
		

		printf(" TimeSpeek Abonent: %s\n",str[i].TimeSpeek);
		

		
		printf(" Tarif Abonent: ");
		
		switch(str[i].Tf)
		{
			case Tarif_1:
			{
				printf(" Tarif-1\n ");
				break;
			}
			case Tarif_2:
			{
				printf(" Tarif-2\n ");
				break;
			}
			case Tarif_3:
			{	
				printf(" Tarif-3\n ");
				break;
			}
			case Tarif_4:
			{
				printf(" Tarif-4\n ");
				break;
			}
		}
		printf("*****************************************\n");
		
	}

	printf("==============================================\n");
}


/***********************Функция поиска необходимого обонента******************/
void Search_AbonentData(SpeekPhonedef * str,int *N,FILE *fl)
{
	
		
		char NameUser[50];
		printf("Input Name User: ");
		scanf("%s",&NameUser);
		
		char *buffer;
		int size = sizeof(SpeekPhonedef);
		
		for(int i=0;i<*N;i++)
	{	int a=strcmp(NameUser,str[i].NameAbonent);
		printf("A=%d\n",a);
		if(a==0)
		{
			fl=fopen("data.bin","w+b");
			if(fl==NULL)
			{
				printf("Error opening file\n");

			}
			else
			{
				
				printf("Save Data!!!\n");
				SpeekPhonedef dt=str[i];
				buffer=(char*)(&dt);
				for(int i=0;i<size;i++)
				{
					putc(*buffer++,fl);
				}


				
			}
		}
	}

	fclose(fl);

	
	
}





