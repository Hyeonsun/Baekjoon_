#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dx[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dy[] = { 2, 1, -1, -2, 2, 1, -1, -2 };
int a[301][301];
int d[301][301];
int x[301]; int y[301];
int n;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = 0; a[x][y] = 1;

	while (!q.empty()) {
		x = q.front().first; y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (a[nx][ny] == -1 && d[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					a[nx][ny] = 1; d[nx][ny] = d[x][y] + 1;
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
		int num = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = -1;
				d[i][j] = 0;
			}
		}

		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		bfs(x1, y1);
		printf("%d\n", d[x2][y2]);
	}
	return 0;
}