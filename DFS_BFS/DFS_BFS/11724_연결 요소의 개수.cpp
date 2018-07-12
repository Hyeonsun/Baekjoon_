#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool check[1001];
vector<int> a[1001];

void dfs(int node) {
	check[node] = true;

	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (check[next] == false)
			dfs(next);
	}
}

void bfs(int start) {
	queue<int> q;
	check[start] = true;
	q.push(start);

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}

	int co = 0;
	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			dfs(i);	//BFS(I)
			co++;
		}
	}

	printf("%d\n", co);
	return 0;
}