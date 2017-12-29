#include <iostream>
#include <algorithm>
using namespace std;

int d[100001][3];
int a[100001][2];
int main(void)
{
	int T, n;


	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i][0];
		for (int i = 1; i <= n; i++)
			cin >> a[i][1];
		d[0][0] = d[0][1] = d[0][2] = 0;

		for (int i = 1; i <= n; i++) {
			d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + a[i][0];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + a[i][1];
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++)
			ans = max(d[i][0], max(d[i][1], d[i][2]));
		cout << ans << '\n';
	}

	return 0;
}