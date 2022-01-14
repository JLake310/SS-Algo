#include <iostream>
#include <algorithm>
#define INF 9876543210

using namespace std;

int N;
int matrix[500][2];
long long dp[500][500];
long long cost;

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> matrix[i][0] >> matrix[i][1];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N - i; j++) {
            dp[j][j + i] = INF;
            for (int k = 0; k < i; k++) {
                cost = dp[j][j + k] + dp[j + k + 1][j + i] + (matrix[j][0] * matrix[j + k][1] * matrix[j + i][1]);
                dp[j][j + i] = min(dp[j][j + i], cost);
            }
        }
    }
    cout << dp[0][N - 1];

    return 0;
}
