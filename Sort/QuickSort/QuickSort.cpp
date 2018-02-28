#include <iostream>
using namespace std;
/*
	�־� Big O(n^2)
	�Ϲ� Big O(n log_2 n)
*/
int Arr[] = { 5, 9, 1, 4, 8, 15, 2, 6, 44, 30 };
int LEN = 10;
// ���������϶� �����Ѵ�.
void QuickSort(int Start, int End);
// ������ �����ϰ� �Ѵ�.
int Partition(int Start, int End);
int main()
{
	for (int i = 0; i < 10; i++)
	{
		cout << Arr[i] << " ";
	}

	cout << endl << endl;
	QuickSort(0, LEN - 1);

	for (int i = 0; i < 10; i++)
	{
		cout << Arr[i] << " ";
	}
	return 0;
}

void QuickSort(int Start, int End)
{
	if (Start <= End)
	{
		int Pivot = Partition(Start, End); // ���� Start, End�� ���� ��Ƽ�Ŵ�
	
		// �ǹ��� �������� �迭�� �����Ѵ�.
		QuickSort(Start, Pivot - 1);  // ���������� �迭����
		QuickSort(Pivot + 1, End); // �������� �迭����
	}
}

int Partition(int Start, int End)
{
	int Pivot = Arr[Start]; // �߽���, ����
	int low = Start + 1;  // ���Ĵ���� ������ ����Ų��.
	int high = End; // ���Ĵ���� �������� ����Ų��.

	// low -> �ǹ����� ū ���� ����������, 
	// high -> �ǹ����� ���� ���� ����������,

	while (high >= low)
	{
		if (Pivot > Arr[low])
			low++;
		if (Pivot < Arr[high])
			high--;

		if (low <= high)
			swap(Arr[low], Arr[high]);
	}

	// �ǹ��̶� high�� �ٲ۴�.
	swap(Arr[Start], Arr[high]);

	return high;
}