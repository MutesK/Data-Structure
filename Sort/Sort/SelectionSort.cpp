#include <iostream>
using namespace std;
using namespace std;
/*
	�Ϲ� �־� Big O(n^2)
*/
int Arr[] = { 5, 9, 1, 4, 8, 15, 2, 6, 44, 30 };
void SelectionSort()
{
	// ���� ������, ���� ū�� ã�Ƽ� �ڷ� ���� �����. �ڷ� ���� ���� �ٽ� Ž���� ���ص� �ȴ�.
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