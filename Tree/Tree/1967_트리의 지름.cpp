#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 10001
using namespace std;

struct Edge {
	int to;
	int cost;
	Edge(int to, int cost) : to(to), cost(cost) {

	}
};

vector<Edge> a[MAX];
bool check[MAX];
int dist[MAX];

void bfs(int start) {
	memset(dist, 0, sizeof(dist));
	memset(check, false, sizeof(check));
	queue<int> q;
	check[start] = true;
	q.push(start);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			Edge &e = a[x][i];
			if (check[e.to] == false) {
				dist[e.to] = dist[x] + e.cost;
				q.push(e.to);
				check[e.to] = true;
			}
		}
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		a[u].push_back(Edge(v, w));
		a[v].push_back(Edge(u, w));
	}
	bfs(1);
	int start = 1;
	for (int i = 2; i <= n; i++) {
		if (dist[i] > dist[start])
			start = i;				// 루트로부터 가장 긴 경로 찾기.
	}
	bfs(start);
	int ans = dist[1];
	for (int i = 2; i <= n; i++) {
		if (ans < dist[i])
			ans = dist[i];
	}
	printf("%d\n", ans);
	return 0;
}