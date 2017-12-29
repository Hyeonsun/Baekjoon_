#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<int> a(n + 1);
	vector<int> d(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j]<a[i] && d[j] + 1 > d[i])
				d[i] = d[j] + 1;
		}
	}
	cout << *max_element(d.begin(), d.end()) << '\n';
	return 0;
}