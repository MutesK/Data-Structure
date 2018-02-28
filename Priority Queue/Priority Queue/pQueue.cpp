/*
	우선순위 큐
		왜 힙으로?
			배열 기반 데이터 저장의 시간 복잡도 O(n) : 배열에 저장된 모든 데이터와의 우선순위 비교과정을 거쳐야된다.
			배열 기반 데이터 삭제의 시간 복잡도 O(1) : 맨 앞에 저장된 데이터를 삭제하면 된다.

			연결 리스트 기반 데이터 저장의 시간 복잡도 O(n) : 배열과 비슷함.
			연결 리스트 기반 데이터 삭제의 시간 복잡도 O(1)

		힙을 기반으로 하면 트리의 높에 해당하는 수만큼 비교연산만 하면된다. 

		저장 - O(log_2 N)
		삭제 - O(log_2 N)
*/

#include "pQueue.h"

int main()
{
	CPriorityQueue Queue;

	Queue.Enqueue(1);
	Queue.Enqueue(2);
	Queue.Enqueue(3);
	Queue.Enqueue(9);
	Queue.Enqueue(7);


	Queue.Display();
}