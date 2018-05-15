#include <cstdio>
using namespace std;

long long a[10000];
int k, n;
bool check(int x) {
	int cnt = 0;

	for (int i = 0; i < k; i++)
		cnt += a[i] / x;

	return cnt >= n;
}

int main(void)
{
	scanf("%d %d", &k, &n);
	for (int i = 0; i < k; i++)
		scanf("%lld", &a[i]);

	long long max = 0;
	for (int i = 0; i < k; i++)
		if (a[i] > max) max = a[i];
	long l = 1;
	long r = max;

	long long ans = 0;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			if (ans < mid)
				ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}

	printf("%lld\n", ans);
	return 0;
}