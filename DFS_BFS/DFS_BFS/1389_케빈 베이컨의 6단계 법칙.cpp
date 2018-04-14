#include <cstdio>
#include  <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

vector<int> a[101];
int n, m;
bool check[101];
int co[101], ans[101];
void bfs(int start) {
	queue<int> q;
	q.push(start);
	check[start] = true;
	co[start] = 0;
	while (!q.empty()) {
		int next = q.front();
		q.pop();
		for (int i = 0; i < a[next].size(); i++) {
			int y = a[next][i];

			if (check[y] == false) {
				//printf("y : %d\n", y);
				check[y] = true;
				q.push(y);
				co[y] = co[next] + 1;
			}
		}
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int j = 0; j < m; j++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v); a[v].push_back(u);
	}
	int min = 100;
	for (int j = 1; j <= m; j++) {
		memset(check, false, sizeof(check));
		bfs(j);
		ans[j] = 0;
		for (int i = 1; i <= m; i++) {
			//printf("%d ", co[i]);
			ans[j] += co[i];
		}
		if (ans[j] < min) min = ans[j];
	}
	for (int i = 1; i <= m; i++)
		if (ans[i] == min) {
			printf("%d\n", i);
			break;
		}
	return 0;
}