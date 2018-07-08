#include <cstdio>
#include <algorithm>
#define MOD 1000000000
using namespace std;

long long d[101][10];
int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i < 10; i++)
		d[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				d[i][j] = d[i - 1][j + 1];
			else if (j == 9)
				d[i][j] = d[i - 1][j - 1];
			else
				d[i][j] = d[i - 1][j - 1] + d[i - 1][j + 1];

			d[i][j] %= MOD;
		}
	}

	long long ans = 0;
	for (int i = 0; i < 10; i++)
		ans += d[n][i];

	ans %= MOD;
	printf("%lld\n", ans);

	return 0;
}