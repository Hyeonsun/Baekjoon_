#include <stdio.h>
#define MOD 10007

int main(void)
{
	long long d[1001][11];
	int N;

	scanf("%d", &N);

	for (int i = 0; i < 10; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			d[i][j] = 0;
			for (int k = 0; k <= j; k++) {
				d[i][j] += d[i - 1][k];
			}
			d[i][j] %= MOD;
		}
	}
	long long sum = 0;
	for (int i = 0; i <= 9; i++)
		sum += d[N][i];

	printf("%lld\n", sum % MOD);
	return 0;
}