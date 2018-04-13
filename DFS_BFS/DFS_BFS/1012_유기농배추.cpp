#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int k;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int a[55][55];
int d[55][55];

void bfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = cnt;

	while (!q.empty()) {
		x = q.front().first; y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] == 1 && d[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = cnt;
				}
			}
		}
	}
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = 0; d[i][j] = 0;
			}
		}
		for (int i = 0; i < k; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			a[u][v] = 1;
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1 && d[i][j] == 0)
					bfs(i, j, ++cnt);
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}