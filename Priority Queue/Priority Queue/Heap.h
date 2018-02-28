#pragma once

#include <iostream>
using namespace std;
enum
{
	HEAP_LEN = 100
};

typedef int T;
class CHeap
{
public:
	CHeap()
	{
		_numOfData = 0;
		memset(_HeapArr, 0, sizeof(T) * HEAP_LEN);
	}

	void Display()
	{
		for (int i = 1; i <= _numOfData; i++)
		{
			printf("%d\n", _HeapArr[i]);
		}
	}

	bool isHeapEmpty()
	{
		if (_numOfData == 0)
			return true;

		return false;
	}

	void Insert(T Data)
	{
		_numOfData++;

		_HeapArr[_numOfData] = Data; // Data 가 Key
		int i = _numOfData;

		while (i > 1 && _HeapArr[GetParentIndex(i)] < _HeapArr[i])
		{
			swap(_HeapArr[i], _HeapArr[GetParentIndex(i)]);
			i = GetParentIndex(i);
		}
		

	}
	bool DeleteElement(T *pOutNode)
	{
		if (_numOfData < 1)
			return false;

		*pOutNode = _HeapArr[1];
		_HeapArr[1] = _HeapArr[_numOfData];
		_HeapArr[_numOfData] = 0;
		_numOfData--;
		Max_heapify(1);

		return true;
	}
private:
	int GetParentIndex(int Index)
	{
		return Index / 2;
	}

	int GetLeftChildIndex(int Index)
	{
		return Index * 2;
	}

	int GetRightChildIndex(int Index)
	{
		return Index * 2 + 1;
	}
	void Max_heapify(int index)
	{
		if (index * 2 > _numOfData) // A[i]가 자식이 없다면
			return;

		int K; // 자식들중 가장 큰값

		if ((index * 2 + 1) > _numOfData)
			K = index * 2;
		else if (_HeapArr[index * 2] > _HeapArr[index * 2 + 1])
			K = index * 2;
		else
			K = index * 2 + 1;

		if (_HeapArr[index] >= _HeapArr[K])
			return;

		swap(_HeapArr[index], _HeapArr[K]);
		Max_heapify(K);
	}
private:
	int _numOfData;
	T _HeapArr[HEAP_LEN];
};