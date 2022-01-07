#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
#define MOD 10007

int DP[MAXN+1][MAXN+1];

int main()
{
    int N, K;

    scanf("%d %d", &N, &K);

    DP[0][0] = 1;
    for(int i=1; i<=N; i++)
    {
        DP[i][0] = 1;
        for (int j=1; j<=i; j++)
        {
            DP[i][j] = (DP[i-1][j-1] + DP[i-1][j])%MOD;
        }
    }

    printf("%d", DP[N][K]);

    return 0;
}
