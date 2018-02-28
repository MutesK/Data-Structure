#include <iostream>
using namespace std;
/*
	�Ϲ� �־� Big O(n^2)
*/
int Arr[] = { 5, 9, 1, 4, 8, 15, 2, 6, 44, 30 };
int LEN = 10;
void InsertSort()
{
	/*
		��ó�� ���� ���ĵǾ� �ִٴ� ������

		���� �ε������� ���ʵ��� ���ԵǾ��ٴ� �������� ������� ����
	*/
	int j = 0;

	for (int i = 1; i < LEN; i++)
	{
		int insData = Arr[i];

		// ���� �ùٸ� ��ġ�� ã�ƾߵȴ�.
		for (j = i - 1; j >= 0; j--)
		{
			if (Arr[j] > insData)
			{
				// �� �ް��� ���� �ڷ� shift�Ѵ�.
				Arr[j + 1] = Arr[j];
			}
			else
				break;
		}

		Arr[j + 1] = insData;
		j = 0;
	}
}
int main()
{
	for (int i = 0; i < 10; i++)
	{
		cout << Arr[i] << " ";
	}

	cout << endl << endl;
	InsertSort();

	for (int i = 0; i < 10; i++)
	{
		cout << Arr[i] << " ";
	}
	return 0;
}