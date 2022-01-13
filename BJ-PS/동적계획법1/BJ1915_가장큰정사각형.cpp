#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int N, M;
int dp[1001][1001];
string str;

int answer;
int getMin(int a, int b, int c) {
    int n = a;
    if (n > b) n = b;
    if (n > c) n = c;
    return n;
}

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    answer = 0;

    for (int i = 1; i <= N; i++) {
        cin >> str;
        for (int j = 1; j <= M; j++) {

            dp[i][j] = str.at(j - 1) - '0';

            if (dp[i][j] == 1) {
                dp[i][j] += getMin(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
                answer = max(answer, dp[i][j]);
            }
        }
    }

    cout << (answer * answer);

    return 0;
}
