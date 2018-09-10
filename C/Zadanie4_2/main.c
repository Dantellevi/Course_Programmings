#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
/*
	В радиоателье хранятся квитанции о сданной в ремонт радиоаппаратуре. 
Каждая квитанция содержит следующую информацию: наименование 
группы изделий (телевизоры, радиоприемники и т. п.), марку изделия, 
дату приемки в ремонт, состояние готовности заказа (выполнен, не выполнен). 
Вывести информацию о состоянии заказов на текущие сутки для заданной группы 
изделий.(использовать указатели и динамическое выделение памяти под структуры).

*/

typedef struct
{
	int day;
	int month;
	int year;
}DateTime;


typedef struct
{
	char NameGroup[100];
	char Marka[100];
	DateTime Date;
	int flagStatus;
}RadioAteliadef;


/*------------------Function Input Data-----------*/
void Input_data(RadioAteliadef *Cvitanciaes,int *N);
/*------------------Print Data-----------*/
void Print_ArrayStruct(RadioAteliadef *Cvitanciaes,int *N);
/*--------------------function output zaivki na tek Day-------------*/
void Serch_zaiavki(RadioAteliadef *Cvitanciaes,int *N);



int main(int argc, char *argv[])
{
	int N;
	printf("Input Count Cvitancies: ");
	scanf("%d",&N);
    RadioAteliadef *Cvitanciaes=(RadioAteliadef*)malloc(N*sizeof(RadioAteliadef));
	Input_data(Cvitanciaes,&N);
	//Print_ArrayStruct(Cvitanciaes,&N);
	Serch_zaiavki(Cvitanciaes,&N);
    return 0;
}

/*------------------Function Input Data-----------*/
void Input_data(RadioAteliadef *Cvitanciaes,int *N)
{
	for(int i=0;i<*N;i++)
	{
		printf("Input NameGroup(Tele,Radio,other): ");
		scanf("%s",&(Cvitanciaes[i].NameGroup));

		printf("Input Marka: ");
		scanf("%s",&(Cvitanciaes[i].Marka));

		printf("Input Status(1-gotov,0-negotov): ");
		scanf("%d",&(Cvitanciaes[i].flagStatus));

		printf("Input Date Postuple(day,month,year): \n");
		printf("Input Day: ");
		scanf("%d",&(Cvitanciaes[i].Date.day));
		printf("Input Month: ");
		scanf("%d",&(Cvitanciaes[i].Date.month));
		printf("Input Year: ");
		scanf("%d",&(Cvitanciaes[i].Date.year));

	}
}


/*------------------Print Data-----------*/
void Print_ArrayStruct(RadioAteliadef *Cvitanciaes,int *N)
{
	for(int i=0;i<*N;i++)
	{
		printf("NameGroup(Tele,Radio,other):%s\n",Cvitanciaes[i].NameGroup);
		printf("Marka:%s\n",Cvitanciaes[i].Marka);
		printf("Status(1-gotov,0-negotov):%d\n",Cvitanciaes[i].flagStatus);
		printf("Date Postuple(day.month.year):%d.%d.%d \n",Cvitanciaes[i].Date.day,Cvitanciaes[i].Date.month,Cvitanciaes[i].Date.year);
		printf("---------------------------------------------------------\n");
	}
}


/*--------------------function output zaivki na tek Day-------------*/
void Serch_zaiavki(RadioAteliadef *Cvitanciaes,int *N)
{
	DateTime t;
	printf("-------------zadanii Day---------------\n");
	printf("Input Day:");
	scanf("%d",&(t.day));
	printf("Input Month:");
	scanf("%d",&(t.month));
	printf("Input Year:");
	scanf("%d",&(t.year));
	int count=0;
	for(int i=0;i<*N;i++)
	{
		if(Cvitanciaes[i].Date.day==t.day && Cvitanciaes[i].Date.month==t.month && Cvitanciaes[i].Date.year==t.year)
		{
			count++;
		}
	}
	RadioAteliadef *CvN=(RadioAteliadef *)malloc(count*sizeof(RadioAteliadef));
	int index_c=0;
	for(int i=0;i<*N;i++)
	{
		if(Cvitanciaes[i].Date.day==t.day && Cvitanciaes[i].Date.month==t.month && Cvitanciaes[i].Date.year==t.year)
		{
			CvN[index_c]=Cvitanciaes[i];
			index_c++;
		}
	}
	printf("-------------Status Zaivok na zadanii Day---------------\n");
	Print_ArrayStruct(CvN,&count);

}

