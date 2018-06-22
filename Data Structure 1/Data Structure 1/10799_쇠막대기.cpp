#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(void)
{
	string str;
	cin >> str;
	stack<int> s;
	int ans = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') s.push(i);
		else {
			if (s.top() + 1 == i) { //·¹ÀÌÀú
				s.pop();
				ans += s.size();
			}
			else {
				s.pop();
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}