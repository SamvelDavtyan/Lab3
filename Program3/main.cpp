#include "BinaryHeap.h"
#include <iostream>


using namespace std;

int main()
{
	BinaryHeap HEAP(100);
	
	int arr[7] = { 1,2,3,4,5,6,7 };
	HEAP.input_heap(arr, 7);
	HEAP.print_heap();
	HEAP.insert(10);
	HEAP.print_heap();

	return 0;
}