#include <bits/stdc++.h>

using namespace std;

#define MAXSIZE 1000000000

long long X, Y;//숫자 범위는 10억이지만 100을 곱해야 하므로 long long으로 선언

bool fmin(int v)
{
    //v만큼 게임을 했을 때 승률이 변하는지 확인
    if(Y*100/X < (Y+v)*100/(X+v)) return true;
    else return false;
}

int main()
{
    int lb=0, ub = MAXSIZE, m;
    scanf("%lld %lld", &X, &Y);

    //승률이 99% 이상이라면, 소수점은 버리기 때문에 아무리 게임을 많이해도 승률이 변하지 않는다.
    if(Y*100/X >= 99)
    {
        printf("-1");
        return 0;
    }

    while(lb+1 < ub)
    {
        m = lb+(ub-lb)/2;
        if(fmin(m)) ub = m;
        else lb = m;
    }

    printf("%d", ub);

    return 0;
}
