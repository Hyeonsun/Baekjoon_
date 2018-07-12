#include <cstdio>
#include <algorithm>
using namespace std;

int d[100001];

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		d[i] = i;
		for (int j = 1; j * j <= i; j++) {
			if (d[i] > d[i - j*j] + 1)
				d[i] = d[i - j*j] + 1;
		}
	}

	printf("%d\n", d[n]);

	return 0;
}