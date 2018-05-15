#include <cstdio>
using namespace std;
int n;
int a[64][64];

int checkSame(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (a[x][y] != a[i][j])
				return -1;
		}
	}
	return a[x][y];
}

void solve(int x, int y, int n) {
	int temp = checkSame(x, y, n);

	if (temp == -1) {
		printf("(");
		int length = n / 2;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				solve(x + length * i, y + length*j, length);
			}
		}
		printf(")");
	}
	else printf("%d", temp);
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	solve(0, 0, n);
}