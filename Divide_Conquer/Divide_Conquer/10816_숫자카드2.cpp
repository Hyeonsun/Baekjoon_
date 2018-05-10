#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	scanf("%d", &n);
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);
		auto p = equal_range(a.begin(), a.end(), num);	// auto : 변수 자동 지정
		auto l = lower_bound(a.begin(), a.end(), num);
		auto r = lower_bound(a.begin(), a.end(), num);
		printf("%d ", p.second - p.first);
		printf("%d", r - l);
	}

	puts("");
	return 0;
}