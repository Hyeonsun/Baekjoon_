#include <cstdio>
#define MOD 10007
using namespace std;

long long d[1001][10];

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i <= 9; i++)
		d[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] += d[i - 1][k];
			}
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