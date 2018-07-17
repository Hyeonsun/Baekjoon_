#include <cstdio>
using namespace std;

int main(void)
{
	int n;
	scanf("%d", &n);
	long long ans = 0;
	int len = 1;
	for (int start = 1; start <= n; start *= 10) {
		int end = start * 10 - 1;
		if (end > n)
			end = n;
		ans += (long long)(end - start + 1) * (len++);
	}

	printf("%d\n", ans);

	return 0;
}