#include <iostream>
#include <ctime>

using namespace std;


int Foo(int a)
{
	if (a<1)
	{
		return 0;
	}

	a--;
	
	return Foo(a);
}



int Factorial(int a)
{
	if (a==0)
	{
		return 0;
	}
	else if(a==1)
	{
		return 1;
	}
	return a*Factorial(a - 1);
}

int main()
{
	setlocale(LC_ALL, "ru");
	//Foo(10);
	cout << "Factorial=" << Factorial(5) << endl;
	system("pause");
	return 0;
}