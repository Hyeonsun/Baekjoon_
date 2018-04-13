#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int a[110][110];
int d[110][110];
int check[110][110];
vector<int> hi(100);
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void bfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = cnt;

	while (!q.empty()) {
		x = q.front().first; y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && nx < n) {
				if (d[nx][ny] == 1 && check[nx][ny] == 0) {
					check[nx][ny] = cnt;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

}

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			hi.push_back(a[i][j]);
		}
	}
	sort(hi.begin(), hi.end());
	hi.erase(unique(hi.begin(), hi.end()), hi.end());

	int cnt = 0, realCnt = 0;
	for (int k = 0; k < hi.size(); k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d[i][j] = 0; check[i][j] = 0;
				if (a[i][j] > hi[k])
					d[i][j] = 1;

			}
		}
		cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][j] == 1 && check[i][j] == 0)
					bfs(i, j, ++cnt);
			}
		}
		if (cnt > realCnt) realCnt = cnt;
	}
	printf("%d\n", realCnt);

	return 0;
}