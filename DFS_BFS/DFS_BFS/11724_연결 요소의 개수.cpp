#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> a[1001];
bool check[1001];

void bfs(int start) {
	queue<int> q;
	check[start] = true;
	q.push(start);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];

			if (check[y] == false) {
				check[y] = true;
				q.push(y);
			}
		}
	}
}

int main(void)
{
	int n, m, start;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	int count = 0;
	for (int i = 1; i <= n; i++)
		sort(a[i].begin(), a[i].end());


	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			bfs(i);
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}