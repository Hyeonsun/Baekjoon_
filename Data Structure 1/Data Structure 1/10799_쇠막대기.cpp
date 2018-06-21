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
		if (a[i] == '(') s.push(i);	// stack에 ( 의 인덱스를 넣는다.
		else {
			if (s.top() + 1 == i) {	// () 이면  --> 레이저
				s.pop();
				ans += s.size();
			}
			else {	// ()가 아니면 --> 쇠막대기
				s.pop();
				ans += 1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}