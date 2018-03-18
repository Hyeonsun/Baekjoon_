#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> p(n);

	for (int i = 0; i < n; i++)
		cin >> p[i];

	sort(p.begin(), p.end());

	int ans = 0, final = 0;

	for (int i = 0; i <= n-1; i++) {
		ans += p[i];
		final += ans;
	}
	cout << final << '\n';

	return 0;
}