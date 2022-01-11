#include <stdio.h>
#include <queue>
#include <vector>

#define MAXn 100
#define INF 987654321

using namespace std;

int n, m;
int a, b, c;

int dp[MAXn+1][MAXn+1];

int main()
{
	scanf("%d %d", &n, &m);
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n;j++){
			dp[i][j] = INF;
		}
	}
	
	while(m--){
		scanf("%d %d %d", &a, &b, &c);
		if(dp[a][b] > c) dp[a][b] = c;
	}
	
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i==j) continue;
				if(dp[i][k] == INF || dp[k][j] == INF) continue;
				if(dp[i][j] > dp[i][k] + dp[k][j]) dp[i][j] = dp[i][k] + dp[k][j];
			}
		}
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n;j++){
			if(dp[i][j] == INF) printf("0 ");
			else printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	
    return 0;
}
