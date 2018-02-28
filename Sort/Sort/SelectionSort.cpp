#include <iostream>
using namespace std;
using namespace std;
/*
	일반 최악 Big O(n^2)
*/
int Arr[] = { 5, 9, 1, 4, 8, 15, 2, 6, 44, 30 };
void SelectionSort()
{
	// 선택 정렬은, 가장 큰수 찾아서 뒤로 놓는 방식임. 뒤로 놓은 곳은 다시 탐색을 안해도 된다.
	int MAX = 0;
	int LEN = 10;
	int j;
	for (int i = LEN - 1; i >= 0; i--)
	{
		for (j = 0; j <= i; j++)
		{
			if (Arr[MAX] < Arr[j])
				MAX = j;
		}

		//swap(Arr[MAX], Arr[i]);
		int Temp = Arr[MAX];
		Arr[MAX] = Arr[i];
		Arr[i] = Temp;

		MAX = 0;
	}
}


int main()
{
	for (int i = 0; i < 10; i++)
	{
		cout << Arr[i] << " ";
	}

	cout << endl << endl;
	SelectionSort();

	for (int i = 0; i < 10; i++)
	{
		cout << Arr[i] << " ";
	}
	return 0;
}