#include <bits/stdc++.h>

using namespace std;

#define MAXN 51
#define INF 1000000000

char MapInfo[MAXN][MAXN];
int MapH[MAXN][MAXN];
int Data[MAXN*MAXN];
bool Visit[MAXN][MAXN];
int N;
int StartC, StartR;//우체국(출발점)
int HouseCnt;//집갯수

int dc[8] = { 0,0,-1,1,-1,-1,1,1 };
int dr[8] = { -1,1,0,0,-1,1,1,-1 };

void dfs(int r, int c, int& minV, int& maxV, int& visitHcnt)
{
    //맵 바깥이거나 방문하였거나 범위내가 아니면,
    if (r<0 || r>=N || c<0 || c>=N || 
        Visit[r][c] || MapH[r][c]<minV || MapH[r][c]>maxV) return;

    //방문 flag 설정
    Visit[r][c] = true;
    //집이면...
    if(MapInfo[r][c]=='K') visitHcnt++;

    for(int i=0; i<8; i++)
    {
        int nR = r+dr[i];
        int nC = c+dc[i];
        dfs(nR, nC, minV, maxV, visitHcnt);
    }

    return;
}

bool canGo(int minV, int maxV)
{
    //visit 초기화
    memset(Visit, 0, sizeof(Visit));

    int visitHcnt = 0;

    dfs(StartR, StartC, minV, maxV, visitHcnt);
    //방문한 집의 개수가 전체 집의 개수와 동일하면
    if(visitHcnt==HouseCnt) return true;
    else return false;
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf(" %c", &MapInfo[i][j]);
            if(MapInfo[i][j]=='P')
            {
                StartR = i;
                StartC = j;
            }
            else if(MapInfo[i][j]=='K')
            {
                HouseCnt++;
            }
        }
    }

    int cnt = 0, ans = INF, uniqueCnt = 1, maxH = 0, minH = INF, maxHIdx, minHIdx;

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%d", &MapH[i][j]);
            Data[cnt++] = MapH[i][j];

            if(MapInfo[i][j]=='P' || MapInfo[i][j]=='K')
            {
                maxH = max(maxH, MapH[i][j]);
                minH = min(minH, MapH[i][j]);
            }
        }
    }

    sort(Data, Data+cnt);
    for(int i=1; i<cnt; i++)
    {
        //sort한 데이터를 unique하게 만든다.
        if(Data[i]!=Data[i-1]) Data[uniqueCnt++] = Data[i];
    }

    for(int i=0; i<uniqueCnt; i++)
    {
        if(Data[i]==maxH) maxHIdx = i;
        if(Data[i]==minH) minHIdx = i;
    }

    //투포인터
    int minIdx = 0, maxIdx = maxHIdx;//maxIdx 우체국/집 최대높이 Idx보다 작아질 수 없다.
    while(maxIdx<uniqueCnt)
    {
        while(minIdx<=minHIdx)
        {
            if(!canGo(Data[minIdx], Data[maxIdx])) break;
            ans = min(ans, Data[maxIdx]-Data[minIdx]);
            //만족하면 minIdx를 더해 범위를 좁힌다.
            minIdx++;
        }
        //만족할 수 없으면 maxIdx를 더해 범위를 늘린다.
        maxIdx++;
    }

    printf("%d", ans);

    return 0;
}
