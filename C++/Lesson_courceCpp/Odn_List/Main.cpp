#include <iostream>
#include <ctime>
#include <string.h>
#include <string>
using namespace std;

/*--------------------Односвязные списки----------------*/
template<typename T>
class  List
{
public:
	 List();
	~ List();
	void Clear();
	void pop_front();
	void push_front(T data);
	void insert(T value, int index);
	void RemoveAt(int index);
	void pop_back();
	int GetSize() { return Size; }
	T& operator[](const int index);

	void push_back(T data);

private:
	template<typename T>
	class Node
	{
	public:
		Node *pNext;
		T data;
		Node(T data=T(), Node *Next=nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T> *head;

};

template<typename T>
 List<T>:: List()
{
	 Size = 0;
	 head = nullptr;
}

 template<typename T>
 List<T>::~ List()
{
	 cout << "ВЫполнился деструктор!!!" << endl;
	 Clear();
}

 template<typename T>
 void List<T>::Clear()
 {
	 while (Size)
	 {
		 pop_front();
	 }
 }

 /***************Удаление первого элемента*************/
 template<typename T>
 void List<T>::pop_front()
 {
	 Node<T> *temp = head;

	 head = head->pNext;
	 delete temp;
	 Size--;
 }

 /*=================добавление в начало списка***************/
 template<typename T>
 void List<T>::push_front(T data)
 {
	 head = new Node<T>(data,head);
	 Size++;

 }

 /****************Вставка по индексу *********************/
 template<typename T>
 void List<T>::insert(T value, int index)
 {
	 if (index==0)
	 {
		 push_front(value);
	 }
	 else
	 {
		 Node<T> *previous = this->head;
		 for (int i = 0; i < index - 1; i++)
		 {
			 previous = previous->pNext;
		 }
		 Node<T> *newMode = new Node<T>(data, previous->pNext);

		 previous->pNext = newMode;

		 Size++;

	 }
	 
 }

 /*****************Удаление по заданному индексу***************/
 template<typename T>
 void List<T>::RemoveAt(int index)
 {
	 if (index==0)
	 {
		 pop_front();
	 }
	 else
	 {
		 Node<T> *previus = this->head;
		 for (int i = 0; i < index - 1; i++)
		 {
			 previus = previus->pNext;
		 }
		 Node<T> *toDelete = previus->pNext;
		 previus->pNext = toDelete->pNext;

		 delete toDelete;
		 Size--;
	 }
 }

 /*******************Удаление последнего элемента в списке***************/
 template<typename T>
 void List<T>::pop_back()
 {
	 RemoveAt(Size - 1);
 }


 /*********************Обращение по индекусе к элементу списка************/
 template<typename T>
 T & List<T>::operator[](const int index)
 {
	 int counter = 0;
	 Node<T> *current = this->head;
	 while (current!=nullptr)
	 {
		 if (counter == index)
		 {
			 return current->data;
		 }
		 current = current->pNext;
		 counter++;
	 }
 }



 /*****************Добавление элемента в конец списка***************/
 template<typename T>
 void List<T>::push_back(T data)
 {
	 if (head == nullptr)
	 {
		 head = new Node<T>(data);

	 }
	 else
	 {
		 Node<T> *current = this->head;
		 while (current->pNext!=nullptr)
		 {
			 current = current->pNext;
		 }
		 current->pNext = new Node<T>(data);
	 }

	 Size++;
 }


/******************************************************/
void main()
{
	setlocale(LC_ALL, "ru");
	List<int>lst;
	lst.push_back(5);
	lst.push_back(12);
	lst.push_back(22);
	cout << "Количество элементов: " << lst.GetSize()<<endl;
	

	for (int i = 0; i <lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	
	//=================================================
	/*List<int> data;
	int N;
	cout << "Введите количество элементов: ";
	cin >> N;
	for (int  i = 0; i < N; i++)
	{
		data.push_back(rand() % 10);
	}

	for (int i = 0; i < data.GetSize(); i++)
	{
		cout << data[i]<<endl;
	}*/

	system("pause");

}