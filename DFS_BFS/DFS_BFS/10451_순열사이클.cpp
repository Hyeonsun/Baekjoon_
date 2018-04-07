#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> a[1001];
bool check[1001];
int start, co = 0, first = 1;
void dfs(int node) {
	check[node] = true;

	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if ((next == start && !first) || (first && next == node)) {
			co++;
		}
		if (check[next] == false) {
			first = 0;
			dfs(next);
		}
	}
}
int main(void)
{
	int T;
	scanf("%d", &T);

	while (T--) {
		int m;
		scanf("%d", &m);
		memset(check, false, sizeof(check));
		co = 0; first = 1;
		for (int i = 1; i <= m; i++) {
			int v;
			scanf("%d", &v);
			a[i].push_back(v);
		}

		for (int i = 1; i <= m; i++) {
			if (check[i] == false) {
				start = i; first = 1;
				dfs(i);
			}
			a[i].clear();
		}
		printf("%d\n", co);
	}
	return 0;
}