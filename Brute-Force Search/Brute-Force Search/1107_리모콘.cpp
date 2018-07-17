#include <cstdio>
#include <algorithm>
using namespace std;

bool broken[10];

int possible(int c) {
	if (c == 0)
		return broken[0] ? 0 : 1;

	int len = 0;
	while (c > 0) {
		if (broken[c % 10]) return false;
		c /= 10;
		len++;
	}

	return len;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		broken[x] = true;
	}

	int ans = n - 100;
	if (ans < 0)
		ans = -ans;


	for (int i = 0;; i++) {
		int c = i;
		int len = possible(i);
		if (len > 0) {
			int press = c - n; 
			if (press < 0) 
				press = -press;
			if (ans > len + press)
				ans = len + press;
		}
	}
}