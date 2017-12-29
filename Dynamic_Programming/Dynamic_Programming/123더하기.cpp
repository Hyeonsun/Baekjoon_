#include <stdio.h>

int main(void)
{
	int N, T;
	int d[12];
	scanf("%d", &T);
	d[1] = 1; d[2] = 2; d[3] = 4;
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int j = 4; j <= N; j++)
			d[j] = d[j - 1] + d[j - 2] + d[j - 3];
		printf("%d\n", d[N]);
	}

	return 0;
}