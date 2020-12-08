#include "pch.h"
#include "CppUnitTest.h"
#include "..\Program3\List.cpp"
#include "..\Program3\BinaryHeap.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab3
{
	TEST_CLASS(UnitTestlab3)
	{
	public:
		TEST_METHOD(Input_heapTest)
		{
			BinaryHeap heap(10);
			int arr[5] = { 1,2,3,4,5 };
			heap.input_heap(arr, 5);
			for (size_t i = 0; i < 5; i++)
				Assert::AreEqual(heap.contains(arr[i]), true);
		}
		TEST_METHOD(ContainsTest1)
		{
			int arr[5] = { 1,2,3,4,5 };
			BinaryHeap heap(10);
			heap.input_heap(arr, 5);
			Assert::IsTrue(heap.contains(3));
		}
		TEST_METHOD(ContainsTest2)
		{
			int arr[5] = { 1,2,3,4,5 };
			BinaryHeap heap(10);
			heap.input_heap(arr, 5);
			Assert::IsTrue(heap.contains(21) == false);
		}
		TEST_METHOD(ContainsTest3)
		{
			BinaryHeap heap;
			Assert::IsTrue(heap.contains(5) == false);
		}
		TEST_METHOD(InsertTest1)
		{
			int arr[5] = { 1,2,3,5,6 };
			BinaryHeap heap;
			heap.input_heap(arr, 5);
			heap.insert(4);
			Assert::IsTrue(heap.contains(4));
		}
		TEST_METHOD(InsertTest2)
		{
			BinaryHeap heap;
			heap.insert(1);
			Assert::IsTrue(heap.contains(1));
		}
		TEST_METHOD(RemoveTest1)
		{
			int arr[5] = { 1,2,3,4,5 };
			BinaryHeap heap;
			heap.input_heap(arr, 5);
			heap.remove(4);
			Assert::IsTrue(heap.contains(4)==false);
		}
		TEST_METHOD(RemoveTest2)
		{
			BinaryHeap heap;
			try
			{
				heap.remove(4);
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Error! Heap is empty.");
			}
		}
		TEST_METHOD(BFT_Iterator_Test1)
		{
			BinaryHeap heap;
			int arr[7] = { 7,4,6,1,3,2,5 };
			heap.input_heap(arr, 7);
			Iterator* Iter = heap.create_bft_iterator();
			for (size_t i = 0; i < 7; i++)
				Assert::IsTrue(Iter->next() == arr[i]);
		}
		TEST_METHOD(BFT_Iterator_Test2)
		{
			BinaryHeap heap;
			Iterator* Iter = heap.create_bft_iterator();
			try
			{
				Iter->next();
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "No more elements in heap");
			}
		}
		TEST_METHOD(DFT_Iterator_Test1)
		{
			BinaryHeap heap;
			int arr[7] = { 7,4,6,1,3,2,5 };
			int control[7] = { 7,4,1,3,6,2,5 };
			heap.input_heap(arr, 7);
			Iterator* Iter = heap.create_dft_iterator();
			for (size_t i = 0; i < 7; i++)
				Assert::IsTrue(Iter->next() == control[i]);
		}
		TEST_METHOD(DFT_Iterator_Test2)
		{
			BinaryHeap heap;
			Iterator* Iter = heap.create_dft_iterator();
			try
			{
				Iter->next();
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "No more elements in heap");
			}
		}
	};
}
