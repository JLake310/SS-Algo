#include <bits/stdc++.h>

using namespace std;

#define MAXN 51

int N, M, Ans;
char Data[MAXN][MAXN];//입력 데이터
bool Visit[MAXN][MAXN];//방문여부
int DP[MAXN][MAXN];//중복계산을 막기 위해 계산 결과 저장

//4가지 방향(왼쪽, 아래, 위, 오른쪽)
int dc[] = {-1, 0, 0, 1};
int dr[] = {0, -1, 1, 0};

bool dfs(int r, int c, int cnt)
{
    //무한번 움직일 수 있는 경우
    if(Ans==-1) return true;

    Ans = max(Ans, cnt);

    Visit[r][c] = true;
    //DP테이블에 계산 결과를 update하여 더 유리 한것이 계산된 것이라면 계산하지 않도록 한다.
    DP[r][c] = cnt;

    for(int i=0; i<4; i++)
    {
        int nr = r + dr[i]*(Data[r][c]-'0');//문자열로 된 숫자에서 '0' 문자를 빼면 int가 된다.(ASCII코드)
        int nc = c + dc[i]*(Data[r][c]-'0');

        //매트릭스 범위를 벗어나거나 구멍인것은 게임이 종료되므로 탐색을 진행하지 않는다.
        if(nr<0 || nr>=N || nc<0 || nc>=M || Data[nr][nc] == 'H') continue;

        //방문한 곳에 또 방문하려 한다면 무한번 움직일 수 있다는 의미
        if(Visit[nr][nc])
        {
            Ans = -1;
            return true;
        }

        //이미 계산된 것은 DP테이블에 기록되며 DP의 값이 cnt보다 크다면 
        //이미 더 길게 움직이는 것이 계산되어 있다.
        if(DP[nr][nc]>0 && cnt<DP[nr][nc]) continue;

        //무한번 움직일 수 있다면 dfs에서 true가 return된다
        if(dfs(nr, nc, cnt+1)) return true;
    }

    //돌아와서는 Visit Flag를 false로 설정
    Visit[r][c] = false;
    return false;
}

int main()
{
    scanf("%d %d", &N, &M);

    for(int i=0; i<N; i++) scanf("%s", Data[i]);//문자열로 입력을 받는다.

    dfs(0, 0, 1);//0,0 좌표에서 출발
    printf("%d", Ans);
}
