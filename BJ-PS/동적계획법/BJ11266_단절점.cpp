#include <iostream>
#include <vector>
#include <algorithm>

#define INF 10001

using namespace std;

int V, E;
int a, b;
int order[10001];
bool answer[10001];
vector<int> v[10001];
int visit;

int dfs(int node, bool isRoot) {

    if (order[node] != 0) return 0;

    int child = 0;
    visit++;
    order[node] = visit;
    int minOrder = INF;

    int vi;
    for (int i = 0; i < v[node].size(); i++) {
        vi = v[node].at(i);

        if(order[vi] > 0){
            if (order[vi] < minOrder) {
                minOrder = order[vi];
            }
        }else{
            int cmp = dfs(vi, false);
            minOrder = min(minOrder, cmp);

            if (!isRoot) {
                if (cmp >= order[node]) {
                    answer[node] = true;
                }
            }
            child++;
        }
    }

    if (v[node].size() == 1) {
        return order[node];
    }

    if (isRoot) {
        if (child > 1) {
            answer[node] = true;
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
        answer[i] = false;
        v[i].clear();
    }

    for (int i = 0; i < E; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    visit = 0;

    for (int i = 1; i <= V; i++) {
        if (order[i] == 0) {
            dfs(i, true);
        }
    }

    int count = 0;
    for (int i = 1; i <= V; i++) {
        if (answer[i]) count++;
    }

    cout << count << endl;

    for (int i = 1; i <= V; i++) {
        if (answer[i]) cout << i << " ";
    }

    return 0;
}
