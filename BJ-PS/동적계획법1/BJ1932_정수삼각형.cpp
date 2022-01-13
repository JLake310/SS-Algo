#include <iostream>
#include <algorithm>

using namespace std;

int tri[500][500];
int dp[500][500];
int N;

int main(int argc, char** argv) {
	
	scanf("%d", &N);
	
	for(int i=0;i<N;i++){
		for(int j=0; j<=i; j++){
			scanf("%d", &tri[i][j]);
		}
	}
	
	dp[0][0] = tri[0][0];
	
	for(int i=0; i<N; i++){
		for(int j=0; j<=i; j++){
			if(j == 0){
				dp[i][j] = tri[i][j] + dp[i-1][j];
			}
			else if(j == i){
				dp[i][j] = tri[i][j] + dp[i-1][j-1];
			}
			else{
				dp[i][j] = tri[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
			}
		}
	}
	
	int answer=0;
	
	for(int i=0;i<N; i++){
		if(answer < dp[N-1][i]) answer = dp[N-1][i];
	}
	
	printf("%d", answer);

    return 0;
}
