#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int d[100][100];
int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,1,-1 };
int a[100][100];

void bfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = cnt;

	while (!q.empty()) {

		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
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

	while (true) {
		scanf("%d %d", &m, &n);
		memset(d, 0, sizeof(d));
		if (n == 0 && m == 0) break;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%1d", &a[i][j]);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1 && d[i][j] == 0) {
					bfs(i, j, ++cnt);
				}
			}
		}

		printf("%d\n", cnt);
	}
}