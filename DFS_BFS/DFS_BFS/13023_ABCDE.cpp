#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool a[2001][2001];
vector<int> b[2001];		//인접리스트
vector<pair<int, int>> edges;	//간선리스트
int main(void)
{
	int n, m; // 정점의 갯수와 간선의 갯수를 입력받는다.
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int from, to;
		scanf("%d %d", &from, &to); // 경로를 입력받는다.
		edges.push_back({ from, to }); // 경로정보를 간선리스트에 넣어준다.
		edges.push_back({ to, from }); // undirected graph이기 떄문에 양방향을 넣어준다.
		a[from][to] = a[to][from] = true;	//인접행렬을 구성하고 방문한 정점은 true로 설정한다.
		b[from].push_back(to);		// 2차원 벡터에 from과 to 의 경로정보를 입력한다.
		b[to].push_back(from);
	}
	m *= 2;	//하나의 정점당 두번씩 체크를 해줘야하기 때문에 *2 해줘야한다.
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			int A = edges[i].first;
			int B = edges[i].second;

			int C = edges[j].first;
			int D = edges[j].second;

			if (A == B || A == C || A == D || B == C || B == D || C == D) //ABCD는 모두 다른사람이여야한다.
				continue;

			if (a[B][C] == false)
				continue;

			for (int E : b[D]) {
				if (E == A || E == B || E == C || E == D)	//E는 ABCD와 달라야한다.
					continue;
				printf("1\n");
				return 0;
			}
		}
	}


	printf("0\n");
	return 0;
}