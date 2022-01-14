#include <iostream>
#include <algorithm>

#define MAXN 1024

using namespace std;

int N,M;
int x1, y1, x2, y2;
int map[MAXN+1][MAXN+1];

int main(int argc, char** argv) {
	
	scanf("%d %d", &N, &M);
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			int tmp;
			scanf("%d", &tmp);
			if(i==1 && j==1) map[i][j] = tmp;
			else if(i==1) map[i][j] = map[i][j-1] + tmp;
			else if(j==1) map[i][j] = map[i-1][j] + tmp;
			else map[i][j] = map[i][j-1] + map[i-1][j] - map[i-1][j-1] + tmp;
		}
	}
	
	while(M--){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int res = map[x2][y2] - map[x1-1][y2] - map[x2][y1-1] + map[x1-1][y1-1];
		printf("%d\n", res);
		
	}
	
    return 0;
}
