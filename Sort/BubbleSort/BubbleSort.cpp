#include <iostream>
using namespace std;
/*
	�Ϲ� �־� Big O(n^2)
*/
int Arr[] = { 5, 9, 1, 4, 8, 15, 2, 6, 44, 30 };
int LEN = 10;
void BubbleSort()
{
	/*
		����ó�� 2���� ������ �������� �����ϸ�,

		���� ū���� �� �ڷ� �ű��. �׸��� ���� ū���̹Ƿ�, ���Ĵ�󿡼� ������.
	*/
	for (int i = LEN; i >= 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			if (Arr[j] > Arr[j + 1])
			{
				swap(Arr[j], Arr[j + 1]);
			}
		}
	}
}
int main()
{
	for (int i = 0; i < 10; i++)
	{
		cout << Arr[i] << " ";
	}

	cout << endl << endl;
	BubbleSort();

	for (int i = 0; i < 10; i++)
	{
		cout << Arr[i] << " ";
	}
	return 0;
}