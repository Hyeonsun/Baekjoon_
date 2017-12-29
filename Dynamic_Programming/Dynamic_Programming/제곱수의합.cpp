#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<int> d(n + 1);


	for (int i = 1; i <= n; i++) {
		d[i] = i;
		for (int j = 1; j*j <= i; j++) {
			d[i] = min(d[i], d[i - (j*j)] + 1);
		}
	}
	long long ans = d[n];
	cout << ans << '\n';

	return 0;
}