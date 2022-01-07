//https://www.geeksforgeeks.org/n-queen-problem-backtracking-3
#include <bits/stdc++.h>

using namespace std;

#define MAXN 15

bool Col[MAXN], Rd[MAXN*2], Ld[MAXN*2];
int N, Ans = 0;

void backtracking(int c)
{
    if(c==N)
    {
        Ans++;
        return;
    }

    for(int i=0; i<N; i++)
    {
        if(Col[i] || Rd[i+c] || Ld[c-i+N-1]) continue;
        Col[i] = Rd[i+c] = Ld[c-i+N-1] = true;
        backtracking(c+1);
        Col[i] = Rd[i+c] = Ld[c-i+N-1] = false;
    }
}

int main()
{
    scanf("%d", &N);

    backtracking(0);

    printf("%d", Ans);
}
