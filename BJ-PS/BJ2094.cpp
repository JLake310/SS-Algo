#include <bits/stdc++.h>

using namespace std;

#define MAXN 50002
#define MAXK 17

int Year[MAXN];
int IDT[1<<MAXK];
int N, M, B;

void initIDT()
{
    for(int i=B-1; i>0; i--)
    {
        IDT[i] = max(IDT[i<<1], IDT[(i<<1)|1]);
    }
}

int binarySearch(int key)
{
    int lb = -1, ub = N-1, m;
    while(lb+1 < ub)
    {
        m = lb+(ub-lb)/2;
        if(Year[m] >= key) ub = m;
        else lb = m;
    }

    //찾는 년도가 데이터 보다 큰 년도 일 경우 N을 return
    return Year[ub]>=key? ub : N;
}

int lgMax(int l, int r)
{
    if(l>=N || r>=N) return 0;//범위 check하여 범위 내가 아니면 0을 return
    l += (B); r += (B);
    int maxV = 0;
    while(l<=r)
    {
        if((l&1)==1) maxV = max(maxV, IDT[l]);
        if((r&1)==0) maxV = max(maxV, IDT[r]);

        l = (l+1)>>1;
        r = (r-1)>>1;
    }
    return maxV;
}

int solve(int Y, int X)
{
    int yIdx = binarySearch(Y);
    int xIdx = binarySearch(X);

    bool existY = (yIdx<N && Year[yIdx]==Y);
    bool existX = (xIdx<N && Year[xIdx]==X);

    // Y < Z < X를 만족하는 최대 강수량
    int zRain = lgMax(binarySearch(Y+1), xIdx-1);
    // X년도의 강수량은 Y년도의 강수량 이하인지 확인 
    if(existX && existY && IDT[xIdx+B] > IDT[yIdx+B]) return 0;
    //Y < Z < X를 만족하는 모든 Z들에 대해서, Z년도의 강수량은 X년도보다 적은지 확인 
    else if(existX && zRain >= IDT[xIdx+B]) return 0;
    else if(existY && zRain >= IDT[yIdx+B]) return 0;
    // Y년도, X년도, 그리고 그 사이의 모든 년도들의 강수량에 대한 정보가 알려져 있는지 확인 
    else if(existY && existX && xIdx-yIdx == X-Y) return 1;
    else return 2;
}

int main()
{
    scanf("%d", &N);
    for(B=1; B<N; B<<=1);

    for(int i=0; i<N; i++) scanf("%d %d", &Year[i], &IDT[B+i]);

    initIDT();

    scanf("%d", &M);

    int Y, X;
    while(M--)
    {
        scanf("%d %d", &Y, &X);

        int ret = solve(Y, X);
        if(ret==0) printf("false\n");
        else if(ret==1) printf("true\n");
        else printf("maybe\n");
    }

    return 0;
}
