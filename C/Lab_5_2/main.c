
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char name[16];
    int age;
}PersonDef;

/*******************������� ������ � �������� ����********/
int saveperson(char *filename,PersonDef *stp);
int LoadPerson(char *fileName);
// �������� �� ����� ������� ��������
int load(char * filename);
// ������ � ���� ������� ��������
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


/*******************������� ������ � �������� ����********/
int saveperson(char *filename,PersonDef *stp)
{
	FILE *fp;
	char *c;
	int size=sizeof(PersonDef);//���. ������ ��� ������
	if((fp=fopen(filename,"wb"))==NULL)//�������� �� �������� �����
	{
		perror("Error occured while opening file");
        return 1;
	}
	// ������������� ��������� �� ������ ���������
	c=(char *)stp;
	 // ����������� ���������� � ���� ���������
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
	int i; // ��� ���������� ������ �������
	int size=sizeof(PersonDef);//���. ������
	PersonDef *ptr=(PersonDef*)malloc(size);//�������� ������ ��� ����������� ���������
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
    // ����� �� ������� ����������� ���������
    printf("%-20s %5d \n", ptr->name, ptr->age);
    free(ptr);
    return 0;
}





/************************************������ � �������� ��������***************************/

// ������ � ���� ������� ��������
int save(char * filename, PersonDef * st, int n)
{
    FILE * fp;
    char *c;
 
    // ����� ������������ ������
    int size = n * sizeof(PersonDef);
     
    if ((fp = fopen(filename, "wb")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    // ���������� ���������� ��������
    c = (char *)&n;
    for (int i = 0; i<sizeof(int); i++)
    {
        putc(*c++, fp);
    }
 
    // ����������� ���������� � ���� ��� ���������
    c = (char *)st;
    for (int i = 0; i < size; i++)
    {
        putc(*c, fp);
        c++;
    }
    fclose(fp);
    return 0;
}


// �������� �� ����� ������� ��������
int load(char * filename)
{
    FILE * fp;
    char *c;
    int m = sizeof(int);
    int n, i;
 
    // �������� ������ ��� ���������� ������
    int *pti = (int *)malloc(m);
 
    if ((fp = fopen(filename, "r")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    // ��������� ���������� ��������
    c = (char *)pti;
    while (m>0)
    {
        i = getc(fp);
        if (i == EOF) break;
        *c = i;
        c++;
        m--;
    }
    //�������� ����� ���������
    n = *pti;
 
    // �������� ������ ��� ���������� ������� ��������
    PersonDef * ptr = (PersonDef*) malloc(n * sizeof(PersonDef));
    c = (char *)ptr;
    // ����� ������ ��������� ����������� �� �����
    while ((i= getc(fp))!=EOF)
    {
        *c = i;
        c++;
    }
    // ������� ����������� ��������� � ����� �� �������
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

