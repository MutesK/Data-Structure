#pragma once

#include <iostream>
using namespace std;

struct st_TNODE
{
	struct st_TNODE *pLeft;
	struct st_TNODE *pRight;

	int iData;
};


class BSearchTree
{
public:

	BSearchTree();
	~BSearchTree();

	//------------------------------------------------------
	// ���ο� �����͸� �߰��Ѵ�.
	//------------------------------------------------------
	bool		InsertNode(int iData);
	//------------------------------------------------------
	// Ư�� �����͸� �����Ѵ�.
	//------------------------------------------------------
	bool		DeleteNode(int iData);

	//------------------------------------------------------
	// Ư�� �����͸� �˻��Ͽ� ��� ����
	//------------------------------------------------------
	st_TNODE	*SearchNode(int iData);

	//------------------------------------------------------
	// Ʈ�� ��ü ����
	//------------------------------------------------------
	bool		ReleaseTree(void);

	//------------------------------------------------------
	// ������ȸ ��� ���
	//------------------------------------------------------
	void		PreorderPrint(st_TNODE *pNode = NULL, int iDepth = 0, int iLR = 0);



private:

	//------------------------------------------------------
	// InsertNode ���ο��� ȣ��Ǵ� ��ġ ã�� �߰� ��� �Լ�
	//------------------------------------------------------
	bool		linkNode(st_TNODE *pParent, st_TNODE *pChild);

	//------------------------------------------------------
	// SearchNode ���ο��� ȣ��Ǵ� ���ã�� ����Լ�
	//------------------------------------------------------
	st_TNODE *	findNode(st_TNODE *pNode, int iData);

	//------------------------------------------------------
	// DeleteNode ���ο��� ȣ��Ǵ� ���ã�� & ���� & ��ó�� ����Լ�
	//------------------------------------------------------
	st_TNODE *	deleteNode(st_TNODE *pNode, st_TNODE *pParent, int iData);

	//------------------------------------------------------
	// ReleaseTree ���ο��� ȣ��Ǵ� ���ã�� ����Լ�
	//------------------------------------------------------
	void		releaseNode(st_TNODE *pNode);


	bool isNil(st_TNODE *pNode)
	{
		if (pNode->pLeft == nullptr && pNode->pRight == nullptr)
			return true;

		return false;
	}
	
	bool isOneSubTree(st_TNODE *pNode)
	{
		bool left = (pNode->pLeft != nullptr);
		bool right = (pNode->pRight != nullptr);

		if (left && right)
			return false;

		return true;
	}


	st_TNODE	*m_pRoot;

	int			m_iNodeCount;

};