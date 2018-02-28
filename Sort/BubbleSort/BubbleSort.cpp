#include <iostream>
using namespace std;
/*
	일반 최악 Big O(n^2)
*/
int Arr[] = { 5, 9, 1, 4, 8, 15, 2, 6, 44, 30 };
int LEN = 10;
void BubbleSort()
{
	/*
		버블처럼 2개의 인접한 값끼리만 정렬하며,

		가장 큰값은 맨 뒤로 옮긴다. 그리고 가장 큰값이므로, 정렬대상에서 빠진다.
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