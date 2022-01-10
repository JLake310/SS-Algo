#include <stdio.h>
#include <queue>

using namespace std;

#define MAXN 1000

int N, M;
int parent[MAXN+1];

struct Data{
	int src, dst, w;
	Data() {};
	Data(int src, int dst, int w) : src(src), dst(dst), w(w){};
	
	bool operator<(const Data d) const{
		return w > d.w;			// 생성자, 작은 순서대로 반환
	}
};

void Find(int x){
	if(x == parent[x]) return x;
	else return parent[x] = Find(parent[x]);
}

void Union(int src, int dst){
	parent[Find(src)] = Find(dst);
}

int main()
{
	int src, dst, w;
	priority_queue<Data> pq;
	scanf("%d", &N);
	scanf("%d", &M);
	
	for(int i=0; i<=N; i++){
		parent[i] = i;
	}
	
	int idx=0;
	while(M--){
		scanf("%d %d %d", &src, &dst, &w);
		pq.push(Data(src, dst, w));
	}
	
	int cnt = 0;
	int answer = 0;
	
	while(true){
		if (cnt == N - 1) break;
		Data d = pq.top();
		pq.pop();
		if(Find(d.src) != Find(d.dst)){
			Union(d.src, d.dst);
			cnt++;
			answer += d.w;
		}
	}
	
	printf("%d\n", answer);
	
    return 0;
}
