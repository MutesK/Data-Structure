#pragma once

template<class T>
class CQueue
{
private:
	struct Node
	{
		T Data;
		Node *pNextNode;
	};
public:
	CQueue()
	{
		_front = _rear = nullptr;
		_allocCount = 0;
	}

	void Enqueue(T Data)
	{
		Node *pNewNode = new Node;
		pNewNode->Data = Data;
		pNewNode->pNextNode = nullptr;

		if (_rear == nullptr)
		{
			_front = pNewNode;
			_rear = pNewNode;
		}
		else
		{
			_rear->pNextNode = pNewNode;
			_rear = pNewNode;
		}

		_allocCount++;
	}
	bool Dequeue(T *pOutData)
	{
		if (_front == nullptr || pOutData == nullptr)
			return false;

		Node *DelNode = _front;
		*pOutData = _front->Data;
		
		_front = _front->pNextNode;
		delete DelNode;

		_allocCount--;

		if (_front == nullptr)
			_rear = nullptr;

		return true;
	}

	bool Peek(T *pOutData)
	{
		if (_front == nullptr || pOutData == nullptr)
			return false;

		*pOutData = _front->Data;
		return true;
	}
	
	bool Peek(T *pOutData, int PeekSize)
	{
		if (_front == nullptr || pOutData == nullptr)
			return false;

		int Travel = 0;
		Node *pTravelNode = _front;
		
		while (pTravelNode != nullptr)
		{
			if (Travel == PeekSize)
				break;

			pTravelNode = pTravelNode->pNextNode;
			Travel++;
		}

		if (Travel == PeekSize)
		{
			*pOutData = pTravelNode->Data;
			return true;
		}

		return false;
	}

	int GetAllocCount()
	{
		return _allocCount;

	}
private:
	Node *_front;
	Node *_rear;
	int _allocCount;
};