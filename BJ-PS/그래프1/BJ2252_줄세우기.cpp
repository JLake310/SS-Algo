#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
int a, b;
int indegree[32001];

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v[32001];
    queue<int> q;
    queue<int> answer;

    cin >> N >> M;

    memset(indegree, 0, (sizeof(indegree)));

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        indegree[b]++;
    }

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            answer.push(i);
            q.push(i);
        }
    }

    while (true) {
        if (q.empty()) break;
        int x = q.front();
        q.pop();
        for (int i = 0; i < v[x].size(); i++) {
            indegree[v[x].at(i)]--;
            if (indegree[v[x].at(i)] == 0) {
                q.push(v[x].at(i));
                answer.push(v[x].at(i));
            }
       }
    }

    for (int i = 0; i < N; i++) {
        cout << answer.front() << " ";
        answer.pop();
    }

    return 0;
}
