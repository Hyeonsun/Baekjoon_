#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;

	int total_cnt = 0;
	if (N == 1); //1이면 이동 불가능
	else if (N == 2) {
		total_cnt = (M - 1) / 2;
		total_cnt = total_cnt > 3 ? 3 : total_cnt;
	}
	else if (M < 7) {
		total_cnt = M - 1;
		total_cnt = total_cnt > 3 ? 3 : total_cnt;
	}
	else
		total_cnt = 4 + M - 7;

	cout << total_cnt + 1 << '\n';

	return 0;
}