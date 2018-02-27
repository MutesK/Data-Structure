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
	
	CHESSSIZE = 10,
};

int Cols[CHESSSIZE + 1];
bool NQueen(int level);
bool isPromising(int level);


int main()
{
	NQueen(0);

	return 0;
}

bool NQueen(int level)
{
	if (!isPromising(level))   // ���� �ùٸ� ��ġ���� Ȯ���Ѵ�.
		return false;
	else if (level == CHESSSIZE) // ������ ���� �����Ѱ��, ����
	{
		for (int Ypos = 1; Ypos <= CHESSSIZE; Ypos++)
		{
			for (int Xpos = 1; Xpos <= CHESSSIZE; Xpos++)
			{
				if (Cols[Ypos] == Xpos)
					printf("5 ");
				else
					printf("0 ");
			}
			printf("\n");
		}
		return true;
	}

	for (int i = 1; i <= CHESSSIZE; i++)
	{
		Cols[level + 1] = i; // ���� �ΰ� -> �ش� X��ǥ�� �־��ش�.
		if (NQueen(level + 1)) // ���� �а��� �浹�� ������ ��ͷ� Ȯ���Ѵ�.
			return true;
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