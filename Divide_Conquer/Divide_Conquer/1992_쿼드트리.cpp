#include <cstdio>
#include <algorithm>
using namespace std;

int a[65][65];

/*void solve(int rowStart, int rowEnd, int colStart, int colEnd) {
int data = a[rowStart][colStart];



for (int i = rowStart; i <= rowEnd; i++) {
for (int j = colStart; j <= colEnd; j++) {
if (data != a[i][j]) {
printf("(");
solve(rowStart, (rowEnd-1) / 2, colStart, (colEnd-1) / 2);
solve((rowEnd + 1) / 2, rowEnd, colStart, (colEnd-1) / 2);
solve(rowStart, (rowEnd-1) / 2, (colEnd + 1) / 2, colEnd);
solve((rowEnd + 1) / 2, rowEnd, (colEnd + 1) / 2, colEnd);
printf(")");
}
}
}
printf("%d %d %d %d -- %d\n", rowStart, rowEnd, colStart, colEnd, data);
//printf("%d", data);
return;
}*/
bool same(int x, int y, int n) {
	for (int i = x; i<x + n; i++)
		for (int j = y; j<y + n; j++)
			if (a[x][y] != a[i][j])
				return false;
	return true;
}

void solve(int x, int y, int n) {
	if (same(x, y, n)) {
		printf("%d", a[x][y]);
	}
	else {
		printf("(");
		int m = n / 2;
		for (int i = 0; i<2; i++)
			for (int j = 0; j<2; j++)
				solve(x + m*i, y + m*j, m);
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