// Refernce : https://www.geeksforgeeks.org/prefix-sum-array-implementation-applications-competitive-programming

/*
Range of the obstacle

start point    -> +1
end point + 1  -> -1
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200001
#define MAXH 500001

int N, H, MinHuddle, MinCnt;
int Cnt[MAXH];

int main()
{
    MinHuddle = MAXN;
    scanf("%d %d", &N, &H);
    int d;
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &d);
        if((i&1) == 0)
        {
            Cnt[0]++;
            Cnt[d]--;
        }
        else
        {
            Cnt[H-d]++;
        }
    }

    int cntTemp = 0;
    for(int i = 0; i < H; i++)
    {
        cntTemp += Cnt[i];
        if(cntTemp < MinHuddle)
        {
            MinHuddle = cntTemp;
            MinCnt = 1;
        }
        else if(cntTemp == MinHuddle)
        {
            MinCnt++;
        }
    }   

    printf("%d %d\n", MinHuddle, MinCnt);

    return 0;
}
