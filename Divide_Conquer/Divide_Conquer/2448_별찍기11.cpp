#include <cstdio>
using namespace std;

char a[3072][6144];

void star(int n, int x, int y) {
	if (n == 3) {	//���̰� 3�̶�� ���� ����� ����Ѵ�.
					//���� �׸���.
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
	star(n / 2, x, y);	// ������ �ﰢ���� ���̿� ��ġ ���� �̿��� ���
	star(n / 2, x - (n / 2), y + (n / 2));
	star(n / 2, x + (n / 2), y + (n / 2));
}

int main(void)
{
	int n, i, j;

	scanf("%d", &n);

	// �迭 �ʱ�ȭ
	for (i = 0; i < n; i++) {
		for (j = 0; j < 2 * n; j++) {
			if (j == 2 * n - 1) a[i][j] = '\0';
			else a[i][j] = ' ';
		}
	}

	star(n, n - 1, 0);	//�ﰢ���� ���̿�, �ﰢ���� ���� ������ ��ǥ�� �Ѱ��ش�.

						//�ﰢ�� ���
	for (i = 0; i < n; i++)
		printf("%s\n", a[i]);

	return 0;
}