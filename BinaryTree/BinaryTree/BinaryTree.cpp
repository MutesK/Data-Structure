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
	// 1. pParent와 pChild을 비교 한다.
	// 크다면 ->, 작다면 <-

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
		1. 삭제할 노드가 단말 노드인 경우
		2. 삭제할 노드가 하나의 자식 노드(하나의 서브트리)를 갖는 경우
		3. 삭제할 노드가 두개의 자식노드(두개의 서브트리)를 갖는 경우
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
		// 1. 삭제할 노드가 단말 노드인 경우
		if (isNil(pNode))
		{
			// 그냥 삭제한다.
			if (pParent->pLeft == pNode)
				pParent->pLeft = nullptr;
			else
				pParent->pRight = nullptr;

			return pNode;
		}
		// 2. 서브트리가 하나만 있다면
		else if (isOneSubTree(pNode))
		{
			// 한쪽으로 연결한다.
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
			// 3. 두개 서브트리가 있다면

			// 1. 왼쪽 서브트리에서 가장 큰값과 바꾼다.
			// 이경우 한번 왼쪽으로 갔다가 쭉 오른쪽으로 가면된다.
			// 2. 오른쪽 서브트리에서 가장 작은값과 바꾼다.
			// 이경우 한번 오른쪽으로 갔다가 쭉 왼쪽으로 가면된다.
			st_TNODE *pBiggestParent = pNode;
			st_TNODE *pBiggestNode = pNode->pLeft;

			while (pBiggestNode->pRight == nullptr)
			{
				pBiggestParent = pBiggestNode;
				pBiggestNode = pBiggestNode->pRight;
			}

			// pNode와 값변경
			pNode->iData = pBiggestNode->iData;
			if (pBiggestParent->pLeft == pBiggestNode)
				pBiggestParent->pLeft = nullptr;
			else
				pBiggestParent->pRight = nullptr;

		}
	}
	else
	{
		// 탐색 모드
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