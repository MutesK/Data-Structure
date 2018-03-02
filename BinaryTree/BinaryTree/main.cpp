#include "BinaryTree.h"
#include <stdlib.h>
#include <conio.h>
int main()
{
	BSearchTree Tree;

	Tree.InsertNode(10);
	Tree.InsertNode(11);
	Tree.InsertNode(12);
	Tree.InsertNode(5);
	Tree.InsertNode(6);

	Tree.PreorderPrint();
	printf("10,11,12,5,6 Node Insert\n\n");

	_getch();
	return 0;
}