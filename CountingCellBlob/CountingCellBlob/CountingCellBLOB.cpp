#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

enum
{
	en_HEIGHT = 8,
	en_WIDTH = 8,

	en_BACKGROUNDPIXEL = 0,
	en_IMAGEPIXEL = 1,

	en_CHECK = 5 // 1 Step Check  Next Step = enCheck + 1;
};
char map[en_HEIGHT][en_WIDTH] = {
	{ 1,0,0,0,0,0,0,1 },
	{ 0,1,1,0,0,1,0,0 },
	{1,1,0,0,1,0,1,0},
	{0,0,0,0,0,1,0,0},
	{0,1,0,1,0,1,0,0},
	{0,1,0,1,0,1,0,0},
	{1,0,0,0,1,0,0,1},
	{0,1,1,0,0,1,1,1}
};

struct Cell
{
	bool isUse;

	int numOfPixel;
	int CellNumber;
};

Cell Cells[1000];

// ¼¿ÀÇ °¹¼ö, ¼¿ÀÇ ±×·ì °¹¼ö, XÁÂÇ¥, YÁÂÇ¥
void Display()
{
	system("cls");
	for (int i = 0; i < en_HEIGHT; i++)
	{
		for (int j = 0; j < en_WIDTH; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}
int Traversal(bool travelMode, int CellGroupCount, int Xpos, int Ypos);
void CountCell()
{
	// ÇöÀçÀ§Ä¡°¡ en_IMAGEPIXELÀÌ¶ó¸é  ÀÎÁ¢ ¼¿¿¡ ´ëÇØ¼­¸¸ DFS Å½»ö ½ÃÀÛÇÑ´Ù.
	int Xpos = 0, Ypos = 0, CellGroupCount= 0;

	for (Ypos = 0; Ypos < en_HEIGHT; Ypos++)
	{
		for (Xpos = 0; Xpos < en_WIDTH; Xpos++)
		{
			int check = Traversal(false, CellGroupCount, Xpos, Ypos);

			if (check > 0)
				CellGroupCount++;
		}
	}


	// Display
	for (auto iter : Cells)
	{
		if (iter.isUse)
		{
			cout << "Cell Number : " << iter.CellNumber << endl;
			cout << "Num of Pixel : " << iter.numOfPixel << endl;
		}
	}
}

int Traversal(bool travelMode, int CellGroupCount, int Xpos, int Ypos)
{
	if (Xpos < 0 || Xpos >= en_HEIGHT)
		return 0;

	if (Ypos < 0 || Ypos >= en_WIDTH)
		return 0;

	if (map[Ypos][Xpos] == en_IMAGEPIXEL)
	{
		map[Ypos][Xpos] = en_CHECK + CellGroupCount;
		Display();
		Sleep(100);

		if (Cells[CellGroupCount].isUse == false)
			Cells[CellGroupCount].isUse = true;

		Cells[CellGroupCount].numOfPixel++;
		Cells[CellGroupCount].CellNumber = CellGroupCount;

		// 8¹æÇâÀ¸·Î Àç±Í
		int retval = 1;

		retval += Traversal(true, CellGroupCount, Xpos - 1, Ypos - 1);
		retval += Traversal(true, CellGroupCount, Xpos, Ypos - 1);
		retval += Traversal(true, CellGroupCount, Xpos + 1, Ypos - 1);
		retval += Traversal(true, CellGroupCount, Xpos - 1, Ypos);
		retval += Traversal(true, CellGroupCount, Xpos + 1, Ypos);
		retval += Traversal(true, CellGroupCount, Xpos - 1, Ypos + 1);
		retval += Traversal(true, CellGroupCount, Xpos, Ypos + 1);
		retval += Traversal(true, CellGroupCount, Xpos + 1, Ypos + 1);

		return retval;
	}
	else
	{
		return 0;
	}
}
int main()
{
	CountCell();

	return 0;
}