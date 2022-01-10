#include <stdio.h>

#define MAXN 1000000

using namespace std;

int N, M;
int parent[MAXN+1];

int Find(int src){
	if (parent[src] == src) return src;
	return parent[src] = Find(parent[src]);	// 경로 압축 
}

void Union(int src, int dst){
	parent[Find(src)] = Find(dst);
}

void initArr(void){
	for(int i=0;i<=N; i++){
		parent[i] = i;
	}
}

int main()
{
	int op, src, dst;
    scanf("%d %d", &N, &M);
    initArr();
    while(M--){
    	scanf("%d %d %d", &op, &src, &dst);
    	if(op == 0){	// Union
    		Union(src, dst);
		}else{			// Find
			if(Find(src) == Find(dst)) printf("YES\n");
			else printf("NO\n");
		}
	}

    return 0;
}
