#pragma once

template<class T>
class CStack
{
private:
	struct Node
	{
		T Data;
		Node *pNextNode;
	};
public:
	CStack()
	{
		_Top = nullptr;
		_AllocCount = 0;
	}

	void Push(T Data)
	{
		Node *pNewNode = new Node;
		pNewNode->Data = Data;
		pNewNode->pNextNode = nullptr;

		if (_Top == nullptr)
			_Top = pNewNode;
		else
		{
			pNewNode->pNextNode = _Top;
			_Top = pNewNode;
		}

		_AllocCount++;
	}

	bool Pop(T *pOutData)
	{
		if (_Top == nullptr || pOutData == nullptr)
			return false;
		else
		{
			*pOutData = _Top->Data;

			Node *delNode = _Top;
			_Top = _Top->pNextNode;

			delete delNode;
			_AllocCount--;
			return true;
		}
	}
	bool Peek(T *pOutData)
	{
		if (_Top == nullptr || pOutData == nullptr)
			return false;
		else
		{
			*pOutData = _Top->Data;
			return true;
		}
	}

	int GetAllocCount()
	{
		return _AllocCount;

	}
private:
	Node* _Top;
	int _AllocCount;
};