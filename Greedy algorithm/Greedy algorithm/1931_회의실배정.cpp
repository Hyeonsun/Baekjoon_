#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct meeting {
	int begin;
	int end;
};

bool cmp(meeting &a, meeting &b) {
	if (a.end == b.end)
		return a.begin < b.begin;
	return a.end < b.end;
}

int main(void)
{
	int n;
	cin >> n;

	vector<meeting> hello(n);

	for (int i = 0; i < n; i++) {
		cin >> hello[i].begin >> hello[i].end;
	}

	sort(hello.begin(), hello.end(), cmp);

	int now = 0;
	int ans = 0;

	for (int i = 0; i < hello.size(); i++) {
		if (now <= hello[i].begin) {
			now = hello[i].end;
			ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}