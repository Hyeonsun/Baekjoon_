#include <iostream>
using namespace std;

long long int d[101];
int main(void)
{
	int T;
	cin >> T;

	int n;

	d[1] = 1; d[2] = 1; d[3] = 1;
	while (T--) {
		cin >> n;
		for (int i = 4; i <= n; i++)
			d[i] = d[i - 2] + d[i - 3];
		long long int ans = d[n];
		cout << ans << '\n';
	}

	return 0;
}