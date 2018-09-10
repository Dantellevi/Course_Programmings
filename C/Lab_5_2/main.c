
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char name[16];
    int age;
}PersonDef;

/*******************Функция записи в бинарный файл********/
int saveperson(char *filename,PersonDef *stp);
int LoadPerson(char *fileName);
// загрузка из файла массива структур
int load(char * filename);
// запись в файл массива структур
int save(char * filename, PersonDef * st, int n);


int main(int argc, char *argv[])
{

    char * filename = "person.dat";
	PersonDef tom={"Tom",21};
	saveperson(filename, &tom);
    LoadPerson(filename);


	char * filenames = "people.dat";
    PersonDef people[] = { "Tom", 23, "Alice", 27, "Bob", 31, "Kate", 29 };
    int n = sizeof(people) / sizeof(people[0]);
 
    save(filenames, people, n);
    load(filenames);

    return 0;
}


/*******************Функция записи в бинарный файл********/
int saveperson(char *filename,PersonDef *stp)
{
	FILE *fp;
	char *c;
	int size=sizeof(PersonDef);//кол. байтов для записи
	if((fp=fopen(filename,"wb"))==NULL)//проверка на открытие файла
	{
		perror("Error occured while opening file");
        return 1;
	}
	// устанавливаем указатель на начало структуры
	c=(char *)stp;
	 // посимвольно записываем в файл структуру
	for (int i = 0; i < size; i++)
    {
        putc(*c++, fp);
    }
    fclose(fp);
    return 0;


}



int LoadPerson(char *fileName)
{
	FILE *fp;
	char *c;
	int i; // для считывания одного символа
	int size=sizeof(PersonDef);//кол. байтов
	PersonDef *ptr=(PersonDef*)malloc(size);//выделяем память для считываемой структуры
	if ((fp = fopen(fileName, "rb")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
	c=(char*)ptr;
	while((i=getc(fp))!=EOF)
	{
		*c=i;
		c++;
	}

	fclose(fp);
    // вывод на консоль загруженной структуры
    printf("%-20s %5d \n", ptr->name, ptr->age);
    free(ptr);
    return 0;
}





/************************************Работа с массивом структур***************************/

// запись в файл массива структур
int save(char * filename, PersonDef * st, int n)
{
    FILE * fp;
    char *c;
 
    // число записываемых байтов
    int size = n * sizeof(PersonDef);
     
    if ((fp = fopen(filename, "wb")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    // записываем количество структур
    c = (char *)&n;
    for (int i = 0; i<sizeof(int); i++)
    {
        putc(*c++, fp);
    }
 
    // посимвольно записываем в файл все структуры
    c = (char *)st;
    for (int i = 0; i < size; i++)
    {
        putc(*c, fp);
        c++;
    }
    fclose(fp);
    return 0;
}


// загрузка из файла массива структур
int load(char * filename)
{
    FILE * fp;
    char *c;
    int m = sizeof(int);
    int n, i;
 
    // выделяем память для количества данных
    int *pti = (int *)malloc(m);
 
    if ((fp = fopen(filename, "r")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    // считываем количество структур
    c = (char *)pti;
    while (m>0)
    {
        i = getc(fp);
        if (i == EOF) break;
        *c = i;
        c++;
        m--;
    }
    //получаем число элементов
    n = *pti;
 
    // выделяем память для считанного массива структур
    PersonDef * ptr = (PersonDef*) malloc(n * sizeof(PersonDef));
    c = (char *)ptr;
    // после записи считываем посимвольно из файла
    while ((i= getc(fp))!=EOF)
    {
        *c = i;
        c++;
    }
    // перебор загруженных элементов и вывод на консоль
    printf("\n%d people in the file stored\n\n", n);
 
    for (int k = 0; k<n; k++)
    {
        printf("%-5d %-20s %5d \n", k + 1, (ptr + k)->name, (ptr + k)->age);
    }
 
    free(pti);
    free(ptr);
    fclose(fp);
    return 0;
}

