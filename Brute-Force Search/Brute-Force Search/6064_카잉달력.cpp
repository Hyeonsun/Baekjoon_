#include <cstdio>
using namespace std;

int a[40001];
int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int m, n, x, y;
		scanf("%d %d %d %d", &m, &n, &x, &y);
		x--; y--;
		bool ok = false;
		for (int k = x; k < (n*m); k += m) {
			if (k%n == y) {
				printf("%d\n", k + 1);
				ok = true;
				break;
			}
		}
		if (!ok)
			printf("-1\n");
	}
}