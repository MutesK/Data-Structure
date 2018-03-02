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
- [x] Red Black Tree
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


## 균형 잡힌 이진 탐색 트리

1. 종류

   1. AVL 트리
   2. 2-3 트리
   3. 2-3-4 트리
   4. 레드 블랙 트리
   5. B 트리

2. Why use?

   ​	*이진 트리가 한쪽으로 쏠려있다면, 검색이 최악의 경우 $O(n)$이 나올수도 있습니다.*

3. 레드 블랙 트리

   1. 특징
      1. 각 노드는 부모의 포인터를 가진다.
      2. 각 노드는 Red, Black의 색상 값을 가진다.
      3. 리프 노드를 표현하기 위해 Nil이라는 공통된 노드를 사용한다.
   2. 노드 구성 조건
      1. 모든 노드는 레드, 블랙 중 하나
      2. 루트 노드는 블랙이다.
      3. 리프 노드는 블랙이다.
      4. 레드 노드의 자식은 블랙이다.
         1. 블랙 노드의 자식은 어떤 색이든 가능
         2. 레드 노드의 부모는 무조건 블랙
      5. 루트노드로 부터 리프노드까지 모든 경로에서의 블랙 노드의 갯수는 같다.
   3. 성능이 왜 좋은가?
      1. 이진트리의 검색 성능을 좌우하는 것은 리프노드 까지의 깊이의 밸런스
      2. 한쪽으로의 쏠림이 적은 상태가 좋다.
   4. 상황분석

   ```cpp
   // == 15개 노드의 최고 상황 ==============================

    
                       B

                R               R

            B       B       B       B
    
         R    R   R   R   R   R   R   R
    
       N  N N  N N N N N N N N N N N N N

   어떤 경우에도 4번만에 검색 가능. (15개 노드)
   Root > Leaf 의 모든 경우에 대해 블랙 2회.


   // == 15개 노드의 레드블랙 최악 상황 =====================


                         B

                B                   R

            B       B         B          B
    
          N  N     N  N    B     B    R     R
                         
                          N N   N N  B  B   B   B

                                    NN  NN  NN  NN
                                    
        
   3회 ~ 5회 만에 검색 가능. (15개 노드)
   ```

   5. 회전

   ```cpp
   // 노드의 회전
   // 노드의 깊이 밸런스를 맞추기 위해서 회전은 필수다.
   /*
   노드의 깊이 밸런스를 맞추기 위해 필요한 기본 기능은 회전.


   - Node N 을 기준으로 우회전

          N

      A       D

    B   C   E   F


           < N 에서 우회전 >

          A

      B       N

           C     D

               E    F


   N 의 왼쪽 자식 (A) 이 N 의 위치로 오며 N 은 왼쪽자식(A) 의 오른편으로 붙음.
   이때 N 의 왼쪽자식 (A) 의 오른편 자식 (C) 은  N 의 왼편으로 붙음.

   - Node N 을 기준으로 좌회전


          N

      A       D

    B   C   E   F


           < N 에서 좌회전 >

          D

        N    F

      A   E

    B   C  

   N 의 오른 자식 (D) 이 N 의 위치로 오며 N 은 왼쪽자식(D) 의 왼편으로 붙음.
   이때 N 의 오른자식 (D) 의 왼편 자식 (E) 은  N 의 오른편으로 붙음.

   */

   ```

   6. 삽입연산

      일반적인 이진트리의 삽입연산 이후, 밸런스 작업을 한다.

      새로 삽입되는 노드는 무조껀 RED이고, 새로 삽입되는 노드는 무조건 끝단에 들어간다.

      ```cpp
      InsertSort(Node)
      {
          // 변수 셋팅
          ParentNode = Node->Parent;
          GrandNode = Node->Parent;
          UncleNode = nullptr;
          
          if Parent = Root
              return;
        	if Grand = nullptr
              return;
          
          if Parent = Grand->left
              Uncle = Grand->Right;
          else
              Uncle = Grand->left
              
          // 상황 1.
          // 나도 부모도 삼촌도 레드
          //  레드 노드의 자식은 블랙이다.라는 조건이 맞지 않음.
          {
              Parent->Color = BLACK;
              Uncle->Color = BLACK;
              Grand->Color = RED;
              
              // 할아버지가 레드로 바뀜으로 인해서,  할아버지 상단의 색상도 모두 비교를 해보아야 한다.
              // 그래서 결국 ROOT 노드까지 올라가면서 이를 반복 확인 해야한다.
              //  할아버지를 새 노드로 잡고 다시 확인.

              InsertSort(pGrand); // 할아버지 기준으로 재귀
          }
          // 상황 2.
          // 오른쪽 레드, 부모도 레드, 삼촌은 블랙
          {
              // 회전을 통해서 밸런스를 일단 맞춰준다. 
              // 좌측이나, 우측으로 노드가 몰려있게 회전해준다.
              // 그리고 회전을 통해 3번 조건으로 만들어준다.
              if ((pGrand->pLeft == pParent && pParent->pLeft == pNode) ||
      			((pGrand->pRight == pParent && pParent->pRight == pNode)))
      		{
      			rotateL(pGrand);
      			//pNode->Color = BLACK;
      			pParent->Color = BLACK;
      			pGrand->Color = RED;
      		}
      		// 부모기준으로 좌회전
      		else
      		{
      			rotateL(pParent);
      			// 3번 상황으로 바뀌였다.
      		}
      		InsertSort(pParent);
          }
          // 상황 3. 
          // 나는 왼쪽 레드, 부모도 레드, 삼촌은 블랙
          {
               // 부모를 블랙으로, 할아버지는 레드, 
              // 할아버지 기준으로 우회전
              pParent->Color = BLACK;
      		pGrand->Color = RED;
      		rotateR(pGrand);
          }
          
          // 회전에 의해 루트가 달라질수 있다.
          	while (m_pRoot->pParent != Nil)
      		m_pRoot = m_pRoot->pParent;


      	m_pRoot->Color = BLACK;
      }
      ```

   7. 삭제연산

      1. 이진트리와 같은 방식으로 함.
      2. 만약 지울 노드가 RED엿다면, 밸런스작업 필요없다.
      3. 지울 노드가 BLACK이라면 밸런스작업이 필요하다.

   ```cpp
   // 지울 노드가 BLACK이고
   // 지울 노드의 자식을 Replace라고 한다.
   // 반복
   {
      if(Replace 노드가 Red 라면)
          Replace 노드를 Black으로 바꿈.
      	   리턴
          
      if(Replace가 Root라면)
          Root = Black, 리턴
          
      if(형재 노드가 Red라면)
      {
          형제를 블랙으로 바꾼다.
          부모를 레드로 바꾼다. // 지운노드는 블랙, 지울노드의 자식(꽤차고 들어온노드) 도 블랙인 상황
          부모기준으로 좌회전한다. // 그다가 형제가 레드라면, 형제의 블랙자식이 양쪽에 붙어있음.
          Replace 기준으로 루프 반복
              
          /* 
          	형제에 딸린 블랙 자식이 둘이기 때문에, 자회전시 형제에 딸려있던 블랙이 이쪽 (기존 부모아래)에 넘겨진다. 회전을 거쳐서 기존의 형제는 새로운 부모가 되어 기존의 부모는 나만의 부모가된다. 
          */
      }
      if(형제가 블랙 & 형제의 두자식 모두 블랙)
      {
          // 형제를 레드로!  왜냐면 자식이 모두 블랙이니 자식만 본다면 레드로 바뀌어도 문제 없음.
          // 그러므로 부모기준으로 (부모를 Replace 로 바꿔서) 본 함수 처리를 모두 다시한다.
      }
       
      if(형재가 블랙 & 형제의 왼쪽 자식의 레드)
      {
          // 왼쪽 또는 오른쪽 또는 양쪽이 모두 레드일 수 있다.
          // 하지만 여기서는 어쨌든 형제의 오른쪽이 레드인 상황이 필요함.
          // 양쪽이 모두 레드여도 상관 없음.
          
          // 왼쪽이 레드라면 형제의 왼자식을 블랙으로 바꾼 후 형제를 레드로 바꾸고 
   		// 형제를 우회전 시켜서  레드를 오른쪽으로 옮김.
   		// 양쪽이 레드여도 똑같이 처리됨.  어차피 왼자식이 블랙으로 되고 우회전.

   		// 그러면 어찌되었뜬 형제는 블랙, 오른자식이 레드 상태로 만들어짐.
      }
       
      if(형제가 블랙 & 형제의 오른쪽 자식이 레드)
      {
          // 형제를 부모와 같은 색으로 바꿔주고, 형제의 오른자식은 블랙으로,  부모는 블랙으로 바꿔주고
   	   // 부모기준 좌회전.
          
          // 이로서 블랙인 부모가 왼편으로 옮겨지므로 블랙이 부모의 왼쪽 넘어온 처리가 됨..
   		// 이 상황은 오른쪽의 블랙을 왼편으로 옮김으로 양쪽 블랙 밸런스가 맞춰졌음.  
   		// 총 블랙개수에 영향이 없으므로 모든 상황 종료.

      }
       
       // 루트를 블랙으로!
   }
   ```

   ​

4. AVL 트리

------

# 어렵다고 느끼거나 다시 봐야될것들

+ 합병정렬
+ 퀵정렬
+ 삽입정렬
+ 힙정렬
+ N Queen Problem
+ 레드 블랙 트리


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