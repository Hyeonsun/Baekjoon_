#include <cstdio>
#include <queue>
using namespace std;

int n;
int a[102][102];
bool check[102];
int d[102];

void bfs(int u, int v) {
	queue<int> q;
	q.push(u);
	d[u] = 0;
	check[u] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int dist = d[cur];
		for (int i = 1; i <= n; i++) {
			if (check[i] == false && a[cur][i] == 1) {
				check[i] = 1;
				q.push(i);
				d[i] = dist + 1;
			}
		}
	}
}
int main(void)
{
	scanf("%d", &n);
	int u, v;
	scanf("%d %d", &u, &v);	// 부모는 u, 자식은 v

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;		//그래프를 만들어줘
	}
	bfs(u, v);

	printf("%d\n", d[v] ? d[v] : -1);

	return 0;
}