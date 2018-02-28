#include <iostream>
using namespace std;
/*
	최악 Big O(n^2)
	일반 Big O(n log_2 n)
*/
int Arr[] = { 5, 9, 1, 4, 8, 15, 2, 6, 44, 30 };
int LEN = 10;
// 분할정복일때 분할한다.
void QuickSort(int Start, int End);
// 비펏을 선택하게 한다.
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
		int Pivot = Partition(Start, End); // 현재 Start, End에 대해 파티셔닝
	
		// 피벗을 기준으로 배열을 분할한다.
		QuickSort(Start, Pivot - 1);  // 오른쪽으로 배열분할
		QuickSort(Pivot + 1, End); // 왼쪽으로 배열분할
	}
}

int Partition(int Start, int End)
{
	int Pivot = Arr[Start]; // 중심점, 기준
	int low = Start + 1;  // 정렬대상의 왼쪽을 가르킨다.
	int high = End; // 정렬대상의 오른쪽을 가르킨다.

	// low -> 피벗보다 큰 값을 만날때까지, 
	// high -> 피벗보다 작은 값을 만날때까지,

	while (high >= low)
	{
		if (Pivot > Arr[low])
			low++;
		if (Pivot < Arr[high])
			high--;

		if (low <= high)
			swap(Arr[low], Arr[high]);
	}

	// 피벗이랑 high랑 바꾼다.
	swap(Arr[Start], Arr[high]);

	return high;
}