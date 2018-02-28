/*
	최악의 경우 Big O (n log_2 N)
	추가 배열 불필요, Binary Heap을 사용한다.
*/
#include <iostream>
#include <cmath>
using namespace std;
int Arr[] = {0, 5, 9, 1, 4, 8, 15, 2, 6, 44, 30 };
int LEN = 10;

void MinHeapSort();
void Build_Max_Heap();
void Max_heapify(int index);

void MaxHeapSort();
void Build_Min_Heap();
void Min_heapify(int index);
int main()
{
	for (int i = 0; i <= 10; i++)
	{
		cout << Arr[i] << " ";
	}

	cout << endl << endl;
	MinHeapSort();

	for (int i = 0; i <= 10; i++)
	{
		cout << Arr[i] << " ";
	}
	return 0;

}
void MaxHeapSort()
{
	Build_Min_Heap();

	for (int index = LEN; index >= 2; index--)
	{
		swap(Arr[1], Arr[index]);
		LEN--;
		Min_heapify(1);
	}
}
void MinHeapSort()
{
	Build_Min_Heap();

	for (int index = LEN; index >= 2; index--)
	{
		swap(Arr[1], Arr[index]);
		LEN--;
		Min_heapify(1);
	}
}
void Build_Min_Heap()
{
	for (int i = LEN / 2; i >= 1; i--)
	{
		Min_heapify(i);
	}
}

void Build_Max_Heap()
{
	for (int i = LEN / 2; i >=1; i--)
	{
		Max_heapify(i);
	}
}

void Min_heapify(int index)
{
	if (index * 2 > LEN) // A[i]가 자식이 없다면
		return;

	int K; // 자식들중 가장 작은 값
	if ((index * 2 + 1) > LEN)
		K = index * 2;
	else if (Arr[index * 2] < Arr[index * 2 + 1])
		K = index * 2;
	else
		K = index * 2 + 1;

	if (Arr[index] <= Arr[K])
		return;

	swap(Arr[index], Arr[K]);
	Min_heapify(K);
}
void Max_heapify( int index)
{
	if (index * 2 > LEN) // A[i]가 자식이 없다면
		return;

	int K; // 자식들중 가장 큰값

	if ((index * 2 + 1) > LEN)
		K = index * 2;
	else if (Arr[index * 2] > Arr[index * 2 + 1])
		K = index * 2;
	else
		K = index * 2 + 1;

	if (Arr[index] >= Arr[K])
		return;

	swap(Arr[index], Arr[K]);
	Max_heapify(K);
}