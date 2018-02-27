# Data Structure and Algorithm

*개인 공부용입니다.*

## TO-DO List

- [x] N Queen Problem
- [ ] PowerSet
- [x] Counting Cell Blob
- [x] Maze
- [ ] Hash
- [ ] 그래프
- [ ] Minimun Spanning Tree
- [ ] Shortest Path
- [ ] Compresssion
- [x] 이진 탐색
- [x] 순차 탐색
- [ ] 버블 정렬
- [ ] 선택 정렬
- [ ] 삽입 정렬
- [ ] 퀵 정렬
- [ ] 합병 정렬
- [ ] 힙 정렬
- [ ] 기수 정렬
- [x] Singly Linked List
- [x] Doubly Linked List
- [x] LinkedList Stack
- [ ] Array Stack
- [x] LinkedList Queue
- [ ] Array Queue
- [ ] Binary Tree
- [ ] Heap
- [ ] Red Black Tree
- [ ] AVL

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

