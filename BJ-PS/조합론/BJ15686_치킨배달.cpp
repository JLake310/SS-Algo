//조합응용
#include <bits/stdc++.h>

using namespace std;

#define MAXN 50
#define MAXM 13
#define INF 987654321

struct stPos
{
    int r, c;
}; 

int N, M, Ans;
int Top, HouseCnt, ChickenCnt;
stPos House[2*MAXN+1];//집의 개수는 2N
stPos Chicken[MAXM+1];//치킨집
int Selected[MAXM+1];//선택된 치킨집의 index

void calcData()
{
    int sum = 0;
    for(int i=0; i<HouseCnt; i++)
    {
        int minDist = INF, dist;
        //i번째 집에서 선택된 치킨집들 까지의 거리 중 최소 치킨거리 계산
        for(int j=0; j<Top; j++)
        {
            dist = abs(House[i].r-Chicken[Selected[j]].r)
                + abs(House[i].c-Chicken[Selected[j]].c);
            minDist = min(minDist, dist);
        }
        sum += minDist;//i번째 집의 최소 치킨거리
    }

    Ans = min(Ans, sum);
}

void backtracking(int start)
{
    if(Top == M)//모두 선택했다면
    {
        calcData();
        return;
    }

    for(int i=start; i<ChickenCnt; i++)
    {
        if(ChickenCnt-i < M-Top) break;//가지치기
        Selected[Top++] = i;//선택된 치킨집
        backtracking(i+1);
        Top--;
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    Ans = INF;

    for(int i=0, data; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%d", &data);
            if(data==1)
            {
                House[HouseCnt].r = i;
                House[HouseCnt++].c = j;
            }
            else if(data==2)
            {
                Chicken[ChickenCnt].r = i;
                Chicken[ChickenCnt++].c = j;
            }
        }
    }

    backtracking(0);

    printf("%d", Ans);

    return 0;
}
