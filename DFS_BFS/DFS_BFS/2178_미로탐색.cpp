#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int co = 0;
int d[110][110];
bool check[110][110];
int a[110][110];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = true;
	d[x][y] = 1;

	while (!q.empty()) {
		x = q.front().first; y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] == 1 && check[nx][ny] == false) {
					d[nx][ny] = d[x][y] + 1;
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &a[i][j]);

	int ans = 0;
	bfs(0, 0);
	printf("%d\n", d[n - 1][m - 1]);

	return 0;
}