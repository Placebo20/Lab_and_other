#include <iostream>
#include<vector>
using std::cout;
using std::endl;
using std::cin;

class Date {
public:
	int day;
	int month;
	int year;
};

class List {
public:

	List();
	~List();

private:

	class Node {
	public:

		Node* pNext;

		Date object;

		Node(int day, int month, int year, Node* pNext = nullptr) {
			this->object.day = day;
			this->object.month = month;
			this->object.year = year;
		}
	};

	int Size;
	Node* head; //Указатель на первый элемент списка

public:

	void append(int day, int month, int year); // Добавляет элемент в конец списка
	Date get(int index); // Геттер структуры == элемента класса
	void set(int day, int month, int year, int index); // Сеттер структуры == элемента класса
	void create_empty(int value); // Создаёт пустой список размером value
	void insert(int day, int month, int year, int index); // Вставляет новый элемент по индексу index
	void remove(int index); // Удаляет элемент по индексу index
	Date length(); // Выводит список
	int GetSize() { return Size; } // Геттер размера списка
	void push_front(int day, int month, int year); // Добавляет элемент в начало списка
};


List::List()
{
	Size = 0;
	head = nullptr;
}


List::~List()
{
}


void List::append(int day, int month, int year) // Работает
{
	if (head == nullptr) {
		head = new Node(day, month, year);
		Size++;
	}
	else {
		Node* current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node(day, month, year);
		Size++;
	}
}


Date List::get(int index) //Работает
{
	int counter = 0;
	Node* current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			return current->object;
		}
		current = current->pNext;
		counter++;
	}
}


void List::set(int day, int month, int year, int index) //Работает
{
	int counter = 0;
	Node* current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			current->object.day = day;
			current->object.month = month;
			current->object.year = year;
		}
		current = current->pNext;
		counter++;
	}
}


void List::create_empty(int value) //Работает
{
	for (int i = 0; i < value; i++) {
		append(0, 0, 0);
	}
}

void List::push_front(int day, int month, int year) //Работает
{
	head = new Node(day, month, year, head);
	Size++;
}

void List::insert(int day, int month, int year, int index) //Не работает
{
	if (index == 0) {
		push_front(day,month,year);
	}
	else {
		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}

		previous->pNext = new Node(day, month, year, previous->pNext);
		Size++;
	}
}


void List::remove(int index) //Работает
{
	Node* previous = this->head;
	for (int i = 0; i < index - 1; i++) {
		previous = previous->pNext;
	}

	Node* toDelete = previous->pNext;
	previous->pNext = toDelete->pNext;
	delete toDelete;
	Size--;
}


Date List::length() //Работает
{
	cout << "Кол-во элементов в списке: " << Size << endl;
	int counter = 0;
	Node* current = this->head;
	while (current != nullptr) {
		return current->object;
		current = current->pNext;
		counter++;
	}
}


int main() {
	setlocale(LC_ALL, "Russian");
	List lst;
	Date tmp;
	int value;
	value = 10;


    for (int i = 0; i < lst.GetSize(); i++) {
		tmp = lst.get(i);
		cout << tmp.day << "/" << tmp.month << "/" << tmp.year << endl;
	}

	return 0;
}
