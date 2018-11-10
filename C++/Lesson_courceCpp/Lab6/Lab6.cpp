#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>
#include <string.h>
#include <string>

using namespace std;

/*
Дана строка, состоящая из групп нулей и единиц. Подсчитать количество
единиц в группах с нечетным количеством символов.

*/

int main()
{
	setlocale(LC_ALL, "ru");
	
	int counter = 0;
	char s[] = "00000 1111111 000 1111 111111 00000000 11111";
	char *sPtr;

	sPtr = strtok(s, " ");
	while (sPtr != NULL)
	{
		if (strlen(sPtr) % 2 != 0 && *sPtr == '1')
		{
			counter += strlen(sPtr);
		}
		sPtr = strtok(NULL, " ");
	}

	cout << counter << endl;

	system("pause");
	return 0;
}



