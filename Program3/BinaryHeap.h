#pragma once
#include "Iterator.h"
#include "List.h"

class BinaryHeap
{
private:
	int* heap;
	size_t size;
	size_t capacity;
	
public:
	BinaryHeap(int capacity);
	~BinaryHeap();

	bool contains(int);
	void insert(int);
	void remove(int);
	void heapify(size_t);
	void input_heap(int*, size_t);
	void print_heap();
	void sift_up(int );


	Iterator* create_dft_iterator();
	Iterator* create_bft_iterator();

	class bft_iterator : public Iterator
	{
	public:
		bft_iterator(int*, size_t, size_t);
		~bft_iterator();
		int next() override;
		bool has_next() override;

	private:
		int* current;
		size_t index;
		size_t size;
	};

	class dft_iterator : public Iterator
	{
	public:
		dft_iterator(int*, size_t, size_t);
		~dft_iterator();
		int next() override;
		bool has_next() override;
	private:
		int* current;
		size_t index;
		size_t size;
		List stack_right;
	};
};