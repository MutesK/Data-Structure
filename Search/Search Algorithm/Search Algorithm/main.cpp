#include <iostream>
using namespace std;

int SequentialSearch(int Array[], int n, int Target)
{
	for (int i = 0; i < n; i++)
	{
		if (Array[i] == Target)
			return i;
	}

	return -1;
}

int SequentialSearch(int Array[], int searchIndex, int n, int Target)
{
	if (Array[searchIndex] == Target)
		return searchIndex;

	if (n < searchIndex)
		return -1;

	return SequentialSearch(Array, searchIndex + 1, n, Target);
}

int BinarySearch(int Array[], int n, int Target)
{
	int start = 0;
	int mid = 0;

	do 
	{
		mid = (start + n) / 2;

		if (Array[mid] > Target)
			n = mid - 1;
		else if (Array[mid] < Target)
			start = mid + 1;
		else
			return mid;
	} while (Array[mid] != Target);
}

int BinarySearch(int Array[], int start, int end, int Target)
{
	if (start > end)
		return -1;

	int mid = (start + end) / 2;

	if (Array[mid] > Target)
		return BinarySearch(Array, start, mid - 1, Target);
	else if (Array[mid] < Target)
		return BinarySearch(Array, mid + 1, end, Target);
	else
		return mid;

}

int main()
{
	int Array[10] = { 1,2,3,4,5,6,7,8,9,10 };

	cout << SequentialSearch(Array, 10, 8) << endl;
	cout << SequentialSearch(Array, 0, 10, 8) << endl;
	cout << BinarySearch(Array, 10, 8) << endl;
	cout << BinarySearch(Array, 0, 10, 8);

}