#include <iostream>
#include <ctime>
#include <string.h>
#include <string>
#include <vector>

using namespace std;
/*


Библиотека стандартных шаблонов (STL)

VECTOR


*/




void main()
{
	setlocale(LC_ALL, "ru");
	
	vector<int> myVector;
	myVector.push_back(44);
	myVector.push_back(2);
	myVector.push_back(22);
	cout << "Количество в векторе :" << myVector.size()<< endl;
	for (int i = 0; i < myVector.size(); i++)
	{
		cout << myVector[i] << endl;
	}

	myVector.pop_back();
	cout << "Количество в векторе :" << myVector.size() << endl;
	for (int i = 0; i < myVector.size(); i++)
	{
		cout << myVector[i] << endl;
	}

	cout << "Количество в векторе :" << myVector.size() << endl;
	cout << "Capasity в векторе :" << myVector.capacity()<< endl;

	myVector.reserve(25);
	cout << "Capasity в векторе :" << myVector.capacity() << endl;
	system("pause");
}