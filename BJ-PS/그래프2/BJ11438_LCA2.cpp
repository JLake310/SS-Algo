#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#include MAX = 20;
using namespace std;
int N, M;
int a, b;
int dp[MAX + 1][100001];
int depth[100001];
bool isVisited[100001];
vector<int> v[100001];

void dfs(int n, int d) {

    isVisited[n] = true;
    depth[n] = d;
    int vi;
    for (int i = 0; i < v[n].size(); i++) {
        vi = v[n].at(i);
        if (isVisited[vi]) continue;
        dp[0][vi] = n;
        dfs(vi, d + 1);
    }
}
void setDP() {
    for (int i = 1; i < MAX; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
}
int lca(int x, int y) {
    if (depth[x] > depth[y])
        swap(x, y);
    for (int i = MAX; i >= 0; i--) {
        if (depth[y] - depth[x] >= (1 << i))
            y = dp[i][y];
    }
    if (x == y) return x;

    for (int i = MAX; i >= 0; i--) {
        if (dp[i][x] != dp[i][y]) {
            x = dp[i][x];
            y = dp[i][y];
        }
    }
    return dp[0][x];
}
int main() {
    scanf("%d", &N);

    for (int i = 1; i < N; i++) {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(isVisited, 0, sizeof(isVisited));
    dfs(1, 1);

    setDP();

    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}
