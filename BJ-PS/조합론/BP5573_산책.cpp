#include <bits/stdc++.h>

using namespace std;

#define MAXHW 1000

int Map[MAXHW+2][MAXHW+2];
int DP[MAXHW+2][MAXHW+2];//방문하는 횟수

int main()
{
    int H, W, N;

    scanf("%d %d %d", &H, &W, &N);

    for(int i=1; i<=H; i++)
        for(int j=1; j<=W; j++)
            scanf("%d", &Map[i][j]);

    DP[1][1] = N-1;
    for(int i=1; i<=H; i++)
    {
        for(int j=1; j<=W; j++)
        {
            //DP[i][j]에 n번 존재하면, DP[i+1][j], DP[i][j+1]에 n/2번 존재한다.
            DP[i+1][j] += DP[i][j]/2;
            DP[i][j+1] += DP[i][j]/2;

            //DP[i][j]가 아래이면 DP[i+1][j]에 1이 더하고, 
            //오른쪽이면 DP[i][j+1]에 1을 더한다.
            if(DP[i][j]%2 ==1)
            {
                if(Map[i][j]==0) DP[i+1][j]++;//아래
                else DP[i][j+1]++;//오른쪽
            }

            //Map에 방향 반영
            Map[i][j] = (Map[i][j] +DP[i][j])%2;
        }
    }

    //마지막 N번째 탐색
    int r = 1, c = 1;
    while(r<=H && c<=W)
    {
        if(Map[r][c]==1) c++;
        else r++;
    }

    printf("%d %d", r, c);

    return 0;
}
