#include <bits/stdc++.h>

using namespace std;

#define MAXN 4000001

bool Visit[MAXN];//소수:false, 소수 아님:true
int Prime[MAXN];

int main()
{
    int N, primeCnt = 0;
    scanf("%d", &N);

    for(int i=2; i<=N; i++)
    {
        if(Visit[i]) continue;

        Prime[primeCnt++] = i;

        for(long long j=(long long)i*i; j<=N; j+=i) Visit[j] = true;
    }

    //투포인터
    int l = 0, r = 0, cnt = 0, sum = 0;

    while(true)
    {
        if(sum >= N) sum -= Prime[l++];
        else if(r == primeCnt) break;
        else sum += Prime[r++];

        if(sum == N) cnt++;
    }

    printf("%d", cnt);

    return 0;
}
