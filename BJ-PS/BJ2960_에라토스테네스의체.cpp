#include <bits/stdc++.h>

using namespace std;

#define MAXN 1001

bool Visit[MAXN];//소수:false, 소수 아님:true

int main()
{
    int N, K = 0, cnt = 0;
    scanf("%d %d", &N, &K);

    for(int i=2; i<=N; i++)
    {
        if(Visit[i]) continue;

        for(int j=i; j<=N; j+=i)
        {
            if(!Visit[j])
            {
                if(++cnt == K)
                {
                    printf("%d", j);
                    return 0;
                }
                Visit[j] = true;
            }
        }
    }

    return 0;
}
