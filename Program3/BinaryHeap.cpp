#pragma once
#include "BinaryHeap.h"
#include <iostream>

/* heap recovery */
void BinaryHeap::heapify(size_t index=0)
{
	int left, right;
	left = 2 * index + 1;
	right = 2 * index + 2;
	if (left < size) {
		if (heap[index] < heap[left])
			std::swap(heap[index], heap[left]);
		heapify(left);
	}
	if (right < size) {
		if (heap[index] < heap[right])
			std::swap(heap[index], heap[right]);
		heapify(right);
	}
}

BinaryHeap::BinaryHeap(int capacity=100)
{
	this->heap = new int[capacity];
	this->size = 0;
	this->capacity = capacity;
}

BinaryHeap::~BinaryHeap()
{
	delete[]heap;
}

/* search for an item in the heap by key */
bool BinaryHeap::contains(int key)
{
	if (this->size == 0)
		return false;
	for (size_t i = 0; i < this->size; i++)
		if (heap[i] == key)
			return true;
	return false;
}

/* adding an element to the tree by key */
void BinaryHeap::insert(int data)
{
	if (size == capacity) {
		capacity *= 100;
		int* temp = new int[capacity];
		for (int i = 0; i < size; i++)
			temp[i] = heap[i];
		delete[]heap;
		heap = temp;
	}
	heap[size] = data;
	sift_up(this->size);
	this->size++;
}

/* the removal of the tree element by key */
void BinaryHeap::remove(int key)
{
	if (this->size==0)
		throw "Error! Heap is empty.";
	int* new_heap = new int[this->size];
	int count = 0, new_heap_size = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (heap[i] != key)
		{
			new_heap[new_heap_size] = heap[i];
			new_heap_size++;
		}			
		else
		{
			count++;
		}
	}
	if (count != 0)
	{
		delete[] heap;
		heap = new_heap;
		this->size -= count;
	}
	else delete[] new_heap;
	for (size_t i = 0; i < this->size; i = 2 * i + 1)
		heapify();
}

void BinaryHeap::input_heap(int* heap, size_t size)
{
	for (size_t i = 0; i < size; i++)
		this->heap[i] = heap[i];
	this->size = size;
	for (size_t i = 0; i < size; i = 2 * i + 1)
		heapify();
}

void BinaryHeap::print_heap()
{
	int i = 0;
	int k = 1;
	while (i < this->size) {
		while ((i < k) && (i < this->size)) {
			std::cout << heap[i] << " ";
			i++;
		}
		std::cout << std::endl;
		k = k * 2 + 1;
	}
}

void BinaryHeap::sift_up(int index)
{
	while (heap[(index - 1) / 2] < heap[index])
	{
		std::swap(heap[index], heap[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}

Iterator* BinaryHeap::create_dft_iterator()
{
	return new dft_iterator(heap, size, 0);
}

Iterator* BinaryHeap::create_bft_iterator()
{
    return new bft_iterator(heap, size, 0);
}

BinaryHeap::bft_iterator::bft_iterator(int* cur,size_t size, size_t index = 0)
{
	current = cur;
	this->size = size;
	this->index = index;
}

BinaryHeap::bft_iterator::~bft_iterator()
{
	delete current;
}

int BinaryHeap::bft_iterator::next()
{
	if (!has_next())
		throw "No more elements in heap";
	this->index++;
	return current[index - 1];
}

bool BinaryHeap::bft_iterator::has_next()
{
	return index != this->size;
}

BinaryHeap::dft_iterator::dft_iterator(int* cur, size_t size, size_t index=0)
{
	current = cur;
	this->size = size;
	this->index = index;
}

BinaryHeap::dft_iterator::~dft_iterator()
{
	delete current;
}

int BinaryHeap::dft_iterator::next()
{
	if (!has_next()) {
		throw "No more elements in heap";
	}
	int temp = current[index];
	int child_right = index * 2 + 2, child_left = index * 2 + 1;
	if (index == 0) stack_right.push_back(0);
	if (child_right < size) {
		stack_right.push_back(child_right);
		index = child_left;
	}
	else if (child_left < size) index = child_left;
	else {
		if (stack_right.at(stack_right.GetSize() - 1) == 0) stack_right.pop_back();
		else {
			index = stack_right.at(stack_right.GetSize() - 1);
			stack_right.pop_back();
		}
		if (size == 1) index = -1;
	}

	return temp;
}

bool BinaryHeap::dft_iterator::has_next()
{
	if (size == 0) return false;
	if (index == 0) return true;
	if (stack_right.isEmpty() && index != 0) return false;
	else return true;
}