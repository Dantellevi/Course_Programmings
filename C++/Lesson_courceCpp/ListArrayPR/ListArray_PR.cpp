#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string.h>
#include <string>
using namespace std;

struct dataList
{
	int data;//данные элемента
	dataList *next;//ссылка на следующий элемент
};

/********************Добавление элемента в список данных************/
dataList* data_Add(int a)
{
	dataList * addElem = new dataList;//выделяем память
	addElem->data = a;//ВНОСИМ ДАННЫЕ
	addElem->next = NULL;
	return addElem;

}

void add(int a, dataList *bg)
{
	dataList *ne = new dataList;//новый элемент
	ne->data = a;//вносим данные
	ne->next = NULL;
	dataList *temp = bg;
	while (temp->next!=NULL)
	{
		temp = temp->next;//поиск конца
		temp->next = ne;//привязка нового элемента

	}
}

int main()
{
	setlocale(LC_ALL, "ru");

	system("pause");
	return 0;
}



