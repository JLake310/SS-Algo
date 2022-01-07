#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000

bool Visit[MAXN+1];//소수:false, 소수 아님:true
int Prime[MAXN+1];
int DP[MAXN+1];
int PrimeCnt;

int eulerPhi(int n)
{
    // start from ans = N
    int ans = n;
    for(int i = 0; i<PrimeCnt && Prime[i]*Prime[i]<=n; i++)
    {
        //count unique
        if (n%Prime[i]==0) ans-=ans/Prime[i];
        // prime factor
        while (n%Prime[i] == 0) n/=Prime[i];
    }
    // last factor
    if (n!=1) ans -= ans/n;
    return ans;
}

int main()
{
    for(int i=2; i<=MAXN; i++)
    {
        if(Visit[i]) continue;

        Prime[PrimeCnt++] = i;

        for(int j=i*i; j<=MAXN; j+=i) Visit[j] = true;
    }

    DP[1] = 3;
    for(int i=2; i<=MAXN; i++)
    {
        DP[i] = DP[i-1]+eulerPhi(i)*2;
    }

    int T, N;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        printf("%d\n", DP[N]);
    }

    return 0;
}
