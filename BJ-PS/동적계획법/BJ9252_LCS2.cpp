#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

string str1;
string str2;
int answer;

int dp[1001][1001];
vector<char> v;

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
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    answer = dp[str1.length()][str2.length()];

    cout << answer << endl;

    if (answer > 0) {
        int x = str1.length();
        int y = str2.length();
        v.clear();

        while (true) {
            if (x == 0 || y == 0) break;
            if (str1[x - 1] == str2[y - 1]) {
                v.push_back(str1[x - 1]);
                x--;
                y--;
            }
            else {
                if (dp[x][y] == dp[x - 1][y]) {
                    x--;
                }
                else if (dp[x][y] == dp[x][y - 1]) {
                    y--;
                }
            }
        }
        while (true) {
            if (v.empty()) break;
            cout << v.at(v.size() - 1);
            v.pop_back();
        }
    }

    return 0;
}
