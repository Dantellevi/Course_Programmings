#include <iostream>
#include <ctime>
#include <string.h>
#include <string>
#include <vector>

using namespace std;
/*


���������� ����������� �������� (STL)

VECTOR


*/




void main()
{
	setlocale(LC_ALL, "ru");
	
	vector<int> myVector;
	myVector.push_back(44);
	myVector.push_back(2);
	myVector.push_back(22);
	cout << "���������� � ������� :" << myVector.size()<< endl;
	for (int i = 0; i < myVector.size(); i++)
	{
		cout << myVector[i] << endl;
	}

	myVector.pop_back();
	cout << "���������� � ������� :" << myVector.size() << endl;
	for (int i = 0; i < myVector.size(); i++)
	{
		cout << myVector[i] << endl;
	}

	cout << "���������� � ������� :" << myVector.size() << endl;
	cout << "Capasity � ������� :" << myVector.capacity()<< endl;

	myVector.reserve(25);
	cout << "Capasity � ������� :" << myVector.capacity() << endl;
	system("pause");
}