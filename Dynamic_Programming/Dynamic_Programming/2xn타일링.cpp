#include <cstdio>
using namespace std;
#define MOD 10007

int d[1001];
int main(void)
{
	int n;
	scanf("%d", &n);

	d[0] = 1; d[1] = 1;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
		d[i] %= MOD;
	}
	d[n] %= MOD;
	printf("%d", d[n]);

	return 0;
}