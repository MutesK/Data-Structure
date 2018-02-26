#pragma once

struct Node
{
	int Data;
	struct Node *pNext;
};


class CLinkedList
{
public:
	CLinkedList()
	{
		pTail = nullptr;
		pHead = nullptr;

		countData = 0;
	}

	void push_back(int Data)
	{
		Node *pNode = new Node;
		pNode->Data = Data;
		pNode->pNext = nullptr;

		if (pTail == nullptr)
		{
			pHead = pNode;
			pTail = pNode;
		}
		else
		{
			pTail->pNext = pNode;
			pTail = pNode;
		}

		countData++;
	}

	int pop_back()
	{
		if (pTail == nullptr)
			return -1;

		int ret = pTail->Data;
		Node *pFindNode = pHead;

		while (pFindNode->pNext != pTail)
			pFindNode = pFindNode->pNext;

		delete pTail;
		pTail = pFindNode;
		pTail->pNext = nullptr;

		countData--;
		return ret;
	}

	void push_front(int Data)
	{
		Node *pNode = new Node;
		pNode->Data = Data;
		pNode->pNext = nullptr;

		if (pHead == nullptr)
		{
			pHead = pNode;
			pTail = pNode;
		}
		else
		{
			pNode->pNext = pHead;
			pHead = pNode;
		}

		countData++;
	}

	int pop_front()
	{
		if (pHead == nullptr)
			return -1;

		int ret = pHead->Data;
		Node *delNode = pHead;

		pHead = pHead->pNext;
		delete delNode;
		
		countData--;
		return ret;
	}

private:
	Node *pHead;
	Node *pTail;

	int countData;
};