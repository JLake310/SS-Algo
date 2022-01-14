#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Data {
    int seq;
    int index;
    Data() {};
    Data(int seq, int index) : seq(seq), index(index) {};
    bool operator<(const Data d) const {
        return index > d.index;
    }
};

struct Pair {
    int x;
    int y;
    Pair() {};
    Pair(int x, int y) : x(x), y(y) {};
    bool operator<(const Pair p) const {
        return y < p.y;
    }
};

int N;
int intput;
long tree[1111111];
int input;
int treeIndex;
long answer;
priority_queue<Data> pq1, pq2;
priority_queue<Pair> pq;

void update(int node) {
    int nodeIndex = treeIndex + node - 1;
    while (true) {
        if (nodeIndex == 0) break;
        tree[nodeIndex] += 1;
        nodeIndex >>= 1;
    }
}

long sum(int node) {
    int left = treeIndex;
    int right = treeIndex + node - 1;

    long value = 0;

    while (true) {
        if (left > right) break;
        if (left % 2 == 1) {
            value += tree[left];
            left++;
        }
        if (right % 2 == 0) {
            value += tree[right];
            right--;
        }
        left >>= 1;
        right >>= 1;
    }

    return value;
}

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    treeIndex = 1;
    while (true) {
        if (treeIndex >= N) break;
        treeIndex <<= 1;
    }

    for (int i = 1; i <= N; i++) {
        cin >> input;
        pq1.push(Data(i, input));
    }

    for (int i = 1; i <= N; i++) {
        cin >> input;
        pq2.push(Data(i, input));
    }

    int px, py;
    while (true) {
        if (pq1.empty() || pq2.empty()) break;
        px = pq1.top().seq;
        py = pq2.top().seq;
        pq1.pop();
        pq2.pop();
        pq.push(Pair(px, py));
    }

    memset(tree, 0, sizeof(tree));

    while (true) {
        if (pq.empty()) break;
        Pair p = pq.top();
        pq.pop();
        answer += sum(p.x);
        update(p.x);
    }

    cout << answer;

    return 0;
}
