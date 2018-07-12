#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool a[2001][2001];
vector<int> b[2001];		//��������Ʈ
vector<pair<int, int>> edges;	//��������Ʈ
int main(void)
{
	int n, m; // ������ ������ ������ ������ �Է¹޴´�.
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int from, to;
		scanf("%d %d", &from, &to); // ��θ� �Է¹޴´�.
		edges.push_back({ from, to }); // ��������� ��������Ʈ�� �־��ش�.
		edges.push_back({ to, from }); // undirected graph�̱� ������ ������� �־��ش�.
		a[from][to] = a[to][from] = true;	//��������� �����ϰ� �湮�� ������ true�� �����Ѵ�.
		b[from].push_back(to);		// 2���� ���Ϳ� from�� to �� ��������� �Է��Ѵ�.
		b[to].push_back(from);
	}
	m *= 2;	//�ϳ��� ������ �ι��� üũ�� ������ϱ� ������ *2 ������Ѵ�.
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			int A = edges[i].first;
			int B = edges[i].second;

			int C = edges[j].first;
			int D = edges[j].second;

			if (A == B || A == C || A == D || B == C || B == D || C == D) //ABCD�� ��� �ٸ�����̿����Ѵ�.
				continue;

			if (a[B][C] == false)
				continue;

			for (int E : b[D]) {
				if (E == A || E == B || E == C || E == D)	//E�� ABCD�� �޶���Ѵ�.
					continue;
				printf("1\n");
				return 0;
			}
		}
	}


	printf("0\n");
	return 0;
}