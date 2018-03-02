#include "BinaryTree.h"

BSearchTree::BSearchTree()
{
	m_pRoot = nullptr;

	m_iNodeCount = 0;
}

BSearchTree::~BSearchTree()
{
	ReleaseTree();
}

bool BSearchTree::InsertNode(int iData)
{
	st_TNODE *pNode = new st_TNODE;
	pNode->iData = iData;
	pNode->pLeft = nullptr;
	pNode->pRight = nullptr;

	if (m_pRoot == nullptr)
	{
		m_pRoot = pNode;
	}
	else
	{
		if (!linkNode(m_pRoot, pNode))
			return false;
	}

	m_iNodeCount++;

	return true;
}

bool BSearchTree::linkNode(st_TNODE *pParent, st_TNODE *pChild)
{
	// 1. pParent�� pChild�� �� �Ѵ�.
	// ũ�ٸ� ->, �۴ٸ� <-

	if (pParent->iData < pChild->iData)
	{
		if (pParent->pRight == nullptr)
		{
			pParent->pRight = pChild;
			return true;
		}
		else
			linkNode(pParent->pRight, pChild);
	}
	else
	{
		if (pParent->pLeft == nullptr)
		{
			pParent->pLeft = pChild;
			return true;
		}
		else
			linkNode(pParent->pLeft, pChild);
	}
}

st_TNODE* BSearchTree::SearchNode(int iData)
{
	if (m_pRoot == nullptr)
		return nullptr;

	st_TNODE *pNode = m_pRoot;

	if (pNode->iData == iData)
		return pNode;

	return findNode(pNode, iData);
}

st_TNODE*	BSearchTree::findNode(st_TNODE *pNode, int iData)
{
	if (pNode->iData == iData)
		return pNode;

	if (pNode == nullptr)
		return nullptr;

	if (pNode->iData > iData)
		return findNode(pNode->pLeft, iData);
	else
		return findNode(pNode->pRight, iData);
}

bool BSearchTree::DeleteNode(int iData)
{
	/*
		1. ������ ��尡 �ܸ� ����� ���
		2. ������ ��尡 �ϳ��� �ڽ� ���(�ϳ��� ����Ʈ��)�� ���� ���
		3. ������ ��尡 �ΰ��� �ڽĳ��(�ΰ��� ����Ʈ��)�� ���� ���
	*/

	if (m_pRoot == nullptr)
		return false;

	if (deleteNode(m_pRoot, nullptr, iData) != nullptr)
	{
		m_iNodeCount--;
		return true;
	}

	return false;
}


st_TNODE*	BSearchTree::deleteNode(st_TNODE *pNode, st_TNODE *pParent, int iData)
{
	if (pNode->iData == iData)
	{
		// 1. ������ ��尡 �ܸ� ����� ���
		if (isNil(pNode))
		{
			// �׳� �����Ѵ�.
			if (pParent->pLeft == pNode)
				pParent->pLeft = nullptr;
			else
				pParent->pRight = nullptr;

			return pNode;
		}
		// 2. ����Ʈ���� �ϳ��� �ִٸ�
		else if (isOneSubTree(pNode))
		{
			// �������� �����Ѵ�.
			bool left = (pNode->pLeft != nullptr);
			bool right = (pNode->pRight != nullptr);

			if (left)
			{
				if (pParent->pLeft == pNode)
					pParent->pLeft = pNode->pLeft;
				else
					pParent->pRight = pNode->pLeft;
			}
			else
			{
				if (pParent->pLeft == pNode)
					pParent->pLeft = pNode->pRight;
				else
					pParent->pRight = pNode->pRight;
			}
		}
		else
		{
			// 3. �ΰ� ����Ʈ���� �ִٸ�

			// 1. ���� ����Ʈ������ ���� ū���� �ٲ۴�.
			// �̰�� �ѹ� �������� ���ٰ� �� ���������� ����ȴ�.
			// 2. ������ ����Ʈ������ ���� �������� �ٲ۴�.
			// �̰�� �ѹ� ���������� ���ٰ� �� �������� ����ȴ�.
			st_TNODE *pBiggestParent = pNode;
			st_TNODE *pBiggestNode = pNode->pLeft;

			while (pBiggestNode->pRight == nullptr)
			{
				pBiggestParent = pBiggestNode;
				pBiggestNode = pBiggestNode->pRight;
			}

			// pNode�� ������
			pNode->iData = pBiggestNode->iData;
			if (pBiggestParent->pLeft == pBiggestNode)
				pBiggestParent->pLeft = nullptr;
			else
				pBiggestParent->pRight = nullptr;

		}
	}
	else
	{
		// Ž�� ���
		if (pNode->iData < iData)
			deleteNode(pNode->pRight, pNode, iData);
		else
			deleteNode(pNode->pLeft, pNode, iData);

	}
}


bool		BSearchTree::ReleaseTree(void)
{
	if (m_pRoot == nullptr)
		return false;

	releaseNode(m_pRoot);
}

void	BSearchTree::releaseNode(st_TNODE *pNode)
{
	if (pNode == nullptr)
		return;

	releaseNode(pNode->pLeft);
	releaseNode(pNode->pRight);

	delete pNode;
}

void		BSearchTree::PreorderPrint(st_TNODE *pNode, int iDepth , int iLR )
{
	if (pNode == nullptr && iDepth > 0)
		return;

	if (pNode == nullptr && iDepth == 0)
		pNode = m_pRoot;

	cout << pNode->iData << endl;
	PreorderPrint(pNode->pLeft, iDepth + 1, 1);
	PreorderPrint(pNode->pRight, iDepth+ 1, 2);

}