#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

int Data[MAXN+1];

int main()
{
    int N, S;

    scanf("%d %d", &N, &S);

    for(int i=0; i<N; i++) scanf("%d", &Data[i]);

    int left=0, right=0, sum=0, ans=N+1;

    while(true)
    {
        if(sum>=S)//부분합이 S이상이면...
        {
            ans = min(ans, right-left);
            //left를 빼주고 left 포인트를 오른쪽으로 옮긴다.
            sum -= Data[left++];
        }
        else if(right==N) break;//끝에 도달하면 종료
        else
        {
            //부분합이 S 미만일 경우 right를 더해주고 right 포인트를 오른쪽으로 옮긴다.
            sum += Data[right++];
        }
    }

    printf("%d", ans==N+1?0:ans);

    return 0;
}
