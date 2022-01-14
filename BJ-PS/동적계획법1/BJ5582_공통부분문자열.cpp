#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

string str1;
string str2;
int answer;

int dp[4001][4001];

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> str1;
    cin >> str2;

    memset(dp, 0, sizeof(dp));
    answer = 0;

    for (int i = 1; i <= str1.length(); i++) {
        for (int j = 1; j <= str2.length(); j++) {
            if (str1.at(i - 1) == str2.at(j - 1)) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                answer = max(answer, dp[i][j]);
            }
        }
    }
    cout << answer << endl;
    return 0;
}
