#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

#define MAXV 20000
#define INF 987654321

struct Data{
	int node;
	int weight;
	
	Data();
	Data(int node, int weight):node(node), weight(weight){};
	
	bool operator<(const Data d) const{		// 우선순위 큐에 넣을 때만 쓰면 됨
		return weight > d.weight;
	}
};

vector<Data> vec[MAXV+1];
int dist[MAXV+1];
bool isVisited[MAXV+1];
priority_queue<Data> pq;

int V,E;
int start, u, v, w;

void Init(int V){
	for(int i=0; i<=V; i++){
		vec[i].clear();
		dist[i] = INF;
		isVisited[i] = false;
	}
}

int main()
{
	scanf("%d %d", &V, &E);
	
	Init(V);
	
	scanf("%d", &start);
	
	dist[start] = 0;
	pq.push(Data(start, 0));
	
	while(E--){
		scanf("%d %d %d", &u, &v, &w);
		vec[u].push_back(Data(v, w));
		//vec[v].push_back(Data(u, w));  양방향일 때만 넣어줌 
	}
	
	while(true){
		if (pq.empty()) break;
		Data now = pq.top();
		pq.pop();
		if(isVisited[now.node]) continue;
		isVisited[now.node] = true;
		for(int i=0; i< vec[now.node].size(); i++){
			Data next = vec[now.node].at(i);
			if(dist[next.node] > dist[now.node] + next.weight){
				dist[next.node] = dist[now.node] + next.weight;
				pq.push(Data(next.node, dist[next.node]));
			}
		}
	}
	
	for(int i=1; i<=V; i++){
		if(dist[i] == 987654321) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
	
    return 0;
}
