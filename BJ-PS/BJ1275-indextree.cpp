#include <bits/stdc++.h>

using namespace std;

#define MAXK 18

long long IDT[1<<MAXK];//index tree
int N, Q, B;

void initIDT()
{
    for(int i=B-1; i>0; i--)
    {
        IDT[i] = IDT[i<<1] + IDT[(i<<1)|1];
    }
}

long long lgSum(int l, int r)
{
    l += (B-1); r += (B-1);
    long long sumV = 0;
    while(l<=r)
    {
        if((l&1)==1) sumV += IDT[l];
        if((r&1)==0) sumV += IDT[r];

        l = (l+1)>>1;
        r = (r-1)>>1;
    }
    return sumV;
}

void update(int p, int v)
{
    p += (B-1);
    IDT[p] = v;
    while(p >>= 1)
    {
        IDT[p] = IDT[p<<1]+IDT[(p<<1)|1];
    }
}

int main()
{
    scanf("%d %d", &N, &Q);

    for(B=1; B<N; B<<=1);

    for(int i=B; i<N+B; i++)
    {
        scanf("%lld", &IDT[i]);
    }

    initIDT();

    for(int i=0, x, y, a, b; i<Q; i++)
    {
        scanf("%d %d %d %d", &x, &y, &a, &b);
        printf("%lld\n", lgSum(min(x,y), max(x,y)));
        update(a, b);
    }

    return 0;
}
