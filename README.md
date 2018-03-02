# Data Structure and Algorithm

*개인 공부용입니다.*

## TO-DO List

- [x] N Queen Problem
- [x] PowerSet
- [x] Counting Cell Blob
- [x] Maze
- [ ] Hash
- [x] 우선순위 큐(Priority Queue)
- [ ] 그래프
- [ ] Minimun Spanning Tree
- [ ] Shortest Path
- [ ] Compresssion
- [x] 이진 탐색
- [x] 순차 탐색
- [x] 버블 정렬
- [x] 선택 정렬
- [x] 삽입 정렬
- [x] 퀵 정렬
- [x] 합병 정렬
- [x] 힙 정렬
- [x] Singly Linked List
- [x] Doubly Linked List
- [x] Linked List Stack
- [ ] Array Stack
- [x] Linked List Queue
- [ ] Array Queue
- [x] BinarySearch Tree
- [ ] Red Black Tree
- [ ] AVL

------



## SinglyLinkedList

*No Use Template*

## DoublyLinedList

*템플릿, 이터레이터 구현된 이중연결리스트입니다.*

## LinkedList Stack

*Unfortunately, I didn't make Project Folder. It just used in Maze Project.*

## LinkedList Queue

*it's same to Stack Description.*

## Maze

*Solve it use Recursive Function, Stack and Queue. Recursive and Stack Method is DFS. Queue Method is BFS.*

## Polynomial

*It's calculate for polynomial with respect to x. it use std:list*

## N Queen Problem

```cpp
int Level; // Ypos 
int Cols[N]; // Index = Ypos, Value = Xpos => 퀸을 가르킴.

bool NQueen(int Level)
{
    if (!isPromising(level))// 만약 올바르지 않는 위치라면
        return false;
    else if // 레벨과 N이 같다면
        return true;
 	
    // 한 행을 반복하면서 퀸의 위치를 설정한다.
    {
        // 퀸의 위치 설정
    	if(NQueen(Level + 1)) // 현재 퀸의 위치가 다음 아래에서 충돌이 없는지 확인한다.
            return true;
    }
    
    return false;
}


bool isPromising(int Level)
{
    // 한 열(Ypos)을 반복한다
    {
        // 이 레벨에 있는 퀸의 X좌표와 전에 있는 X좌표와 동일하다면
        return false;
        
        // 대각선의 기울기가 1인가?
        return false;
    }
    
    return true;
}
```

## PowerSet

*멱집합*

+ { a , b, c, d, e, f} 의 모든 부분집합을 나열하려면,
+  a를 제외한 {b, c, d, e, f}의 모든 부분집합들을 나열하고
+ {b, c, d, e, f}의 모든 부분집합에 {a}를 추가한 집합들을 나열한다.

*상태 공간 트리*

+ 해를 찾기 위해 탐색할 필요가 있는 모든 후보들을 포함하는 트리
+ 트리의 모든 노드를 방문하면 해를 찾을수 있다.
+ 루트에서 출발하여, 체계적으로 모든 노드를 방문하는 절차를 기술한다.
+ 1차원적인 생각으로 진짜 트리를 만드는것은 아님. 로직상으로 탐색할수 있게 한다.


## Heap

+ Complete Binary Tree

+ Heap Property 만족한다.
  + Max Heap Property  = 부모는 자식보다 크거나 작다.
  + Min Heap Property = 부모는 자식보다 작거나 같다.

+ 일반 이진트리의 속성으로 Height = Log_2 (Node의 갯수)

+ Full Binary Tree
  + 모든 레벨의 노드들이 꽉차 있는 형태

+ Complete Binary Tree
  + 마지막 레벨을 제외하면 완전히 빈칸으로 꽉차 있음.

+ 힙은 일차원 배열로 표현이 가능함.
  + 루트 노드 A[1]
  + A[i]의 부모 = A[i / 2]
  + A[i]의 왼쪽 자식 = A[2i]
  + A[i]의 오른쪽 자식 = A[2i + 1]

  ```cpp
  MaxHeapSort()
  {
      // 1. 배열을 작은 힙으로 만든다.
      
      // 인덱스가 끝인 노드부터 2가 될때까지 반복
      // swap(Arr[1], Arr[index]); // 이 이유는, 작은 값이 제일 위에 있다.
      // 인덱스의 끝부분은 이미 정렬이 완료되어서 제자리에 있기 때문에 다음 Heapifiy에 적용되지 않게 조절한다.
      // Min_heapify(1); // 최상위 루트노드에 대해 Min으로 Heap화한다.
  }

  // 배열을 작은 힙으로 만든다.
  {
      // 자식을 노드를 가지고 있는 노드중에 가장 우측에 있는 노드부터, 루트노드까지 Min 힙화 한다.
      for (int i = LEN / 2; i >= 1; i--)
  	{
  		Min_heapify(i);
  	}
  }

  // Min 힙화한다.
  {
      /*
      A[i]가 자식이 없다면 
      	리턴
      
      K - 자식들중 가장 큰 값
      
      A[i] <= A[K] 라면  // 부모보다 자식이 더 크다면 Min Heap이 아니다.
      	리턴
      
      A[i]와 A[k] 교체한다.
      Min_heapify(K) // K로 다시 돈다.
      */
  }
  ```

  ​

## Binary Tree

+ 응용의 예
  + 수식 트리
  + Huffman Code(압축)

+ 표현방법
  + 배열
  + Linked List

+ 포화 이진 트리

  + 모든 노드가 2개씩 꽉찬경우

+ 완전 이진 트리

  + 왼쪽에서 오른쪽으로 꽉채운 트리
  + 힙구조, 힙정렬에서 사용됨.

+ 높이 균형 트리

  + right tree의 가중치와 left tree 가중치를 비슷하게 만들어준다.

  + 가중치를 보며, 루트를 바꾸면서 가장 밸런스를 맞게 만들어주는 역할

    *트리의 가중치란. 트리상에 가능한 모든경로에 대해 '경로의 가중치'의 합을 의미.*

    *1번 노드에서 N번 노드로 갈때 필요한 자원를 예를 들수 있음.*

*힙과 다르게, 최악의 경우의 이진트리의 높이는 N이다.*

+ 이진트리의 순회
  + Inorder(중위)
  + Preorder(전위)
  + postorder(후위)
  + level-order(BFS)

```cpp
Inorder_Traversal(Node = Root)
{
    Inorder_Traversal(Node->left);
    printf(Node);
    Inorder_Traversal(Node->right);
}

Preorder_Traversal(Node = Root)
{
	printf(Node);	
    Inorder_Traversal(Node->left);
    Inorder_Traversal(Node->right);
}

postorder_Traversal(Node = Root)
{
    Inorder_Traversal(Node->left);
    Inorder_Traversal(Node->right);
    printf(Node);
}

Level Order Tree Traversal()
{
    Queue.Enqueue(Root);
    
    while(Queue isn't Empty)
    {
        v = Queue.Dequeue();
        printf(v);
        Queue.Enqueue(v->left);
        Queue.Enqueue(v->right);
    }
}
```

## BinarySearch Tree

+ 삭제연산

  1. 삭제할 노드가 단말 노드인 경우
  2. 서브트리가 하나만 있는 경우
  3. 두개의 서브트리가 있는 경우

  ```cpp
  // 1. 삭제할 노드가 단말 노드인경우
  if(isNil(Node))
  {
      // 그냥 삭제, 부모와 연결고리도 끊는다.
  }

  // 2. 서브트리가 하나만 있다면
  else if(isOneSubTree(pNode))
  {
      // pNode가 가지고 있는 자식이랑 부모랑 바로 연결시켜준다.
  }

  else
  // 3. 서브트리가 2개 이상이 있다면
  {
      // 해결방법은 2가지가 있다.
      // 1. 왼쪽 서브트리에서 가장 큰값이랑 바꾸는 방법
      // 2. 오른쪽 서브트리에서 가장 작은 값이랑 바꾸는 방법
  }
  ```

  ​

------

# 어렵다고 느끼거나 다시 봐야될것들

+ 합병정렬
+ 퀵정렬
+ 삽입정렬
+ 힙정렬
+ N Queen Problem


------

# 각 알고리즘별 시간복잡도

1. 버블 정렬

     시간복잡도 $O(n^2)$이다.

2. 삽입 정렬

   시간복잡도 $O(n^2)$이다.

3. 선택 정렬

   ​	시간복잡도 $O(n^2)$이다.

4. 합병 정렬

   ​	시간복잡도 $O(n log_2 n)$이다. 최악의 경우에도 같다.

5. 퀵 정렬

   ​	시간복잡도 $O(n log_2 n)$이다. 최악의 경우에는 $O(n^2)$이다.

6. 힙 정렬

   ​	최대 힙으로 만드는 과정은 $O(n)$ 이고, Down Heap은 한 노드에 대해서 $log_2 N$ 까지 내려갈수 있다. 

   ​	하지만 내려가면서 2번의 비교를 하므로, $2 log_2 N$ 의 비교 연산이 들어간다. 즉, $O(n + 2log_2 N)$이므로

   ​	$O(n log_2 n)$ 이다.

7. 선형 탐색

   ​    선형 탐색은 무조건 한번은 돌아야 한다. $O(n)$ 이다.

8. 이진 탐색

   ​     이진 탐색의 경우 한번 돌때마다 $N/2$이 되기 때문에, K번을 돌았다면 $(1/2)^k N \approx 1$ 이므로, 

   ​	$N \approx 2^K$ 가 되므로, $O(log_2 N)$ 이다.