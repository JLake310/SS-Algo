//순열 응용
#include <bits/stdc++.h>

using namespace std;

#define MAXN 10

int Card[MAXN];
bool Visit[MAXN];
set<string> S;
int N, K;

void backtracking(int index, string numStr)
{
    if(index == K)
    {
        S.insert(numStr);
        return ;
    }

    for(int i=0; i<N; i++)
    {
        if(Visit[i]==false)
        {
            Visit[i]=true;
            backtracking(index+1, numStr + to_string(Card[i]));
            Visit[i]=false;
        }
    }
}

int main()
{
    scanf("%d %d", &N, &K);

    for(int i=0; i<N; i++) scanf("%d", &Card[i]);

    backtracking(0, "");//index, numStr

    printf("%d", (int)S.size());

    return 0;
}
