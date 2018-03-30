#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(vector<int> a, int num) {
	int l = 0, r = a.size();
	int mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] == num)
			return 1;
		else if (a[mid] < num)
			r = mid - 1;
		else
			r = mid + 1;
	}
	return 0;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	vector<int> a(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int m;
	scanf("%d", &m);
	vector<int> b(m);
	vector<int> count((*max_element(b.begin(), b.end())) + 1);
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);

	sort(a.begin(), a.end());
	for (int i = 0; i < b.size(); i++)
		count[b[i]] += binary_search(a, b[i]);

	for (int i = 0; i < count.size(); i++)
		printf("%d %d\n", b[i], count[i]);

	return 0;
}