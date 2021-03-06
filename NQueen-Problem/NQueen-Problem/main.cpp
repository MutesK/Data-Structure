#include <iostream>
using namespace std;

/*
	n * n 체스판 

	각 열마다 퀸이 있어야 하며, 그 퀸은 아무도 먹지못하게 만들어야된다.

	=> 상태 공간 트리를 이용하면 해를 구할수있다.
	즉 해가 존재한다면, 그것은 반드시 이 트리의 어떤 한 노드에 해당함.
	따라서 이 트리를 체계적으로 탐색하면 해를 구할수 있다.

	실제 이 트리를 만드는게 아니라 논리적인것.
	모든 노드를 탐색할 필요는 없다.

*/

enum
{
	eQUEEN = 5,

	eBLANK = 0,
	eNOT,
	
	//CHESSSIZE = 10,
};

int* Cols;
bool NQueen(int level, int N);


bool isPromising(int level);

int Method = 0;
int main()
{
	int N; 

	scanf_s("%d", &N);
	Cols = new int[N + 1];

	NQueen(0, N);
	printf("%d", Method);

	return 0;
}

bool NQueen(int level, int N)
{
	if (!isPromising(level))   // 퀸이 올바른 위치인지 확인한다.
		return false;
	else if (level == N) // 레벨이 전부 도달한경우, 리턴
	{
		Method++;
		return true;
	}
	
	for (int i = 1; i <= N; i++)
	{
		Cols[level + 1] = i; // 퀸을 두고 -> 해당 X좌표를 넣어준다.
		NQueen(level + 1, N);// 퀸을 둔곳이 충돌이 없는지 재귀로 확인한다.
	
	}

	return false; // 둘수없는 경우의 수에 걸렷다.

}

bool isPromising(int level)
{
	for (int i = 1; i < level; i++)
	{
		// 바로 밑인가?
		if (Cols[i] == Cols[level])
			return false;

		// 같은 대각선인가? = 기울기가 1인가
		else if (level - i == abs(Cols[level] - Cols[i]))
			return false;
	}

	return true;
}