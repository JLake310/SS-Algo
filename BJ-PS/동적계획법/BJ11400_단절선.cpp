#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 100001

using namespace std;

struct Data {
    int x, y;
    Data() {};
    Data(int x, int y) : x(x), y(y) {};

    bool operator<(const Data d) const {
        if (x == d.x) return (y > d.y);
        return (x > d.x);
    }
};

int V, E;
int a, b;
int order[100001];
priority_queue<Data> answer;
vector<int> v[100001];
int seq;

int dfs(int node, int parent) {

    if (order[node] != 0) return 0;

    seq++;
    order[node] = seq;
    int minOrder = INF;

    int vi;
    for (int i = 0; i < v[node].size(); i++) {
        vi = v[node].at(i);

        if (vi == parent) continue;

        if(order[vi] > 0){
            if (order[vi] < minOrder) {
                minOrder = order[vi];
            }
        }else{
            int cmp = dfs(vi, node);
            minOrder = min(minOrder, cmp);

            if (cmp > order[node]) {
                int a = vi;
                int b = node;
                if (a > b) {
                    int tmp = a;
                    a = b;
                    b = tmp;
                }
                answer.push(Data(a, b));
            }
        }
    }

    return min(minOrder, order[node]);
}

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;

    for (int i = 0; i <= V; i++) {
        order[i] = 0;
        v[i].clear();
    }

    for (int i = 0; i < E; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    seq = 0;

    dfs(1, 0);

    cout << answer.size() << endl;

    while(true){
        if (answer.empty()) break;
        Data d = answer.top();
        answer.pop();

        cout << d.x << " " << d.y << endl;
    }

    return 0;
}
