#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> a[100001];
bool check[100001];
int start;
bool isCycle = false;
bool first = true;
int ans = 0, co = 0;

void dfs(int node, bool checking) {
	check[node] = true;
	if (checking) {
		co++;
		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];
			if (check[next] == false)
				dfs(next, true);
		}
		return;
	}
	int next = a[node][0];
	if ((next == start && !first) || (first && next == node) || (!first && next == node)) {
		isCycle = true;
		return;
	}
	if (check[next] == false) {
		first = 0;
		dfs(next, false);
	}
}
int main(void)
{
	int T;
	scanf("%d", &T);

	while (T--) {
		int m;
		memset(check, false, sizeof(check));
		scanf("%d", &m);
		first = true; ans = 0; co = 0;
		isCycle = false;
		for (int i = 1; i <= m; i++) {
			int v;
			scanf("%d", &v);
			a[i].push_back(v);
		}
		for (int i = 1; i <= m; i++) {
			if (check[i] == false) {
				start = i; first = true;
				dfs(i, false);
				if (isCycle) {
					dfs(i, true);
				}
			}
			a[i].clear();
		}
		printf("%d\n", m - co);
	}
	return 0;
}s