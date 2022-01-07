## Links

### CP book 

https://cpbook.net/

### CP book pdf 

https://www.comp.nus.edu.sg/~stevenha/myteaching/competitive_programming/cp2.pdf

### CP book code 

https://github.com/stevenhalim/cpbook-code

https://www.geeksforgeeks.org/

### Online Compiler

https://ide.geeksforgeeks.org/

https://www.onlinegdb.com/online_c++_compiler

## DFS
https://visualgo.net/en/dfsbfs

\cpbook-code-master\ch4\traversal\dfs_cc.cpp

\cpbook-code-master\ch4\traversal\cyclecheck.cpp

그래프 표현 https://visualgo.net/en/graphds

## BFS
https://visualgo.net/en/dfsbfs

\cpbook-code-master\ch4\sssp\bfs.cpp

https://qiao.github.io/PathFinding.js/visual/

미로에서 최단경로 찾기 https://www.geeksforgeeks.org/shortest-path-in-a-binary-maze/

## DFS/BFS 장단점
### DFS 장점
현 경로상의 노드를 기억하기 때문에 적은 메모리를 사용 찾으려는 노드가 깊은 단계에 있는 경우 BFS 보다 빠르게 찾을 수 있음.

### DFS 단점
해가 없는 경로를 탐색 할 경우에도 단계가 끝날 때까지 탐색 효율성을 높이기 위해서 미리 지정한 임의 깊이까지만 탐색하고 해를 발견하지 못하면 빠져나와 다른 경로를 탐색하는 방법을 사용기도 함 DFS를 통해서 얻어진 해가 최단 경로라는 보장이 없음 DFS는 해에 도착하면 탐색을 종료하기 때문

### BFS 장점
최단경로를 찾을 수 있음

### BFS 단점
경로가 매우 길 경우에는 탐색 가지가 급격히 증가함에 따라 보다 많은 기억 공간 필요

## 재귀함수
https://visualgo.net/en/recursion

Factorial Numbers

## 정렬
### 유일성 검사
https://www.geeksforgeeks.org/print-distinct-elements-given-integer-array/

### 합집합/교집합
https://www.geeksforgeeks.org/union-and-intersection-of-two-sorted-arrays-2

### Binary Search
https://www.acmicpc.net/blog/view/109

~~~c++
#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
int Arr[MAXN];

int binarySearch(int* arr, int size, int key)
{
    int lb = -1, ub = size-1, m;
    while(lb+1 < ub)
    {
        m = lb+(ub-lb)/2;
        if(arr[m] >= key) ub = m;
        else lb = m;
    }

    return ub>=size? -1 : arr[ub]==key? ub : -1 ;
}

int binarySearch2(int* arr, int size, int key)
{
    int *p = lower_bound(arr, arr+size, key);
    return (p-arr)>=size? -1 : *p==key? (p-arr) : -1 ;
}

int main()
{
    int t, T, N, M, key;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        printf("#%d", t);
        scanf("%d %d", &N, &M);
        for(int i=0; i<N; i++) scanf("%d", &Arr[i]);
        for(int i=0; i<M; i++)
        {
            scanf("%d", &key);
            printf(" %d", binarySearch(Arr, N, key));
        }
        printf("\n");
    }
    return 0;
}
~~~

Lower bound in c  v 이상인 최소 index https://www.geeksforgeeks.org/implementing-upper_bound-and-lower_bound-in-c

https://www.geeksforgeeks.org/binary-search/
