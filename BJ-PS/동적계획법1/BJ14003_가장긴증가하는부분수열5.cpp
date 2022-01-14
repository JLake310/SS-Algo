#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int arr[1000000];
int idx[1000000];
vector<int> v;
vector<int> vReverse;

int main(int argc, char** argv) {

    scanf_s("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf_s("%d", &arr[i]);
    }

    v.push_back(arr[0]);
    idx[0] = 1;

    for (int i = 1; i < N; i++) {

        if (arr[i] > v.at(v.size() - 1)) {
            v.push_back(arr[i]);
            idx[i] = v.size();
        }
        else {
            int left = 0;
            int right = v.size() - 1;

            while (true) {
                if (left >= right) break;
                int mid = (left + right) / 2;

                if (v.at(mid) >= arr[i]) {
                    right = mid;
                }
                else {
                    left = mid + 1;
                }
            }
            v[left] = arr[i];
            idx[i] = left + 1;
        }
    }

    printf("%d\n", (int)v.size());

    vReverse.clear();
    int K = v.size();

    for (int i = N - 1; i >= 0; i--) {
        if (K == 0) break;
        if (K == idx[i]) {
            vReverse.push_back(arr[i]);
            K--;
        }
    }

    while (true) {
        if (vReverse.empty()) break;
        printf("%d ", vReverse.at(vReverse.size() - 1));
        vReverse.pop_back();
    }

    return 0;
}
