#include <cstdio>
#include <algorithm>
#define MOD 1000000000
using namespace std;

long long d[101][101];

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= 9; i++) d[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j >= 1 && j <= 8)
				d[i][j] = d[i - 1][j - 1] + d[i - 1][j + 1];
			else if (j == 0)
				d[i][j] = d[i - 1][1];
			else if (j == 9)
				d[i][j] = d[i - 1][8];

			d[i][j] %= MOD;
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 9; i++)
		ans += d[n][i];
	ans %= MOD;
	printf("%lld\n", ans);

	return 0;
}
