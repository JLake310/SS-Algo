#include <bits/stdc++.h>

using namespace std;

#define MAXN 51
#define INF 1000000000

struct pos
{
    int r, c;
};

char MapInfo[MAXN][MAXN];
int MapH[MAXN][MAXN];
int Data[MAXN*MAXN];
bool Visit[MAXN][MAXN];
int N;
int StartR, StartC;//우체국(출발점)
int HouseCnt;//집갯수

int dc[8] = { 0,0,-1,1,-1,-1,1,1 };
int dr[8] = { -1,1,0,0,-1,1,1,-1 };

bool canGo(int minV, int maxV)
{
    int visitHouseCnt = 0, r, c, nR, nC;
    //visit 초기화
    memset(Visit, 0, sizeof(Visit));

    queue<pos> q;
    q.push({StartR, StartC});

    while(!q.empty())
    {
        r = q.front().r;
        c = q.front().c;
        q.pop();

        //맵 바깥이거나 방문하였거나 범위내가 아니면,
        if (r<0 || r>=N || c<0 || c>=N || 
            Visit[r][c] || 
            MapH[r][c]<minV || MapH[r][c]>maxV) continue;

        Visit[r][c] = true;

        if(MapInfo[r][c]=='K')
        {
            visitHouseCnt++;
            if(visitHouseCnt==HouseCnt) return true;
        }

        for(int i=0; i<8; i++)
        {
            nR = r+dr[i];
            nC = c+dc[i];

            q.push({nR, nC});
        }
    }

    return false;
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf(" %c", &MapInfo[i][j]);
            if(MapInfo[i][j]=='P')//우체국
            {
                StartR = i;
                StartC = j;
            }
            else if(MapInfo[i][j]=='K')
            {
                HouseCnt++;//집 갯수 count
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
                maxH = max(maxH, MapH[i][j]);//최대높이
                minH = min(minH, MapH[i][j]);//최소높이
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
        if(Data[i]==maxH) maxHIdx = i;//최대높이에 해당하는 Idx
        if(Data[i]==minH) minHIdx = i;//최소높이에 해당하는 Idx
    }

    //투포인터
    int minIdx = 0, maxIdx = maxHIdx;//maxIdx 우체국/집 최대높이 Idx보다 작아질 수 없다.
    while(maxIdx<uniqueCnt)
    {
        while(minIdx<=minHIdx)//minIdx는 우체국/집 최소 높이Idx보다 커질 수 없다.
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
