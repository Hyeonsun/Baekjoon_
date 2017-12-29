#include <stdio.h>
#define MOD 1000000000

int main(void)
{
	long long d[101][10];
	int N;
	long long sum = 0;

	scanf("%d", &N);

	d[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			d[i][j] = 0;
			if (j == 0)
				d[i][j] += d[i - 1][j + 1];
			else if (j == 9)
				d[i][j] += d[i - 1][j - 1];
			else
				d[i][j] += d[i - 1][j - 1] + d[i - 1][j + 1];
			d[i][j] %= MOD;
		}
	}

	for (int i = 0; i < 10; i++)
		sum += d[N][i];
	sum %= MOD;
	printf("%lld\n", sum);

	return 0;
}