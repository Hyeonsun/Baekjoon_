#include <cstdio>
#include <algorithm>
using namespace std;

int d[100001], a[100001];
int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	d[0] = 0;
	for (int i = 1; i <= n; i++) {
		d[i] = max(a[i], d[i - 1] + a[i]);
	}

	int ans = d[1];
	for (int i = 2; i <= n; i++)
		if (ans < d[i])
			ans = d[i];

	printf("%d\n", ans);

	return 0;
}