#include <stdio.h>
#define MOD 10007

int main(void)
{
	int d[1001];
	int N;

	scanf("%d", &N);

	d[0] = 1; d[1] = 1;

	for (int i = 3; i <= N; i++)
		d[i] = (d[i - 1] + 2 * d[i - 2]) % MOD;

	printf("%d\n", d[N]);

	return 0;
}