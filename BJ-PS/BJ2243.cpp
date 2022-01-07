#include <bits/stdc++.h>

using namespace std;

#define MAXK 21
#define MAXV 1000000

int IDT[1<<MAXK];//index tree
int N, B;

//k번째 찾기
int search(int k)
{
    int p = 1;
    while(p<B)
    {
        p <<= 1;//p는 왼쪽 child
        //왼쪽이 K보다 작을 경우 원하는 값은 오른쪽에 있다.
        if(IDT[p] < k)
        {
            k -= IDT[p];
            p += 1;
        }
    }

    return p-(B-1);
}

void update(int p, int v)
{
    p += (B-1);
    IDT[p] += v;
    while(p >>= 1)
    {
        IDT[p] = IDT[p<<1]+IDT[(p<<1)|1];
    }
}

int main()
{
    scanf("%d", &N);
    for(B=1; B<MAXV; B<<=1);

    for(int i=0, a, b, c; i<N; i++)
    {
        scanf("%d", &a);

        if(a==1)
        {
            scanf("%d", &b);
            c = search(b);
            printf("%d\n", c);
            update(c, -1);
        }
        else
        {
            scanf("%d %d", &b, &c);
            update(b, c);
        }
    }

    return 0;
}
