#include <cstdio>
using namespace std;
int d[11];
int main(void)
{
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;


	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 3; i <= n; i++) {
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}
		printf("%d\n", d[n]);
	}

	return 0;
}