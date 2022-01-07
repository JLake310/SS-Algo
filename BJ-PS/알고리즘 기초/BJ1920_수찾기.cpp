#include <bits/stdc++.h>

using namespace std;

#define MAXN 100001

int Data[MAXN];

int binarySearch(int n, int key)
{
    int lb = -1, ub = n, m;
    while(lb+1 < ub)
    {
        m = lb+(ub-lb)/2;
        if(Data[m] >= key) ub = m;
        else lb = m;
    }

    return Data[ub]==key? 1:0;
}

int main()
{
    int N, M;

    scanf("%d", &N);

    for(int i=0; i<N; i++) scanf("%d", &Data[i]);

    sort(Data, Data+N);

    scanf("%d", &M);

    for(int i=0, num; i<M; i++)
    {
        scanf("%d", &num);
        printf("%d\n", binarySearch(N-1, num));
    }

    return 0;
}
