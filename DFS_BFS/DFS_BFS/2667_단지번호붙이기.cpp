#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int a[30][30];
int d[30][30];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int co[25 * 25];
int n;

void dfs(int x, int y, int cnt) {
	d[x][y] = cnt;
	for (int k = 0; k<4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (a[nx][ny] == 1 && d[nx][ny] == 0) {
				dfs(nx, ny, cnt);
			}
		}
	}
}
void bfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y)); d[x][y] = cnt;

	while (!q.empty()) {
		x = q.front().first; y = q.front().second; q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (a[nx][ny] == 1 && d[nx][ny] == 0) {
					d[nx][ny] = cnt;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &a[i][j]);

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 && d[i][j] == 0)
				bfs(i, j, ++cnt);

		}
	}

	printf("%d\n", cnt);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			co[d[i][j]] += 1;
		}
	}
	sort(co + 1, co + cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		printf("%d\n", co[i]);
	}
	return 0;
}