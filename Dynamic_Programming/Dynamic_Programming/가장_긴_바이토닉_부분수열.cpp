#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	vector<int> d(n + 1);
	vector<int> d2(n + 1);

	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (a[j]<a[i] && d[j] + 1>d[i])
				d[i] = d[j] + 1;
		}
	}
	for (int i = n; i >= 1; i--) {
		d2[i] = 1;
		for (int j = i; j <= n; j++) {
			if (a[i] > a[j] && d2[j] + 1 > d2[i])
				d2[i] = d2[j] + 1;
		}
	}

	long long ans = 0;
	for (int i = 0; i < n; i++)
		if (ans < d[i] + d2[i] - 1)
			ans = d[i] + d2[i] - 1;

	cout << ans << '\n';
	return 0;
}