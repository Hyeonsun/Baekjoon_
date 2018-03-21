#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> hello(n);
	
	for (int i = 0; i < n; i++)
		cin >> hello[i];

	sort(hello.begin(), hello.end());

	int ans = 0, good = 0;
	for (int i = 0; i < hello.size(); i++) {
		ans += hello[i];
		good += ans;
	}
	cout << good << '\n';
}