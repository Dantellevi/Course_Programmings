
#include <iostream>
#include <ctime>
#include <string.h>
#include <string>
using namespace std;

#define DEBUG 



int main()
{
	setlocale(LC_ALL, "ru");

#ifdef DEBUG
cout << "����� ���������:\n";
#else
	cout << "����� �� ���������:\n";
#endif // DEBUG


	
	for (int i = 0; i < 15; i++)
	{
		cout << i << endl;
	}
#ifdef DEBUG
cout << "����� �����\n";
#endif // DEBUG

	

	

	system("pause");
	return 0;
}



