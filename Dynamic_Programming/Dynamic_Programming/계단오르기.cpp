#include <cstdio>
#include <algorithm>
using namespace std;

int d[301], a[301];

int main(void)
{
	// Using 1-d array

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	d[1] = a[1];
	d[2] = a[1] + a[2];

	for (int i = 3; i <= n; i++) {
		d[i] = max(d[i - 3] + a[i - 1] + a[i], d[i - 2] + a[i]);
	}


	printf("%d\n", d[n]);
	return 0;




	// Using 2-d array


	int d[301][3], a[301];

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	d[1][1] = a[1];
	for (int i = 2; i <= n; i++) {
		d[i][1] = max(d[i - 2][1], d[i - 2][2]) + a[i];
		d[i][2] = d[i - 1][1] + a[i];
	}

	int ans = max(d[n][1], d[n][2]);

	printf("%d\n", ans);

	return 0;
}