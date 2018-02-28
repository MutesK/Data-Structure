#include <iostream>
using namespace std;
/*
	일반, 최악 Big O(n log_2 n)
*/
int Arr[] = { 5, 9, 1, 4, 8, 15, 2, 6, 44, 30 };
int LEN = 10;
void Merge(int Start, int Mid, int End)  // 병합하면서 정렬해준다.
{
	// Start에서 End까지 정렬한다.
	int *tempArr = new int[End + 1];  // 병합 한 결과를 담을 배열 

	int fIdx = Start;  // 오른쪽 영역의 위치정보
	int rIdx = Mid + 1;	// 왼쪽영역의 위치정보
	int i;
	int sIdx = Start;  // tempArr에 저장할 인덱스

	while (fIdx <= Mid && rIdx <= End)  // 오른쪽 배열이 완성되거나, 왼쪽 배열이 완성되면 나온다.
	{						
		if (Arr[fIdx] <= Arr[rIdx])				// 병합 할 두 영역의 데이터들을 비교하여, 정렬순서대로 tempArr에 하나씩 옮겨 담는다.
			tempArr[sIdx] = Arr[fIdx++];
		else
			tempArr[sIdx] = Arr[rIdx++];

		sIdx++;
	}

	if (fIdx > Mid) // 배열의 앞부분이 모두 옮겨졌다면
	{ 
		for (i = rIdx; i <= End; i++, sIdx++)  // 배열의 뒷부분에 남은 데이터들을 배열에 그대로 옮긴다.
			tempArr[sIdx] = Arr[i];
	}
	else // 배열의 뒷부분이 모두 tempArr에 옮겨졌다면,
	{
		for (i = fIdx; i <= Mid; i++, sIdx++)  // 배열의 앞부분에 남은 데이터들을 tempArr에 그대로 옮긴다.
			tempArr[sIdx] = Arr[i];
	}

	for (i = Start; i <= End; i++)
	{
		Arr[i] = tempArr[i];
	}


	delete[] tempArr;
}
void MergeSort(int Start, int End)   // 재귀함수를 이용해서 배열을 나눠준다.
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