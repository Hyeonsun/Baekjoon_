#include <string>
#include <iostream>
using namespace std;
string rot13(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'm')
			s[i] = s[i] + 13;
		else if (s[i] >= 'n' && s[i] <= 'z')
			s[i] = s[i] - 13;
		else if (s[i] >= 'A' && s[i] <= 'M')
			s[i] = s[i] + 13;
		else if (s[i] >= 'N' && s[i] <= 'Z')
			s[i] = s[i] - 13;
	}
	return s;
}

int main(void)
{
	string s;
	getline(cin, s);
	cout << rot13(s) << '\n';
}