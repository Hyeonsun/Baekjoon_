#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> hi[101];
bool check[101];
int co = 0, cot = 0;
bool isOk = false;
bool bfs(int node, int end) {
	queue<int> q;
	q.push(node);
	check[node] = true;

	while (!q.empty()) {
		int next = q.front();
		q.pop();
		cot++;
		for (int i = 0; i < hi[next].size(); i++) {
			int y = hi[next][i];
			if (check[y] == false) {
				check[y] = true;
				q.push(y);
				co = cot;
				if (y == end) {
					printf("%d\n", co);
					isOk = true;
				}
			}
		}
	}
	return isOk;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	int a, b;
	scanf("%d %d", &a, &b);

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		hi[u].push_back(v); hi[v].push_back(u);
	}
	if (a == b) {
		puts("0");
	}
	else if (!bfs(a, b))
		puts("-1");

	return 0;
}