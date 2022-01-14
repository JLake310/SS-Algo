#include <iostream>
#include <algorithm>
#include <cstring>

#define INF 10001;

using namespace std;

int N, M;
int memory[100];
int cost[100];
int dp[100][10001];
int C;
int answer;

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> memory[i];
    }

    C = 0;
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
        C += cost[i];
    }

    answer = INF;
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= C; j++) {
            if (i == 0) {
                if (j >= cost[i]) {
                    dp[i][j] = memory[i];
                    if (memory[i] >= M) {
                        C = cost[i];
                        answer = cost[i];
                        break;
                    }
                }
            }
            else {
                if (j >= cost[i]) {
                    dp[i][j] = max(dp[i - 1][j - cost[i]] + memory[i], dp[i - 1][j]);
                    if (dp[i][j] >= M) {
                        C = j;
                        answer = j;
                        break;
                    }
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }

    cout << answer;

    return 0;
}
