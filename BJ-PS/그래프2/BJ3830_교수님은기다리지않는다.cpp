#include <iostream>

int N, M;
int a, b;
long long c;
char cmd;
int parent[100001];
long long weight[100001];

int find(int x) {
    if (x == parent[x])return x;
    int par = find(parent[x]);
    weight[x] += weight[parent[x]];
    return parent[x] = par;
}

void uni(int x, int y, long long z) {
    int px = find(x);
    int py = find(y);
    if (px != py) {
        parent[px] = py;
        weight[px] = weight[y] - weight[x] + z;
    }
}

void init() {
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
        weight[i] = 0;
    }
}

int main(int argc, char** argv) {

    while (true) {
        scanf_s("%d %d", &N, &M);
        if (N == 0 && M == 0) return 0;

        init();

        for (int i = 0; i < M; i++) {
            scanf_s(" %c", &cmd);
            if (cmd == '!') {
                scanf_s("%d %d %lld", &a, &b, &c);
                uni(a, b, c);
            }
            else {
                scanf_s("%d %d", &a, &b);
                if (find(a) == find(b)) {
                    printf("%lld\n", weight[a] - weight[b]);
                }
                else {
                    printf("UNKNOWN\n");
                }
            }
        }
    }
}
