#include <cstdio>
#include <cstdlib>
#define STAR 1
#define BLANK 0
using namespace std;

int n;

void go(char **a, int x, int y, int n, int color) {
	int newColor;
	if (color == STAR) {
		if (n == 1) a[x][y] = '*'; //���� n�� 1�ϰ�� *���
		else {	//n�� 2 �̻��� ���
			newColor = STAR;
			int m = n / 3;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (i == 1 && j == 1) newColor = BLANK; // (1,1)�� ��츸 BLANK ������ STAR�� ä����
					else newColor = STAR;	// ������ ��쿣 STAR
					go(a, x + m*i, y + m*j, m, newColor);
				}
			}
		}
	}
	else {
		for (int i = x; i < x + n; i++)
			for (int j = y; j < y + n; j++)
				a[i][j] = ' ';
	}
}
int main(void)
{
	scanf("%d", &n);
	int i, j;
	char **a;

	a = (char**)malloc(sizeof(char*)*n);	 //double pointer memory allocation
	for (i = 0; i < n; i++)
		a[i] = (char*)malloc(sizeof(char)*(n + 1));

	for (i = 0; i < n; i++)
		for (j = 0; j < n + 1; j++)
			a[i][j] = 0;

	go(a, 0, 0, n, STAR);
	for (int i = 0; i < n; i++)
		printf("%s\n", a[i]);

	return 0;
}