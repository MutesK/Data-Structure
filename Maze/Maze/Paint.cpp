#include <iostream>
#include <Windows.h>
#include "Stack.h"
#include "Queue.h"
using namespace std;

enum {
	MAP_HEIGHT = 10,
	MAP_WIDTH = 20
};

struct Point
{
	int X;
	int Y;
};

char originalMap[MAP_HEIGHT][MAP_WIDTH] = {
	{ ' ',' ' ,'0' ,' ' ,' ' ,' ' ,' ' ,' ' ,'0' ,'0' ,'0' ,'0' ,' ' ,' ' ,' ' ,'0' ,'0' ,'0' ,'0' ,'0' },
	{ ' ','0' ,'0' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,'0' ,' ' ,' ' ,' ' ,'0' ,' ' ,' ' ,' ' ,' ' },
	{ ' ','0' ,'0' ,' ' ,' ' ,'0' ,'0' ,' ' ,' ' ,' ' ,' ' ,'0' ,' ' ,' ' ,' ' ,'0' ,' ' ,' ' ,'0' ,' ' },
	{ ' ','0' ,'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,' ' ,' ' ,' ' ,'0' ,' ' ,' ' ,'0' ,' ' },
	{ ' ','0' ,'0' ,' ' ,' ' ,' ' ,' ' ,'0' ,' ' ,' ' ,' ' ,'0' ,'0' ,' ' ,' ' ,'0' ,' ' ,'0' ,'0' ,'0' },
	{ '0','0' ,' ' ,' ' ,' ' ,' ' ,' ' ,'0' ,' ' ,'0' ,'0' ,' ' ,' ' ,' ' ,' ' ,'0' ,' ' ,'0' ,'0' ,'0' },
	{ '0','0' ,' ' ,'0' ,'0' ,' ' ,' ' ,'0' ,' ' ,'0' ,' ' ,' ' ,' ' ,' ' ,' ' ,'0' ,' ' ,'0' ,'0' ,'0' },
	{ '0','0' ,' ' ,' ' ,'0' ,' ' ,' ' ,'0' ,' ' ,'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,' ' ,'0' ,'0' ,'0' },
	{ '0','0' ,'0' ,'0' ,'0' ,' ' ,'0' ,'0' ,'0' ,'0' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,'0' ,'0' ,'0' },
	{ ' ',' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' },
};

char Buffer[MAP_HEIGHT][MAP_WIDTH];
CStack<Point> Stack;
CQueue<Point> Queue;
void printMap();
void RecursiveSolveMaze(int x, int y);  // 깊이 우선 탐색
void StackSloveMaze(int x, int y);  // 깊이 우선탐색
void QueueSloveMaze(int x, int y); // using BFS 너비 우선 탐색
int main()
{
	while (1)
	{
		cout << "#1 Recursive Method \n";
		memcpy(Buffer, originalMap, sizeof(originalMap));
		printMap();
		RecursiveSolveMaze(1, 1);
		cout << "Recursive Method Complete Wait 5sec For Next Method(Stack Method) \n";

		Sleep(5000);

		memcpy(Buffer, originalMap, sizeof(originalMap));
		printMap();
		StackSloveMaze(1, 1);
		cout << "Stack Method Complete Wait 5sec For Next Method(Queue Method) \n";
		Sleep(5000);


		memcpy(Buffer, originalMap, sizeof(originalMap));
		printMap();
		QueueSloveMaze(1, 1);
		cout << "Queue Method Complete Wait 5sec For Next Method(Recursive Method) \n";
		Sleep(5000);
	}

	return 0;
}

void RecursiveSolveMaze(int x, int y)
{
	if (x < 0 || x > MAP_HEIGHT)
		return;

	if (y < 0 || y > MAP_WIDTH)
		return;

	// 만약 현재위치가 0이라면
	if (Buffer[x][y] == '0')
	{
		Buffer[x][y] = '.';		// 거쳐갔다는 표시
		Sleep(80);
		printMap();

		RecursiveSolveMaze(x + 1, y);
		RecursiveSolveMaze(x - 1, y);
		RecursiveSolveMaze(x, y + 1);
		RecursiveSolveMaze(x, y - 1);
	}
}

void StackSloveMaze(int x, int y)
{
	Point P1 = { x, y };

	Stack.Push(P1);
	int Tx;
	int Ty;

	do
	{
		Stack.Pop(&P1);
		Tx = P1.X;
		Ty = P1.Y;

		// Tx, Ty가 반경내인지, 거쳐가야될 값인지
		if (Tx < 0 || Tx > MAP_HEIGHT)
			continue;
		if (Ty < 0 || Ty > MAP_WIDTH)
			continue;

		if (Buffer[Tx][Ty] == '0')
		{
			Buffer[Tx][Ty] = '.';
			Sleep(80);
			printMap();


			Point Left = {Tx - 1, Ty};
			Point Right = { Tx + 1, Ty };
			Point Up = {Tx, Ty-1};
			Point Down = {Tx, Ty+1};

			Stack.Push(Left);
			Stack.Push(Right);
			Stack.Push(Up);
			Stack.Push(Down);
		}
	} while (Stack.GetAllocCount() != 0);

}

void QueueSloveMaze(int x, int y)
{
	Point P1 = { x, y };

	Queue.Enqueue(P1);

	int Tx;
	int Ty;

	do
	{
		Queue.Dequeue(&P1);
		Tx = P1.X;
		Ty = P1.Y;

		// Tx, Ty가 반경내인지, 거쳐가야될 값인지
		if (Tx < 0 || Tx > MAP_HEIGHT)
			continue;
		if (Ty < 0 || Ty > MAP_WIDTH)
			continue;

		if (Buffer[Tx][Ty] == '0')
		{
			Buffer[Tx][Ty] = '.';
			Sleep(80);
			printMap();

			Point Left = { Tx - 1, Ty };
			Point Right = { Tx + 1, Ty };
			Point Up = { Tx, Ty - 1 };
			Point Down = { Tx, Ty + 1 };

			Queue.Enqueue(Left);
			Queue.Enqueue(Right);
			Queue.Enqueue(Up);
			Queue.Enqueue(Down);
		}

	} while (Queue.GetAllocCount() != 0);
}

void printMap()
{
	system("cls");

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			printf("%c", Buffer[i][j]);
		}

		printf("\n");
	}
}