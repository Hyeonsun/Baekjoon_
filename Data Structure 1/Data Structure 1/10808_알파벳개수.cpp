#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string s;
	cin >> s;

	for (int i = 'a'; i <= 'z'; i++) {
		cout << count(s.begin(), s.end(), i) << ' ';
	}

	return 0;
}