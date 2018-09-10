#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/* ВЫПОЛНЕНО
Дан файл со  строкой символов, 
состоящая из произвольного текста, слова разделены пробелами. 
Вывести на экран порядковый номер слова минимальной длины и количество 
символов в этом слове. Все это сохранить в другой файл(bin, txt).

*/

/*----------------Функция ввода имени файла-----------*/
void GetFileName(char *namef);
/*------------------Функция чтения строки из файла----------*/
void Read_Data(FILE *pr,char *buffer, char *NameFile);
/*--------------------Функция обработки строки , нахождение мин. слова в строке-------*/
void Parse_String(char *strParse, char *strMinstr, int *numb, int *nmbsymv);
/*------------------Функция записи результата в бинарный и текстовый файл----------*/
void Write_Result(FILE *pr,char *buffer, char *NameFile);


int main(int argc, char *argv[])
{
	FILE *fp;
	char NameFile[40];
    GetFileName(NameFile);
	char str[100]="Name File for work:";
	strcat(str,NameFile);
	puts(str);
	char bUF[256];
	Read_Data(fp,bUF,NameFile);
	char str2[300]="Read Data is File: ";
	strcat(str2,bUF);
	puts(str2);
	char wordSearch[20];
	int nmb;
	int nmb_sym;
	Parse_String(bUF,wordSearch, &nmb,&nmb_sym);
	printf("Min Word:%s\n ,number word: %d\n, count symvol :%d\n",wordSearch,nmb,nmb_sym);
	//----------------------------------------------------------------------------------------
	FILE *Nfiler;
	char res_mass[256];
	sprintf(res_mass,"Data:\n Min Word:%s\n ,number word: %d\n, count symvol :%d\n",wordSearch,nmb,nmb_sym);
	printf("-------------------------------------------------\n");
	
	char namenew[40];
	GetFileName(namenew);
	Write_Result(Nfiler,res_mass,namenew);
    return 0;
}


/*----------------Функция ввода имени файла-----------*/
void GetFileName(char *namef)
{
	printf("Input File Name: ");
	gets_s(namef);
}


/*------------------Функция чтения строки из файла----------*/
void Read_Data(FILE *pr,char *buffer, char *NameFile)
{
	pr=fopen(NameFile,"r");
	fgets(buffer,100,pr);
	fclose(pr);
}

/*------------------Функция записи результата в бинарный и текстовый файл----------*/
void Write_Result(FILE *pr,char *buffer, char *NameFile)
{
	pr=fopen(NameFile,"ab");
	if(pr!=NULL)
	{
		fwrite(buffer,sizeof(char),strlen(buffer),pr);
	}
	else
	{
		printf("Error Create and write bin File\n");
	}
	
}



void buf_clear(char *str)
{
	for(unsigned int i=0;i<strlen(str);i++)
	{
		str[i]=0;
	}

}


/*--------------------Функция обработки строки , нахождение мин. слова в строке-------*/
void Parse_String(char *strParse, char *strMinstr, int *numb, int *nmbsymv)
{
	int count_space=0;
	int count_word;
	for(unsigned int  i=0;i<strlen(strParse);i++)
	{
		if(strParse[i]==' ')
		{
			count_space+=1;
		}
	}
	count_word=count_space+1;

	printf("space:%d\n",count_space);
	//выделить двум. массив по количеству слов, и сравнивать отдельно слова  
	char buffer_word[count_word][16];
	for(int i=0;i<count_word;i++)
	{
		for(int j=0;j<16;j++)
		{
			buffer_word[i][j]=0;
		}
	}
	int index_w=0;
	int index_w_c=0;
	for(int i=0;i<strlen(strParse);i++)
	{
		if(strParse[i]!=' ')
		{
			buffer_word[index_w][index_w_c]=strParse[i];
			index_w_c+=1;
		}
		else if(strParse[i]==' ')
		{
			index_w+=1;
			index_w_c=0;
		}
	}

	for(int j=0;j<count_word;j++)
	{
		printf("word[%d]=%s\n",j,buffer_word[j]);
	}
	
	int min_length=strlen(buffer_word[0]);
	int index_min;
	 
	char bfmin[16];
	strcpy(bfmin,buffer_word[0]);
	for(int k=0;k<count_word;k++)
	{
		if(min_length>strlen(buffer_word[k]))
		{
			min_length=strlen(buffer_word[k]);
			index_min=k;
			buf_clear(bfmin);
			strcpy(bfmin,buffer_word[k]);
			

		}
	}


	printf("min word= %s, index word=%d\n",bfmin,index_min);
	
	strcpy(strMinstr,bfmin);
	*numb=index_min;
	*nmbsymv=strlen(bfmin);


}









