#include "List.h"

// constructor
List::List()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

// copy constructor
List::List(const List &lst)
{
	size = 0;
	head = nullptr;
	tail = nullptr;
	Node* temp = lst.head;
	for (int i = 0; i < lst.size; i++)
	{
		push_back(temp->data);
		temp = temp->next;
	}
}

// destructor
List::~List()
{
	clear();
}

// inserting an element at the end of the list
void List::push_back(int data)
{
	if (head == nullptr)
	{
		this->head = this->tail = new Node(data);
	}
	else
	{
		Node* temp = new Node(data, nullptr, tail);
		tail->next = temp;
		tail = temp;
	}
	size++;
}

// inserting an element at the beginning of the list
void List::push_front(int data)
{
	if (!(isEmpty()))
	{
		Node* lasthead = head;
		head = new Node(data, head);
		lasthead->prev = head;
	}
	else
	{
		head = new Node(data, head);
	}
	size++;
}

// remove the last element
void List::pop_back()
{
	if (isEmpty())
		throw "Error! Linked list is Empty.";
	else
	{
		Node* todelete = tail;
		tail = tail->prev;
		delete todelete;
		size--;
	}
}

// remove the first element
void List::pop_front()
{
	if (head != nullptr) {
		Node* temp = this->head;
		head = head->next;
		delete temp;
		size--;
	}
	else throw "Error! Linked list is Empty.";
}

// insert into an arbitrary place in the list by index
void List::insert(size_t index, int data)
{
	if (!isEmpty())
	{
		if (index >= size || index < 0)
			throw "Error! Incorrect input.";
	}
	else
	{
		if (index != size)
			throw "Error! Incorrect input.";
	}
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		if (index == size)
			push_back(data);
		else {
			if (index < (size - 1) / 2)
			{
				Node* previous = this->head;
				for (size_t i = 0; i < index - 1; i++)
				{
					previous = previous->next;
				}
				previous->next = new Node(data, previous->next, previous);
			}
			else
			{
				Node* previous = this->tail;
				for (size_t i = size - 1; i > index - 1; i--)
				{
					previous = previous->prev;
				}
				previous->next = new Node(data, previous->next, previous);
			}
			size++;
		}
	}
}


// deleting an element by index
void List::remove(size_t index)
{
	if (index >= size || index < 0)
		throw "Error! Incorrect input.";
	if (index == 0)
		pop_front();
	else
	{
		if (index < (size - 1) / 2)
		{
			Node* previous = this->head;
			for (size_t i = 0; i < index - 1; i++)
			{
				previous = previous->next;
			}
			Node* todelete = previous->next;
			previous->next = todelete->next;
			delete todelete;
		}
		else
		{
			Node* previous = this->tail;
			for (size_t i = size - 1; i >= index; i--)
			{
				previous = previous->prev;
			}
			Node* todelete = previous->next;
			previous->next = todelete->next;
			delete todelete;
		}
		size--;
	}
}

// clear list
void List::clear()
{
	while (size) {
		pop_front();
	}
}

// output the list to the console
void List::print_to_console()
{
	if (isEmpty())
		throw "Linked List is empty.\n";
	else
	{
		Node* current = head;			
		for (int i = 0; i < GetSize()-1; i++)
		{
			std::cout << current->data << " - ";
			current = current->next;
		}
		std::cout << current->data;	
	}
}

// getting list size
size_t List::GetSize()
{
	return size;
}

// getting an element by index
int List::at(const int index)
{
	if (index >= size || index < 0)
		throw "Error! Incorrect input.";
	int counter = 0;
	Node* current = head;
	while (current != nullptr)
	{
		if (counter == index)
			return current->data;
		current = current->next;
		counter++;
	}
}

// replacing the element by index with the passed element
void List::set(size_t index, int data) 
{
	if (index >= size || index < 0)
		throw "Error! Incorrect input.";
	if (index == 0)
	{
		pop_front();
		push_front(data);
	}
	else
	{
		if (index < (size - 1) / 2)
		{
			Node* previous = this->head;
			for (size_t i = 0; i < index - 1; i++)
			{
				previous = previous->next;
			}
			Node* todelete = previous->next;
			previous->next = todelete->next;
			delete todelete;
			previous->next = new Node(data, previous->next, previous);
		}
		else
		{
			Node* previous = this->tail;
			for (size_t i = size - 1; i >= index; i--)
			{
				previous = previous->prev;
			}
			Node* todelete = previous->next;
			previous->next = todelete->next;
			delete todelete;
			previous->next = new Node(data, previous->next, previous);
		}
		
	}
}

// checking the list for emptiness
bool List::isEmpty()
{
	if (head == nullptr)
		return true;
	else return false;
}


// insert at the beginning of the list of another list
void List::push_front(List lst)
{
	if (!isEmpty() && lst.isEmpty())
		throw "Error! Inserting an empty list at the beginning is not possible.";
	Node* temp = lst.tail;
	for (size_t i = 0; i < lst.GetSize(); i++) {
		this->push_front(temp->data);
		temp = temp->prev;
	}
}