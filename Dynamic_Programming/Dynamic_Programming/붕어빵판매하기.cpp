#include <cstdio>
#include <algorithm>
using namespace std;

int d[1001];
int a[10001];
int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	d[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = max(d[i], d[i - j] + a[j]);
		}
	}

	printf("%d\n", d[n]);
	return 0;
}