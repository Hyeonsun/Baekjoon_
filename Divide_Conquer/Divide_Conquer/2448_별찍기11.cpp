#include <cstdio>
using namespace std;

char a[3072][6144];

void star(int n, int x, int y) {
	if (n == 3) {	//높이가 3이라면 별을 만들어 출력한다.
					//별을 그린다.
		a[y][x] = '*';
		a[y + 1][x - 1] = '*';
		a[y + 1][x + 1] = '*';
		a[y + 2][x - 2] = '*';
		a[y + 2][x - 1] = '*';
		a[y + 2][x] = '*';
		a[y + 2][x + 1] = '*';
		a[y + 2][x + 2] = '*';
		return;
	}
	star(n / 2, x, y);	// 각각의 삼각형의 높이와 위치 값을 이용해 재귀
	star(n / 2, x - (n / 2), y + (n / 2));
	star(n / 2, x + (n / 2), y + (n / 2));
}

int main(void)
{
	int n, i, j;

	scanf("%d", &n);

	// 배열 초기화
	for (i = 0; i < n; i++) {
		for (j = 0; j < 2 * n; j++) {
			if (j == 2 * n - 1) a[i][j] = '\0';
			else a[i][j] = ' ';
		}
	}

	star(n, n - 1, 0);	//삼각형의 높이와, 삼각형의 맨위 꼭지점 좌표를 넘겨준다.

						//삼각형 출력
	for (i = 0; i < n; i++)
		printf("%s\n", a[i]);

	return 0;
}