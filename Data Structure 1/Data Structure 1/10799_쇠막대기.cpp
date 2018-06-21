#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	string a;
	cin >> a;
	int n = a.size();

	stack<int> s;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] == '(') s.push(i);	// stack�� ( �� �ε����� �ִ´�.
		else {
			if (s.top() + 1 == i) {	// () �̸�  --> ������
				s.pop();
				ans += s.size();
			}
			else {	// ()�� �ƴϸ� --> �踷���
				s.pop();
				ans += 1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}