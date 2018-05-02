#include <vector>
#include <cstdio>
#include <queue>
#define MAX 100111
using namespace std;

int depth[MAX];
int parent[MAX];
vector<int> a[MAX];
bool check[MAX];

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v); a[v].push_back(u);
	}
	// set Root value
	depth[1] = 0;
	parent[1] = 0;
	check[1] = true;

	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y : a[x]) {
			if (!check[y]) {
				depth[y] = depth[x] + 1;
				parent[y] = x;
				check[y] = true;
				q.push(y);
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		printf("%d\n", parent[i]);
	}
	return 0;
}