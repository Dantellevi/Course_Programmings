#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string.h>

using namespace std;








int main()
{
	setlocale(LC_ALL, "ru");

	cout << sizeof(string) << endl;

	for (int i = 0; i < 255; i++)
	{
		cout << "code: " << i << " " << "char =" << (char)i << endl;
	}

	char *Sstring = "Hello World";
	cout << Sstring << endl;
	char **str = new char*[5];
	for (int i = 0; i < 5; i++)
	{
		str[i] = new char[100];
	}

	for (int j = 0; j < 5; j++)
	{
		cout << "Введите строку: ";
		cin >> str[j];
	}
	for (int j = 0; j < 5; j++)
	{
		cout << "Строкаp["<<j<<"]="<<str[j]<<endl;
		
	}
	cout << "==================Конкатенация====================\n";
	char mas[100] = "Hello";
	char mas2[100] = "World";

	cout << mas << endl;
	strcat(mas, mas2);
	cout << mas << endl;
	system("pause");
	return 0;
}



