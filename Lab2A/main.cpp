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
	Node* head; //��������� �� ������ ������� ������

public:

	void append(int day, int month, int year); // ��������� ������� � ����� ������
	Date get(int index); // ������ ��������� == �������� ������
	void set(int day, int month, int year, int index); // ������ ��������� == �������� ������
	void create_empty(int value); // ������ ������ ������ �������� value
	void insert(int day, int month, int year, int index); // ��������� ����� ������� �� ������� index
	void remove(int index); // ������� ������� �� ������� index
	Date length(); // ������� ������
	int GetSize() { return Size; } // ������ ������� ������
	void push_front(int day, int month, int year); // ��������� ������� � ������ ������
};


List::List()
{
	Size = 0;
	head = nullptr;
}


List::~List()
{
}


void List::append(int day, int month, int year) // ��������
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


Date List::get(int index) //��������
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


void List::set(int day, int month, int year, int index) //��������
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


void List::create_empty(int value) //��������
{
	for (int i = 0; i < value; i++) {
		append(0, 0, 0);
	}
}

void List::push_front(int day, int month, int year) //��������
{
	head = new Node(day, month, year, head);
	Size++;
}

void List::insert(int day, int month, int year, int index) //�� ��������
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


void List::remove(int index) //��������
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


Date List::length() //��������
{
	cout << "���-�� ��������� � ������: " << Size << endl;
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
