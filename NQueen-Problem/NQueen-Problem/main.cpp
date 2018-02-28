#include <iostream>
using namespace std;

/*
	n * n ü���� 

	�� ������ ���� �־�� �ϸ�, �� ���� �ƹ��� �������ϰ� �����ߵȴ�.

	=> ���� ���� Ʈ���� �̿��ϸ� �ظ� ���Ҽ��ִ�.
	�� �ذ� �����Ѵٸ�, �װ��� �ݵ�� �� Ʈ���� � �� ��忡 �ش���.
	���� �� Ʈ���� ü�������� Ž���ϸ� �ظ� ���Ҽ� �ִ�.

	���� �� Ʈ���� ����°� �ƴ϶� �����ΰ�.
	��� ��带 Ž���� �ʿ�� ����.

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
	if (!isPromising(level))   // ���� �ùٸ� ��ġ���� Ȯ���Ѵ�.
		return false;
	else if (level == N) // ������ ���� �����Ѱ��, ����
	{
		Method++;
		return true;
	}
	
	for (int i = 1; i <= N; i++)
	{
		Cols[level + 1] = i; // ���� �ΰ� -> �ش� X��ǥ�� �־��ش�.
		NQueen(level + 1, N);// ���� �а��� �浹�� ������ ��ͷ� Ȯ���Ѵ�.
	
	}

	return false; // �Ѽ����� ����� ���� �ɷǴ�.

}

bool isPromising(int level)
{
	for (int i = 1; i < level; i++)
	{
		// �ٷ� ���ΰ�?
		if (Cols[i] == Cols[level])
			return false;

		// ���� �밢���ΰ�? = ���Ⱑ 1�ΰ�
		else if (level - i == abs(Cols[level] - Cols[i]))
			return false;
	}

	return true;
}