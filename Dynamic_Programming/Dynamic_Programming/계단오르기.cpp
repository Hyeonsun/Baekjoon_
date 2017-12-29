#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[301][2];
int main(void)
{
	int n;
	cin >> n;

	vector<int> a(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	d[1][0] = a[1];
	for (int i = 2; i <= n; i++) {
		d[i][0] = max(d[i - 2][0], d[i - 2][1]) + a[i];
		d[i][1] = d[i - 1][0] + a[i];
	}

	long long ans = 0;
	ans = max(d[n][0], d[n][1]);
	cout << ans << '\n';

	return 0;
}