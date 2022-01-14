#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[100001][5][5];
int arr[100001];

int move(int from, int to) {
    if (from == 0) return 2;
    if (from == to) return 1;
    return (4 - (abs(from - to) % 2));
}

int dfs(int n, int  x, int y) {
    if (n == N) return 0;

    if (dp[n][x][y] > 0) return dp[n][x][y];

    int left = dfs(n + 1, arr[n], y) + move(x, arr[n]);
    int right = dfs(n + 1, x, arr[n]) + move(y, arr[n]);

    return dp[n][x][y] = min(left, right);
}

int main(int argc, char** argv) {

    N = 0;
    while (true) {
        scanf("%d", &arr[N]);
        if (arr[N] == 0) break;
        N++;
    }

    cout << dfs(0, 0, 0);

    return 0;
}
