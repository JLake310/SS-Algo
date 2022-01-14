#include <iostream>
#include <cstring>

using namespace std;

int N;
int map[500][500];
int dp[500][500];
int answer;

int main(int argc, char** argv) {

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i + 1; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    memset(dp, -1, sizeof(dp));

    dp[0][0] = map[0][0];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][j] = map[i][j] + dp[i - 1][j];
            }
            else if (j == i) {
                dp[i][j] = map[i][j] + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = map[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
    }

    answer = -1;

    for (int i = 0; i < N; i++) {
        if (dp[N - 1][i] > answer) answer = dp[N - 1][i];
    }

    printf("%d\n", answer);

    return 0;
}
