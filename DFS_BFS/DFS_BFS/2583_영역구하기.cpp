#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int x[101][101];
int y[101][101];
int d[101][101];
int a[101][101];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int n, m, k;
vector<int> co;
int cot = 0;

void bfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = cnt;
	while (!q.empty()) {
		x = q.front().first; y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (0 <= nx && nx < m && 0 <= ny && ny < n) {
				if (d[nx][ny] == 0) {
					cot++;
					d[nx][ny] = cnt;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main(void)
{
	scanf("%d %d %d", &m, &n, &k);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			x[i][j] = i;
			y[i][j] = j;
		}
	}

	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		int width, height;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				d[i][j] = 1;
				a[i][j] = 1;
			}
		}
	}


	int cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0 && d[i][j] == 0) {
				bfs(i, j, ++cnt);
				co.push_back(cot);
				cot = 0;
			}
		}
	}

	printf("%d\n", cnt);
	sort(co.begin(), co.end());
	for (int i = 0; i < co.size(); i++)
		printf("%d ", co[i] + 1);

	return 0;
}