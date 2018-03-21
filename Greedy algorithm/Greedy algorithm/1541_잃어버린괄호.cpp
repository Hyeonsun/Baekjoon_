#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	string s;
	cin >> s;
	vector<int> num;
	vector<int> sign;

	int cur = 0;
	bool minus = false; // find if the sign is minus
	sign.push_back(1);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+' || s[i] == '-') {		// if s[i] is sign
			if (s[i] == '+')
				sign.push_back(1);
			else
				sign.push_back(-1);
			num.push_back(cur);
			cur = 0;
		}
		else // if s[i] is number
			cur = cur * 10 + (s[i] - '0');
	}
	num.push_back(cur);
	int ans = 0;
	minus = false;
	for (int i = 0; i < num.size(); i++) {
		if (sign[i] == -1)
			minus = true;
		else
			minus = false;
		if (minus)
			ans -= num[i];
		else
			ans += num[i];
	}
	cout << ans << '\n';
	return 0;
}