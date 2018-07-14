#include <cstdio>
#include <algorithm>
using namespace std;

int main(void)
{
	int e = 1, s = 1, m = 1;
	int a, b, c;
	int E = 15, S = 28, M = 19;
	scanf("%d %d %d", &a, &b, &c);

	for (int i = 1;; i++) {	// 7980 번을 넘을 수없다. 
		if (e == a && s == b  && m == c) {
			printf("%d\n", i);
			break;
		}
		e++; s++; m++;
		if (e > E) e = 1;
		if (s > S) s = 1;
		if (m > M) m = 1;
	}
	return 0;
}