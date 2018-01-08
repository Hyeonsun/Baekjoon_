#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main(void)
{
	int a, b;
	int Gcd, Lcm;

	cin >> a >> b;

	Gcd = gcd(a, b);
	Lcm = Gcd * (a / Gcd) * (b / Gcd);

	cout << Gcd << '\n' << Lcm << '\n';

	return 0;
}