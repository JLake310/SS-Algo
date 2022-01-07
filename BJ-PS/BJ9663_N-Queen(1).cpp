#include <bits/stdc++.h>

using namespace std;

#define MAXN 15

int Col[MAXN];
int N, Ans = 0;

bool check(int row)
{
    for(int i=0; i<row; i++)
    {
        if(Col[i] == Col[row] || abs(Col[row] - Col[i]) == row - i)
            return false;
    }
    return true;
}

void backtracking(int c)
{
    if(c==N)
    {
        Ans++;
        return;
    }

    for(int i=0; i<N; i++)
    {
        Col[c] = i;
        if(check(c)) backtracking(c+1);
    }
}
int main()
{
    scanf("%d", &N);

    backtracking(0);

    printf("%d", Ans);
}
