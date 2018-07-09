#include <cstdio>
#include <algorithm>
using namespace std;

int d[1001], d2[1001], a[1001];
int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j] && d[j] + 1 > d[i])
				d[i] = d[j] + 1;
		}
	}

	for (int i = n; i >= 1; i--) {
		d2[i] = 1;
		for (int j = n; j > i; j--) {
			if (a[i] > a[j] && d2[j] + 1 > d2[i])
				d2[i] = d2[j] + 1;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < d[i] + d2[i] - 1)
			ans = d[i] + d2[i] - 1;
	}

	printf("%d\n", ans);

	return 0;
}