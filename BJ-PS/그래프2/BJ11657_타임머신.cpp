#include <iostream>

#define INF 9876543210

using namespace std;

struct Data {
    int a, b, c;
    Data() {};
    Data(int a, int b, long long c) : a(a), b(b), c(c) {};
};

int N, M;
int a, b, c;
long long dist[501];
Data list[6000];

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        list[i] = Data(a, b, c);
    }

    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }

    dist[1] = 0;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dist[list[j].a] == INF) continue;
            if (dist[list[j].b] > dist[list[j].a] + list[j].c) {
                dist[list[j].b] = dist[list[j].a] + list[j].c;
            }
        }
    }
    bool isCycle = false;

    for (int j = 0; j < M; j++) {
        if (dist[list[j].a] == INF) continue;
        if (dist[list[j].b] > dist[list[j].a] + list[j].c) {
            isCycle = true;
            break;
        }
    }

    if (isCycle) {
        cout << -1 << endl;
    }
    else {
        for (int i = 2; i <= N; i++) {
            if (dist[i] == INF) {
                cout << -1 << endl;
            }
            else {
                cout << dist[i] << endl;
            }
        }
    }

    return 0;
}
