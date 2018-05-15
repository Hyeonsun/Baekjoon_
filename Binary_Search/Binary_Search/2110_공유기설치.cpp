#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<long long> &a, long long mid, int m) {
	int cnt = 1;
	long long last = a[0];
	for (long long house : a) {
		if (house - last >= mid) {
			cnt++;
			last = house;
		}
	}
	return cnt >= m;
}

int main(void)
{
	int n, m;

	scanf("%d %d", &n, &m);
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);

	sort(a.begin(), a.end());

	long long l = 1;
	long long r = a[n - 1] - a[0];
	long long ans = 1;

	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check(a, mid, m)) {
			if (ans < mid) ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}

	printf("%lld", ans);
	return 0;
}