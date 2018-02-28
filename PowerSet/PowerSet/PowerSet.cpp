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

// �̷��� �Ϸ��� PowerSet �Լ��� �������� ���յ��� return �ؾ� �Ѵ�. How?

// ��� �Լ��� �ΰ��� ������ �Ű������� �޵��� �����ؾߵ�.
// �� ��° ������ ��� �κ����յ鿡 ù��° ������ �������Ͽ� ����Ѵ�.
PowerSet(P, S)
{
	if S is empty set
		Print P
	else
		let t be the first element of S;
		PowerSet(P, S-{t});
		PowerSet(Pu{t}, S-{t});  // P�� ������.

}

S = {a, b, c, d, e, f} �϶�
#1
����  S						���� P
{b, c, d, e, f}�� ��� �κ����տ�  {a} �� �߰��� ���յ��� �����Ѵ�.

#2
{c, d, e, f}�� ��� �κ����տ�  {a} �� �߰��� ���յ��� �����Ѵ�.
{c, d, e, f}�� ��� �κ����տ�  {a, b} �� �߰��� ���յ��� �����Ѵ�.

 
 P = ó������ K-1��° ���ҵ� �� �Ϻ�
 S = K��° ����, ������ ���ұ��� ���ӵ� ���ҵ�.


 ���� S�� Data[K] ... Data[n-1]�̰�,
 ���� P�� Include[i] = true or false, i =0 ... K-1������ ���ҵ�

 int Data[LEN];
 bool Include[LEN];
*/

char Data[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
int LEN = 6;
bool include[6] = { false };  // Ʈ���� ���� ���� ��ġ�� ǥ���Ѵ�.

void PowerSet(int K) // K // Ʈ���� ���� ���� ��ġ�� ǥ���Ѵ�.
{
	if (K == LEN) // S�� ����ִٸ� S(K)���� K�� LEN -> �� �ε����� ���ٸ� => �� ��ġ�� ���������
	{
		// �迭 ���
		for (int i = 0; i < LEN; i++)  // P �迭�� ����Ѵ�. -> P�� include�̹Ƿ� include�� true�ΰ͸� ����Ѵ�.
		{
			if (include[i])
				cout << Data[i] << " ";
		}
		cout << endl;
		return;
	}
	include[K] = false; // PowerSet(P, S-{t}); data[K]�� �������� ������ �κ����յ�  -> {b, c, d, e, f}�� ��� �κ����տ�  {a} �� �߰��� ���յ��� �����Ѵ�.
	PowerSet(K + 1);  // �������� ���Ȱ��ٰ�
	include[K] = true; // PowerSet(Pu{ t }, S - {t});  data[K]�� �����ϴ� ������ �κ����յ� -> {a, b, c, d, e, f}�� ��� �κ�����.
	PowerSet(K + 1); // ���������� ��������.
}

int main()
{
	PowerSet(0);
	return 0;
}