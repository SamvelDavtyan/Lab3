#pragma once
#include <iostream>

class List
{
public:
	List();
	List(const List &lst);
	~List();
	void push_back(int data);
	void push_front(int data);
	void pop_back();
	void pop_front();
	void insert(size_t index, int data);
	void remove(size_t index);
	void clear();
	void print_to_console();
	size_t GetSize();
	int at(const int index);
	void set(size_t index, int data);
	bool isEmpty();
	void push_front(List lst);
private:

	class Node
	{
	public:
		Node* next;
		Node* prev;
		int data;
		Node(int data = 0, Node* next = nullptr, Node* prev =nullptr)
		{
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
	};
	Node* head;
	Node* tail;
	size_t size;
};
