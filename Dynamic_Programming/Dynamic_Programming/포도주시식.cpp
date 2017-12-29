#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d[10001][3];
int main(void)
{
	int n;
	cin >> n;
	vector<int> a(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++) {
		d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
		d[i][1] = d[i - 1][0] + a[i];
		d[i][2] = d[i - 1][1] + a[i];
	}
	long long ans = 0;
	ans = max(d[n][0], max(d[n][1], d[n][2]));
	cout << ans << '\n';

	return 0;
}