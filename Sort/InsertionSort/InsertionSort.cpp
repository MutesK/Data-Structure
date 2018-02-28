#include <iostream>
using namespace std;
/*
	일반 최악 Big O(n^2)
*/
int Arr[] = { 5, 9, 1, 4, 8, 15, 2, 6, 44, 30 };
int LEN = 10;
void InsertSort()
{
	/*
		맨처음 값은 정렬되어 있다는 전제로

		뒤의 인덱스들이 차례들이 삽입되었다는 가정으로 만들어진 정렬
	*/
	int j = 0;

	for (int i = 1; i < LEN; i++)
	{
		int insData = Arr[i];

		// 정렬 올바른 위치를 찾아야된다.
		for (j = i - 1; j >= 0; j--)
		{
			if (Arr[j] > insData)
			{
				// 그 뒷값은 전부 뒤로 shift한다.
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