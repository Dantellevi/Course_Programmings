#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string.h>
#include <string>
using namespace std;

string DataFromDB()
{
	return "Data From BD";
}
string DataFromWebServer()
{
	return "Data Web Server";
}

void foo1()
{
	cout << "void foo1" << endl;
}

void foo2()
{
	cout << "void foo2" << endl;
}


int  foo1s(int a)
{
	return a+1;
}

int  foo2s(int a)
{
	return a * 2;
}

void ShowInfo(string (*foort)())
{
	cout << foort();
}

int main()
{
	setlocale(LC_ALL, "ru");
	/*void(*fooPointer)();//выдел€ю указатель на функцию
	int(*foos)(int a);//второй указатель на функцию
	fooPointer = foo1;//присваиваю указателю адрес функции
	fooPointer();//вызываю функцию по указателю
	 foos= foo1s;
	 cout << foos(123);*/

	ShowInfo(DataFromDB); 


	system("pause");
	return 0;
}



