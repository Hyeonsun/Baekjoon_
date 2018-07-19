#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int w[20][20];

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &w[i][j]);
		}
	}

	vector<int> d(n);
	for (int i = 0; i < n; i++)
		d[i] = i;

	int ans = 214783647;

	do {
		bool ok = true;
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			if (w[d[i]][d[i + 1]] == 0)		// 번호에서 다음 번호까지의 가중치가 0이면 false
				ok = false;
			else
				sum += w[d[i]][d[i + 1]];
		}
		if (ok && w[d[n - 1]][d[0]] != 0) {
			sum += w[d[n - 1]][d[0]];
			if (ans > sum) ans = sum;
		}
	} while (next_permutation(d.begin() + 1, d.end()));	// 시작점은 0으로 고정 - 경우의수가 줄어든다.

	printf("%d\n", ans);

	return 0;
}