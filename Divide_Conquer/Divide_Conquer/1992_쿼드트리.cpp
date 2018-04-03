#include <cstdio>
using namespace std;
int a[65][65];

bool same(int row, int col, int size) {
	for (int i = row; i < row + size; i++)
		for (int j = col; j < col + size; j++)
			if (a[row][col] != a[i][j])
				return false;
	return true;
}
void solve(int row, int col, int size) {
	int data = a[row][col];

	if (same(row, col, size)) {
		printf("%d", data);
	}
	else {
		int resize = size / 2;
		printf("(");
		solve(row, col, resize);
		solve(row, col + resize, resize);
		solve(row + resize, col, resize);
		solve(row + resize, col + resize, resize);
		printf(")");
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &a[i][j]);

	solve(0, 0, n);
	return 0;
}