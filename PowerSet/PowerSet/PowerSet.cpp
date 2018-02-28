#include <iostream>
using namespace std;

/*
PowerSet(S)
{
	if S is empty set
		print nothing
	else
		let t be the first element of S;
		find all subsets of S-{t} by calling PowerSet(S - {t});
		print the Subnets; -> Return All of Them
		print the subsets with adding t;
}

// 이렇게 하려면 PowerSet 함수는 여러개의 집합들을 return 해야 한다. How?

// 재귀 함수가 두개의 집합을 매개변수로 받도록 설계해야됨.
// 두 번째 집합의 모든 부분집합들에 첫번째 집합을 합집합하여 출력한다.
PowerSet(P, S)
{
	if S is empty set
		Print P
	else
		let t be the first element of S;
		PowerSet(P, S-{t});
		PowerSet(Pu{t}, S-{t});  // P에 합집합.

}

S = {a, b, c, d, e, f} 일때
#1
집합  S						집합 P
{b, c, d, e, f}의 모든 부분집합에  {a} 를 추가한 집합들을 나열한다.

#2
{c, d, e, f}의 모든 부분집합에  {a} 를 추가한 집합들을 나열한다.
{c, d, e, f}의 모든 부분집합에  {a, b} 를 추가한 집합들을 나열한다.

 
 P = 처음부터 K-1번째 윈소들 중 일부
 S = K번째 부터, 마지막 원소까지 연속된 원소들.


 집합 S는 Data[K] ... Data[n-1]이고,
 집합 P는 Include[i] = true or false, i =0 ... K-1까지의 원소들

 int Data[LEN];
 bool Include[LEN];
*/

char Data[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
int LEN = 6;
bool include[6] = { false };  // 트리상 현재 나의 위치를 표현한다.

void PowerSet(int K) // K // 트리상 현재 나의 위치를 표현한다.
{
	if (K == LEN) // S가 비어있다면 S(K)에서 K가 LEN -> 볼 인덱스가 없다면 => 내 위치가 리프노드라면
	{
		// 배열 출력
		for (int i = 0; i < LEN; i++)  // P 배열을 출력한다. -> P는 include이므로 include가 true인것만 출력한다.
		{
			if (include[i])
				cout << Data[i] << " ";
		}
		cout << endl;
		return;
	}
	include[K] = false; // PowerSet(P, S-{t}); data[K]를 포함하지 않을때 부분집합들  -> {b, c, d, e, f}의 모든 부분집합에  {a} 를 추가한 집합들을 나열한다.
	PowerSet(K + 1);  // 왼쪽으로 내렸갔다가
	include[K] = true; // PowerSet(Pu{ t }, S - {t});  data[K]를 포함하는 않을때 부분집합들 -> {a, b, c, d, e, f}의 모든 부분집합.
	PowerSet(K + 1); // 오른쪽으로 내려간다.
}

int main()
{
	PowerSet(0);
	return 0;
}