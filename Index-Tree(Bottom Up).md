구간의 대표 값(합, 최대, 최소, GCD 등)을 Bottom up 방식으로 구함

완전 이진 트리로 구성

즉, 마지막 레벨은 노드가 왼쪽에 몰려있고 마지막 레벨을 제외하면 포화이진트리(모든 노드의 자식이 2개) 구조

부모 노드가 자식 노드들의 대표 값을 가진다. (구간 합 : 자식들의 합, 구간 최대값 : 자식들 중 큰 값, 구간 최소값 : 자식들 중 작은 값)

Leaf 노드 개수는 data 개수보다 큰 2^N 개

Leaf 노드의 첫번째 index는 Leaf 노드의 개수와 같음

(예를 들어, data 개수가 5개이면, 8개(2^3)개의 Leaf노드가 필요하며 Leaf노드의 첫번째 index는 8이 됨)

Index tree 공간은 Leaf노드 개수*2 가 됨

(data 5개이면, Leaf node개수 8개, 공간은 16개 확보 필요)

Leaf노드의 첫번째 index 혹은 Leaf노드 개수 구하기

1에다가 N보다 커질 때까지 2를 곱한다

    for(B=1; B<N; B<<=1);
    
#### 값 Update

1. 변경하고자 하는 값의 index 변경  index가 1부터 시작하면 Leaf노드 첫번째 index -1 을 더해주고 0부터 시작하면 Leaf노드 첫번째 index를 더해준다
2. 부모로 이동(index/2 혹은 index>>=1)
3. 왼쪽(index2 혹은 index<<1), 오른쪽(index2+1 혹은 (index<<1)|1 ) 자식 값으로 부모 값을 갱신
4. 2~3을 Root까지 반복 (결국 LogN에 Update 가능)

```
void update(int p, int v)
{
    p += (B-1);
    MinIDT[p] = v;
    while(p >>= 1)
    {
        MinIDT[p] = min(MinIDT[p<<1], MinIDT[(p<<1)|1]);
    }
}
```

#### 구간 값 구하기

1. 구간 왼쪽(L), 오른쪽(R) 노드 index를 입력 받는다
2. 왼쪽(L), 오른쪽(R) 노드 index 값을 각각 변경한다.  index가 1부터 시작하면 Leaf노드 첫번째 index -1 을 더해주고 0부터 시작하면 Leaf노드 첫번째 index를 더해준다
3. L이 홀수 일 경우 L번째 노드를 선택하여 구간 대표 값 갱신
4. L은 L+1 노드로 이동
5. R이 짝수 일 경우 R번째 노드를 선택하여 구간 대표 값 갱신
6. R은 R-1 노드로 이동
7. L, R노드의 각각 부모로 이동 (L/2, R/2)
8. L>R이 될 때까지 3~7 반복 (결국 LogN에 구간 값 구하기 가능)

```
int lgMin(int l, int r)
{
    l += (B-1); r += (B-1);
    int minV = INF;
    while(l<=r)
    {
        if((l&1)==1) minV = min(minV, MinIDT[l]);
        if((r&1)==0) minV = min(minV, MinIDT[r]);

        l = (l+1)>>1;
        r = (r-1)>>1;
    }
    return minV;
}
```

```
int lgSum(int l, int r)
{
    l += (B-1); r += (B-1);
    int sum = 0;
    while(l <= r)
    {
        if((l&1) == 1) sum += IDT[l];
        if((r&1) == 0) sum += IDT[r];

        l = (l+1)>>1;
        r = (r-1)>>1;
    }
    return sum;
}
```
