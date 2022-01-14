#include <iostream>
#include <algorithm>

#define MAX 16

using namespace std;

int N, W;
int input1, input2;
int dp[1001][1001];
int list[1001][2];

int dist(int type, int p1, int p2) {
    int x1, y1, x2, y2;

    x1 = list[p1][0];
    y1 = list[p1][1];
    x2 = list[p2][0];
    y2 = list[p2][1];

    if (p2 == 0) {
        if (type == 1) {
            x2 = 1;
            y2 = 1;
        }
        else {
            x2 = N;
            y2 = N;
        }
    }
    return (abs(x1 - x2) + abs(y1 - y2));
}

int dfs(int p1, int p2) {

    if (p1 == W || p2 == W) return 0;
    if (dp[p1][p2] > 0) return dp[p1][p2];

    int next = max(p1, p2) + 1;

    int v1 = dfs(next, p2) + dist(1, next, p1);
    int v2 = dfs(p1, next) + dist(2, next, p2);

    return dp[p1][p2] = min(v1, v2);
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> W;

    for (int i = 1; i <= W; i++) {
        cin >> list[i][0] >> list[i][1];
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = 0;
        }
    }

    cout << dfs(0, 0) << endl;

    int p1 = 0;
    int p2 = 0;
    for (int i = 1; i <= W; i++) {
        int d = dist(1, i, p1);
        if ((dp[p1][p2] - dp[i][p2]) == d) {
            p1 = i;
            cout << "1" << endl;
        }
        else {
            p2 = i;
            cout << "2" << endl;
        }
    }

    return 0;
}
