#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

struct Data {
    int n;
    int w;
    Data() {};
    Data(int n, int w) : n(n), w(w) {};

    bool operator< (const Data d) const {
        return w > d.w;
    }
};

int N, M;
int S, D;
int u, v, p;
vector<Data> path[500];
int dist[500];
bool isPath[500][500];
vector<int> par[500];

void dijkstra(int seq) {
    priority_queue<Data> pq;

    pq.push(Data(S, 0));
    dist[S] = 0;

    while (true) {
        if (pq.empty()) break;
        Data d = pq.top();
        pq.pop();

        Data nextD;
        for (int i = 0; i < path[d.n].size(); i++) {
            nextD = path[d.n].at(i);

            if (isPath[d.n][nextD.n]) continue;

            if (dist[nextD.n] > dist[d.n] + nextD.w) {
                dist[nextD.n] = dist[d.n] + nextD.w;
                pq.push(Data(nextD.n, dist[nextD.n]));
                if(seq == 1){
                    par[nextD.n].clear();
                    par[nextD.n].push_back(d.n);
                }
            }
            else {
                if (seq == 1){
                    if (dist[nextD.n] == dist[d.n] + nextD.w) {
                        par[nextD.n].push_back(d.n);
                    }
                }
            }
        }
    }
}

void removePath(int start, int node) {

    if (node == start) return;

    for (int i = 0; i < par[node].size(); i++) {
        if (isPath[par[node].at(i)][node]) continue;
        isPath[par[node].at(i)][node] = true;
        removePath(start, par[node].at(i));
    }
}

int main(int argc, char** argv) {

    while (true) {
        scanf_s("%d %d", &N, &M);

        if (N == 0 && M == 0) break;

        scanf_s("%d %d", &S, &D);

        for (int i = 0; i < N; i++) {
            dist[i] = INF;
            path[i].clear();
            for (int j = 0; j < N; j++) {
                isPath[i][j] = false;
            }
        }

        for (int i = 0; i < M; i++) {
            scanf_s("%d %d %d", &u, &v, &p);
            path[u].push_back(Data(v, p));
        }

        dijkstra(1);

        if (dist[D] == INF) {
            printf("%d\n", -1);
            continue;
        }

        removePath(S, D);

        for (int i = 0; i < N; i++) {
            dist[i] = INF;
        }

        dijkstra(2);

        if (dist[D] == INF) {
            printf("%d\n", -1);
        }
        else {
            printf("%d\n", dist[D]);
        }
    }

    return 0;
}
