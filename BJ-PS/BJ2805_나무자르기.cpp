#include <bits/stdc++.h>

using namespace std;

#define MAXSIZE 200000000
#define MAXN 1000000

int N, M;//나무의 수 N, 집으로 가져가려고 하는 나무의 길이 M
int Wood[MAXN];

bool fmax(int size)
{
    long long h = 0;
    //나무를 size만큼 자르고 남은 나머지를 더한다.
    for(int i = 0; i < N; i++) h += max(0, Wood[i]-size);
    if(h >= M) return true;
    return false;
}

int main()
{
    int lb = 0, ub = 0, m, ans;

    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &Wood[i]);
        ub = max(ub, Wood[i]);
    }

    while(lb+1 < ub)
    {
        m = lb+(ub-lb)/2;
        if(fmax(m)) lb = m;
        else ub = m;
    }

    printf("%d", lb);

    return 0;
}
