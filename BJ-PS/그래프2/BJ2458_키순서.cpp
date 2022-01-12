#include <iostream>

#define INF 987654321

using namespace std;

int N, M;
int a, b;
int dp[501][501];
int answer = 0;

int main(int argc, char** argv) {

    cin >> N;
    cin >> M;
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = INF;
        }
    }
    
    while(M--){
        scanf("%d %d, &a, &b);
        dp[a][b] = 0;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) continue;
                if (dp[i][k] == INF || dp[k][j] == INF) continue;
                if (dp[i][j] > dp[i][k] + dp[k][j]) dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= N; i++) {
        count = 0;
        for (int j = 1; j <= N; j++) {
            if (i == j) count++;
            if (dp[i][j] == 0 || dp[j][i] == 0) count++;
        }
        if (count == N) answer++;
    }

    printf("%d\n", answer);

    return 0;
}
