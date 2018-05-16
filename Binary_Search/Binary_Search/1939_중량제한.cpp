#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> a[10001];

bool c[10001];
int n, m;
int st, ed;
/* bfs ·Î Çª´Â¹ý
void init() {
	for (int i = 1; i <= n; i++)
		visit[i] = 0;
	while (!que.empty())     que.pop();
}

int bfs(int limit) {

	init();

	que.push(start);
	visit[start] = 1;

	while (!que.empty()) {
		int current = que.front();
		que.pop();

		if (current == dest)    return 1;

		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i].first;
			int w = graph[current][i].second;

			if (visit[next] == 0 && limit <= w) {
				visit[next] = 1;
				que.push(next);
			}
		}
	}

	return 0;
}

int solve(int e)
{
	int s = 0, middle;

	while (s <= e) {
		middle = (s + e) / 2;

		if (bfs(middle))        s = middle + 1;
		else                    e = middle - 1;
	}

	return e;
}
*/
//dfs·Î Çª´Â ¹ý
bool go(int node, int limit) {
	if (c[node])
		return false;
	c[node] = true;
	if (node == ed)
		return true;
	for (auto &p : a[node]) {
		int next = p.first;
		int cost = p.second;
		if (cost >= limit)
			if (go(next, limit))
				return true;
	}
	return false;
}

int main(void)
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}

	scanf("%d %d", &st, &ed);
	int left, right;
	left = 1;
	right = 1000000000;
	int ans = 0;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		memset(c, false, sizeof(c));
		if (go(st, mid)) {
			ans = mid;
			left = mid + 1;
		}
		else  right = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}