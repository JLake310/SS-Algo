#include <iostream>
#include <queue>

using namespace std;

struct Data {
    int index;
    int speed;
    Data() {};
    Data(int index, int speed):index(index), speed(speed) {};
    bool operator<(const Data d) const {
        return speed < d.speed;
    }
};

int N;
int input;
long tree[1111111];
int arr[500001];
int treeIndex;
int answer[500001];
priority_queue<Data> pq;

void update(int node) {
    int nodeIndex = treeIndex + node - 1;
    while (true) {
        if (nodeIndex == 0) break;
        tree[nodeIndex] += 1;
        nodeIndex /= 2;
    }
}

long sum(int x, int y) {
    int left = treeIndex + x - 1;
    int right = treeIndex + y - 1;

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
        left /= 2;
        right /= 2;
    }

    return value;
}

int main(int argc, const char* argv[]) {

    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &input);
        pq.push(Data(i, input));
    }

    treeIndex = 1;
    while (true) {
        if (treeIndex >= N) break;
        treeIndex *= 2;
    }

    Data d;
    while (true) {
        if (pq.empty()) break;
        d = pq.top();
        pq.pop();
        answer[d.index] = sum(1, d.index) + 1;
        update(d.index);
    }

    for (int i = 1; i <= N; i++) {
        printf("%d\n", answer[i]);
    }

    return 0;
}
