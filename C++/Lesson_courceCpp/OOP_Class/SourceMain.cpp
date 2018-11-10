
#include <iostream>
#include <ctime>
#include <string.h>
#include <string>
using namespace std;


class Human
{
public:
	int Age;
	int weiht;
	string Name;


	void Print()
	{
		cout << "Имя:" << Age << "\t" << "Вес:" << weiht << "\t" << "Имя:" << Name << endl;

	}



};


int main()
{
	setlocale(LC_ALL, "ru");
	Human Sergey;
	Sergey.Age = 56;
	Sergey.Name = "Сергей";
	Sergey.weiht = 100;
	Sergey.Print();

	system("pause");
	return 0;
}



