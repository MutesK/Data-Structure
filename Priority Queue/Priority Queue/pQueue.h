#pragma once

#include "Heap.h"

class CPriorityQueue
{
public:
	CPriorityQueue()
	{

	}

	bool IsQueueEmpry()
	{
		return pQueue.isHeapEmpty();
	}
	
	void Enqueue(int Data)
	{
		pQueue.Insert(Data);
	}
	bool Dequeue(int *pOutData)
	{
		return pQueue.DeleteElement(pOutData);
	}

	void Display()
	{
		pQueue.Display();
	}
private:
	CHeap pQueue;
};