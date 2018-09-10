// WorkFunctions.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <ctime>

using namespace std;

void foo(void)
{
	cout << "Вызов функции!!!" << endl;
}


int main()
{
	setlocale(LC_ALL, "ru");
	foo();
	system("pause");
    return 0;
}





