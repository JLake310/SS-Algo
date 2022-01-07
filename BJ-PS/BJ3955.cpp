#include <bits/stdc++.h>

using namespace std;

// returns a (mod m)
int mod(int a, int m)
{
    // ensure positive answer
    return ((a%m) + m) % m;
}

// pass x and y by ref
int extEuclid(int a, int b, int &x, int &y)
{
    int xx = y = 0;
    int yy = x = 1;
    // repeats until b == 0
    while (b)
    {
        int q = a/b;
        int t = b; b = a%b; a = t;
        t = xx; xx = x-q*xx; x = t;
        t = yy; yy = y-q*yy; y = t;
    }
    // returns gcd(a, b)
    return a;
}

// returns b^(-1) (mod m)
int modInverse(int b, int m)
{
    int x, y;
    // to get b*x + m*y == d
    int d = extEuclid(b, m, x, y);
    if (d != 1) return -1;// to indicate failure
    // b*x + m*y == 1, now apply (mod m) to get b*x == 1 (mod m)
    return mod(x, m);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int K, C;
        long long ans;
        scanf("%d %d", &K, &C);
        //C*y = K*x+1 을 만족하는것
        //즉, C*y ≡ 1(mod K)
        //따라서, 역원을 구하는 문제가 됨.
        ans = modInverse(C, K);
        if(ans==-1)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }

        //K명에게 나누어주려면 Cx > K 이어야 함
        while(C*ans<=K) ans+=K;
        if(ans>1e9) printf("IMPOSSIBLE\n");
        else printf("%lld\n", ans);
    }

    return 0;
}
