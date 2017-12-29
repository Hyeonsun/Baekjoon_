#include <stdio.h>

int d[1000001];

int go(int n)
{
	if (d[n] > 0) return d[n];
	if (n == 1)
		return 0;

	d[n] = go(n - 1) + 1;
	if (n % 3 == 0) {
		int temp = go(n / 3) + 1;
		if (d[n] > temp)
			d[n] = temp;
	}
	if (n % 2 == 0) {
		int temp = go(n / 2) + 1;
		if (d[n] > temp)
			d[n] = temp;
	}
	return d[n];
}
int main(void)
{
	int N;
	scanf("%d", &N);

	printf("%d\n", go(N));

	return 0;
}