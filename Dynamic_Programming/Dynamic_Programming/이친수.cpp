#include <cstdio>
using namespace std;
long long d[91];
int main(void)
{
	// Using 1-d array
	int n;
	scanf("%d", &n);

	d[0] = 0; d[1] = 1;

	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}

	printf("%lld\n", d[n]);
	return 0;



	//Using 2-d array
	int n;
	scanf("%d", &n);

	d[1][0] = 0; d[1][1] = 1;
	d[0][0] = 0; d[0][1] = 0;

	for (int i = 2; i <= n; i++) {
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}

	long long ans = d[n][0] + d[n][1];
	printf("%lld\n", ans);

	return 0;
}