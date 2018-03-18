#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct meeting {
	int begin, end;
};

bool cmp(const meeting &u, meeting &v) {
	if (u.end == v.end)
		return u.begin < v.begin;
	else
		return u.end < v.end;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	vector<meeting> a(n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &a[i].begin, &a[i].end);

	sort(a.begin(), a.end(), cmp);

	int now = 0;
	int ans = 0;

	for (int i = 0; i < a.size(); i++) {
		if (now <= a[i].begin) {
			now = a[i].end;
			ans += 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}