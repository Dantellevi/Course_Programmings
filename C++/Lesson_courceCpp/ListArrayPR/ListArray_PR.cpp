#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string.h>
#include <string>
using namespace std;

struct dataList
{
	int data;//������ ��������
	dataList *next;//������ �� ��������� �������
};

/********************���������� �������� � ������ ������************/
dataList* data_Add(int a)
{
	dataList * addElem = new dataList;//�������� ������
	addElem->data = a;//������ ������
	addElem->next = NULL;
	return addElem;

}

void add(int a, dataList *bg)
{
	dataList *ne = new dataList;//����� �������
	ne->data = a;//������ ������
	ne->next = NULL;
	dataList *temp = bg;
	while (temp->next!=NULL)
	{
		temp = temp->next;//����� �����
		temp->next = ne;//�������� ������ ��������

	}
}

int main()
{
	setlocale(LC_ALL, "ru");

	system("pause");
	return 0;
}



