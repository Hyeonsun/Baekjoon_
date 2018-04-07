#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#define RED 1
using namespace std;

vector<int> a[20001];
int col[20001];

void dfs(int start, int color) {
	col[start] = color;	// visited ó��, color ���� (RED / BLUE)
	for (int i = 0; i < a[start].size(); i++) {
		int next = a[start][i];		// start ���� ����Ǿ��ִ� ��� ã�� next�� ����
		if (col[next] == 0)		//next ����� color�� 0(�湮���� ���� ���) ���
			dfs(next, 3 - color); // ���̿켱Ž�� ���ȣ�� (������尡 RED��� BLUE / BLUE���ٸ� RED)
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
			a[i].clear();	// test case�� �ִ� ��츦 ����ؼ� vector clear���ְ�
			col[i] = 0;		// color �迭�� 0���� �ٽ� �ʱ�ȭ
		}
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			a[u].push_back(v); a[v].push_back(u);
		}

		for (int i = 1; i <= n; i++) {
			if (col[i] == 0)		// no visited
				dfs(i, RED);	 // ���� �켱 Ž�� ��� - color ����
		}

		bool ok = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < a[i].size(); j++) {	// ���� Ž��
				int k = a[i][j];
				if (col[i] == col[k])
					ok = false;
			}
		}
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}
