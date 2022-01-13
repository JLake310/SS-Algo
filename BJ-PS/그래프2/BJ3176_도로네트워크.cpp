#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii; 

struct Data {
    int n;
    int w;
    Data() {};
    Data(int n, int w) : n(n), w(w) {};
};

struct Output {
    int shortest;
    int longest;
    Output() {};
    Output(int shortest, int longest) : shortest(shortest), longest(longest) {};
};

int N, M;
vector<Data> v[100001];
int depth[100001];
int dp[21][100001];
int dpMax[21][100001];
int dpMin[21][100001];

Output lca(int x, int y) {

    int longest = 0;
    int shortest = 987654321;

    if (depth[x] != depth[y]) {
        if (depth[x] > depth[y]) swap(x, y);

        for (int i = 20; i >= 0; i--) {
            if (depth[y] - depth[x] >= (1 << i)) {
                longest = max(dpMax[i][y], longest);
                shortest = min(dpMin[i][y], shortest);
                y = dp[i][y];
            }
        }
    }

    if (x != y) {
        for (int i = 20; i >= 0; i--) {
            if (dp[i][x] != dp[i][y]) {

                longest = max(dpMax[i][x], longest);
                shortest = min(dpMin[i][x], shortest);
                x = dp[i][x];

            longest = max(dpMax[i][y], longest);
                shortest = min(dpMin[i][y], shortest);
                y = dp[i][y];
            }
        }

        longest = max(dpMax[0][x], longest);
        longest = max(dpMax[0][y], longest);
        shortest = min(dpMin[0][x], shortest);
        shortest = min(dpMin[0][y], shortest);
    }

    return Output(shortest, longest);
}

void bfs(int root) {
    queue<pii> q;
    q.push(pii(root, 0));

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int i = 0; i < v[node].size(); i++) {
            Data vi = v[node].at(i);
            int next = vi.n;
            int dist = vi.w;
            if (next == parent) continue;
            depth[next] = depth[node] + 1;
            dp[0][next] = node;
            dpMin[0][next] = dist;
            dpMax[0][next] = dist;
            q.push(pii(next, node));
        }
    }
}

void setDP() {
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= N; j++) {
            dpMin[i][j] = min(dpMin[i - 1][j], dpMin[i - 1][dp[i - 1][j]]);
            dpMax[i][j] = max(dpMax[i - 1][j], dpMax[i - 1][dp[i - 1][j]]);
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int a, b, c;
    for (int i = 1; i < N; i++) {
        cin >> a >> b >> c;
        v[a].push_back(Data(b, c));
        v[b].push_back(Data(a, c));
    }

    for (int i = 1; i <= 20; i++) {
        for (int j = 0; j <= N; j++) {
            dpMin[i][j] = 987654321;
            dp[i][j] = 0;
            dpMax[i][j] = 0;
        }
    }

    bfs(1);

    setDP();

    cin >> M;
    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        Output answer = lca(x, y);
        cout << answer.shortest << " " << answer.longest << "\n";
    }

    return 0;
}
