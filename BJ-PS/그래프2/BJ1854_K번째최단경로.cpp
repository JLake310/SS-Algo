#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Data {
    int n, w;
    Data() {};
    Data(int n, int w) : n(n), w(w) {};

    bool operator<(const Data d) const {
        return w > d.w;
    }
};

int N, M, K;
int a, b, c;
vector<Data> v[1001];
priority_queue<int> pq[1001];
priority_queue<Data> q;

void init() {
    priority_queue<int> emptyPQ;
    priority_queue<Data> emptyQ;

    for (int i = 0; i <= N; i++) {
        v[i].clear();
        swap(pq[i], emptyPQ);
    }
    swap(q, emptyQ);
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    init();

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        v[a].push_back(Data(b, c));
    }

    q.push(Data(1, 0));
    pq[1].push(0);

    while (true) {
        if (q.empty()) break;
        Data d = q.top();
        q.pop();
        Data vi;

        for (int i = 0; i < v[d.n].size(); i++) {
            vi = v[d.n].at(i);
            if (pq[vi.n].size() < K) {
                pq[vi.n].push(d.w + vi.w);
                q.push(Data(vi.n, (d.w + vi.w)));
            }
            else {
                int cmp = pq[vi.n].top();
                if (cmp > d.w + vi.w) {
                    pq[vi.n].pop();
                    pq[vi.n].push(d.w + vi.w);
                    q.push(Data(vi.n, (d.w + vi.w)));
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (pq[i].size() < K) {
            cout << -1;
        }
        else {
            cout << pq[i].top();
        }
        cout << endl;
    }

    return 0;
}
