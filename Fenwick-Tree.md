구간의 대표 값(주로 합, 최대/최소는 특성상 어려움)을 bit 연산으로 구할 수 있음

트리 공간이 데이터 개수와 같은 N개만 있으면 됨

v&-v 을 수행하면 2진수 기준으로 가장 오른쪽 1이 나오게 됨.

예를 들어

Ex) 32bit 기준으로......

6 = 0000 0000 0000 0000 0000 0000 0000 0110

-6 = 1111 1111 1111 1111 1111 1111 1111 1010

6 & -6 = 110 & 010 = 010

#### 값 Update

```
void update(int y, long long v)
{
    while(y <= N)
    {
        Ftree[y] += v;
        y += (y&-y);
    }
}
```

#### 구간 값 구하기

```
long long getSum(int v)
{
    long long ret = 0;
    while(v > 0)
    {
        ret += Ftree[v];
        v -= (v&-v);
    }
    return ret;
}
```
