#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n, k;
int check[100001];
queue<int> q;

int bfs() {
	q.push(n); check[n] = 1; // queue�� push�ϰ� check true
							 //bfs ����
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		if (p == k) return check[p] - 1;	//������ ã���� ���

											//p-1 �� 0���� ũ�� ���� �湮���� ���� ĭ�ϰ��
		if (p - 1 >= 0 && check[p - 1] == 0) {
			check[p - 1] = check[p] + 1;
			q.push(p - 1);
		}

		//p+1 �� 0���� �۰� ���� �湮���� ���� ĭ�ϰ��
		if (p + 1 <= 100000 && check[p + 1] == 0) {
			check[p + 1] = check[p] + 1;
			q.push(p + 1);
		}

		//�����̵��Ͽ� 2*p�� �̵��ߴµ� �װ��� �湮���� ���� ĭ�ϰ��
		if (2 * p <= 100000 && check[2 * p] == 0) {
			check[2 * p] = check[p] + 1;
			q.push(2 * p);
		}
	}
}

int main(void)
{
	scanf("%d %d", &n, &k);
	printf("%d\n", bfs());

	return 0;
}