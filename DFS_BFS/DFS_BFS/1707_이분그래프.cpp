#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#define RED 1
using namespace std;

vector<int> a[20001];
int col[20001];

void dfs(int start, int color) {
	col[start] = color;	// visited 처리, color 지정 (RED / BLUE)
	for (int i = 0; i < a[start].size(); i++) {
		int next = a[start][i];		// start 노드와 연결되어있는 노드 찾아 next로 지정
		if (col[next] == 0)		//next 노드의 color이 0(방문하지 않은 노드) 라면
			dfs(next, 3 - color); // 깊이우선탐색 재귀호출 (이전노드가 RED라면 BLUE / BLUE였다면 RED)
	}
}

int main(void)
{
	int test;
	scanf("%d", &test);

	while (test--) {
		int n, m;
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++) {
			a[i].clear();	// test case가 있는 경우를 고려해서 vector clear해주고
			col[i] = 0;		// color 배열도 0으로 다시 초기화
		}
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			a[u].push_back(v); a[v].push_back(u);
		}

		for (int i = 1; i <= n; i++) {
			if (col[i] == 0)		// no visited
				dfs(i, RED);	 // 깊이 우선 탐색 사용 - color 지정
		}

		bool ok = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < a[i].size(); j++) {	// 간선 탐색
				int k = a[i][j];
				if (col[i] == col[k])
					ok = false;
			}
		}
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}
