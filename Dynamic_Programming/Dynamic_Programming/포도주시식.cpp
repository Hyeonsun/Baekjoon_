#include <cstdio>
#include <algorithm>
using namespace std;

long long d[10001][3];
long long a[10001];

int main(void)
{
	// solve 2-d array
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < 3; i++) {
		d[0][i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
		d[i][1] = d[i - 1][0] + a[i];
		d[i][2] = d[i - 1][1] + a[i];
	}

	long long ans = max(d[n][0], max(d[n][1], d[n][2]));

	printf("%lld\n", ans);

	return 0;



	// solve 1-d array
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	d[0] = 0;

	for (int i = 1; i <= n; i++)
		d[i] = max(d[i - 1], max(d[i - 2] + a[i], d[i - 3] + a[i - 1] + a[i]));

	printf("%lld\n", d[n]);

	return 0;
}