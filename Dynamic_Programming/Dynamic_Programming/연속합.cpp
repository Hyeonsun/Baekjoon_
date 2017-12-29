#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<int> a(n + 1);
	vector<int> d(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	d[1] = a[1];
	for (int i = 2; i <= n; i++)
		d[i] = max(a[i], d[i - 1] + a[i]);

	long long ans = d[1];
	for (int i = 2; i <= n; i++)
		if (ans < d[i])
			ans = d[i];

	cout << ans << '\n';

	return 0;
}