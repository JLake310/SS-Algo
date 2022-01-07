#include <bits/stdc++.h>

using namespace std;

#define MAXN 100
#define MAXK 1000000000

int DP[MAXN*2+1][MAXN+1];

int main()
{
    int N, M, K;

    scanf("%d %d %d", &N, &M, &K);

    N += M;

    DP[0][0] = 1;//0개에서 0개를 고르는 경우는 1로 설정
    for(int i=1; i<=N; i++)
    {
        DP[i][0] = 1;
        for (int j=1; j<=i && j<=M; j++)
        {
            DP[i][j] = DP[i-1][j-1] + DP[i-1][j];
            //overflow가 되지 않도록 최대값을 고정 시킨다.
            if(DP[i][j] > MAXK) DP[i][j] = (MAXK+1);
        }
    }

    //N에서 C개를 고르는 경우가 K보다 작으면 불가능하다.
    if(DP[N][M]<K)
    {
        printf("-1");
        return 0;               
    }

    while(N)
    {
        if(DP[N-1][M] >= K) printf("a");
        else
        {
            printf("z");
            K -= DP[N-1][M--];
        }
        N--;
    } 

    return 0;
}
