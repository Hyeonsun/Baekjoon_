#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}
int main(void)
{
	int T;
	cin >> T;

	while (T--) {
		int num;
		long long sum = 0;
		cin >> num;
		vector<int> a(num);
		for (int i = 0; i < num; i++)
			cin >> a[i];
		for (int i = 0; i < num - 1; i++)
			for (int j = i + 1; j < num; j++)
				sum += gcd(a[i], a[j]);
		cout << sum << '\n';
	}
	return 0;
}