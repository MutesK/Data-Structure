# Recursive

## 재귀함수가 무한 루프에 빠지지 않기위한 조건

1. 적어도 하나의 재귀함수에서 빠지는 경우가 존재해야 된다.
2. 재귀를 반복하다보면 결국 조건1에 만족해야된다.

## 재귀함수는 수학함수 계산에만 유용한건 아니다.

1. 문자열길이 계산

```
if the string is empty
	return 0
else
	return 1 + the length of the string that excludes first character.
```

2. 문자열을 뒤집어 프린트

```c
void function(char str[], int index = 0)
{
    if(strlen(str) == 0)
    	return;
   	else
   	{
        function(function(str, index + 1));
        printf("%c", str[index]);
   	}
}
```

3. 2진수로 변환하여 출력

```c
void function(int n)
{
    if(n < 2)
        printf("%d", n);
    else
    {
        function(n / 2);
        printf("%d", n % 2);
    }
}
```

4. 배열의 합 구하기

```c
void function(int n, int data[])
{
    if(n <= 0)
        return 0;
    else
        return function(n-1, data) + data[n-1];
}
```

## Recursion vs Iteration

+ 일반적인 상황에서는 모든 순환 함수는 반복문이 가능함
+ 역으로, 모든 박복문은 재귀함수로 표현가능함
+ 순환함수는 복잡한 알고리즘을 단순하고 알기쉽게 표현하는 것을 가능하게 함.
+ 하지만 함수 호출에 따른 오버헤드가 있다.

## 재귀 함수 설계

*암시적(implicit) 매개변수를 명시적(explicit) 매개변수로 바꾸어라.*

1. 순차 탐색

```c
int SequentialSearch(int Array[], int searchIndex, int n, int Target)
{
	if (Array[searchIndex] == Target)
		return searchIndex;

	if (n < searchIndex)
		return -1;

	return SequentialSearch(Array, searchIndex + 1, n, Target);
}
```

2. 최대값 찾기

```cpp
int findMax(int Array[], int Start, int End)
{
    if(Start == End)
        return Array[Start];
    
    return std::max(data[start], findMax(Array, start + 1, end));
}
```

