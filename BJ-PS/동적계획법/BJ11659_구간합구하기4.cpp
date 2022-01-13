#include <iostream>
#include <algorithm>

using namespace std;

int N, M, a, b;
int dp[100001];

int main(int argc, char** argv) {
	
	scanf("%d %d", &N, &M);
	dp[0] = 0;
	for(int i=0;i<N;i++){
		int tmp;
		scanf("%d", &tmp);
		dp[i+1] = dp[i] + tmp;
	}
	
	while(M--){
		scanf("%d %d", &a, &b);
		printf("%d\n", (dp[b] - dp[a-1]));
	}
	
    return 0;
}
