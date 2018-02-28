#include <iostream>
using namespace std;
/*
	�Ϲ�, �־� Big O(n log_2 n)
*/
int Arr[] = { 5, 9, 1, 4, 8, 15, 2, 6, 44, 30 };
int LEN = 10;
void Merge(int Start, int Mid, int End)  // �����ϸ鼭 �������ش�.
{
	// Start���� End���� �����Ѵ�.
	int *tempArr = new int[End + 1];  // ���� �� ����� ���� �迭 

	int fIdx = Start;  // ������ ������ ��ġ����
	int rIdx = Mid + 1;	// ���ʿ����� ��ġ����
	int i;
	int sIdx = Start;  // tempArr�� ������ �ε���

	while (fIdx <= Mid && rIdx <= End)  // ������ �迭�� �ϼ��ǰų�, ���� �迭�� �ϼ��Ǹ� ���´�.
	{						
		if (Arr[fIdx] <= Arr[rIdx])				// ���� �� �� ������ �����͵��� ���Ͽ�, ���ļ������ tempArr�� �ϳ��� �Ű� ��´�.
			tempArr[sIdx] = Arr[fIdx++];
		else
			tempArr[sIdx] = Arr[rIdx++];

		sIdx++;
	}

	if (fIdx > Mid) // �迭�� �պκ��� ��� �Ű����ٸ�
	{ 
		for (i = rIdx; i <= End; i++, sIdx++)  // �迭�� �޺κп� ���� �����͵��� �迭�� �״�� �ű��.
			tempArr[sIdx] = Arr[i];
	}
	else // �迭�� �޺κ��� ��� tempArr�� �Ű����ٸ�,
	{
		for (i = fIdx; i <= Mid; i++, sIdx++)  // �迭�� �պκп� ���� �����͵��� tempArr�� �״�� �ű��.
			tempArr[sIdx] = Arr[i];
	}

	for (i = Start; i <= End; i++)
	{
		Arr[i] = tempArr[i];
	}


	delete[] tempArr;
}
void MergeSort(int Start, int End)   // ����Լ��� �̿��ؼ� �迭�� �����ش�.
{
	if (Start < End)
	{
		int mid = (Start + End) / 2;
		//wprintf(L"[%d, %d]\n", Start, mid);
		MergeSort(Start, mid);
		//wprintf(L"[%d, %d]\n", mid + 1, End);
		MergeSort(mid + 1, End);
		Merge(Start, mid, End);
	}
}
int main()
{
	for (int i = 0; i < 10; i++)
	{
		cout << Arr[i] << " ";
	}

	cout << endl << endl;
	MergeSort(0, LEN);

	for (int i = 0; i < 10; i++)
	{
		cout << Arr[i] << " ";
	}
	return 0;
}