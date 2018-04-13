#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n, k;
int check[100001];
queue<int> q;

int bfs() {
	q.push(n); check[n] = 1; // queue에 push하고 check true
							 //bfs 시작
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		if (p == k) return check[p] - 1;	//동생을 찾았을 경우

											//p-1 이 0보다 크고 아직 방문하지 않은 칸일경우
		if (p - 1 >= 0 && check[p - 1] == 0) {
			check[p - 1] = check[p] + 1;
			q.push(p - 1);
		}

		//p+1 이 0보다 작고 아직 방문하지 않은 칸일경우
		if (p + 1 <= 100000 && check[p + 1] == 0) {
			check[p + 1] = check[p] + 1;
			q.push(p + 1);
		}

		//순간이동하여 2*p에 이동했는데 그곳이 방문하지 않은 칸일경우
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