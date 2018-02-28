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
- [ ] 기수 정렬
- [x] Singly Linked List
- [x] Doubly Linked List
- [x] Linked List Stack
- [ ] Array Stack
- [x] Linked List Queue
- [ ] Array Queue
- [ ] Binary Tree
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

------

# 어렵다고 느끼거나 다시 봐야될것들

+ 합병정렬
+ 퀵정렬
+ 삽입정렬
+ 힙정렬
+ N Queen Problem