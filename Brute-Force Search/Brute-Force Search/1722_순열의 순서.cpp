#include <algorithm>
#include <cstdio>
using namespace std;

int a[21];

bool next_permutation(int n, int a[]) {
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) i--;
	if (i <= 0) return false;
	int j = n - 1;
	while (a[j] <= a[i - 1]) j--;
	swap(a[i - 1], a[j]);
	j = n - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i++; j--;
	}
	return true;
}

int main(void)
{
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);

	int co = 0;
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	int k; int b[21];

	if (m == 1)
		scanf("%d", &k);
	else if (m == 2)
		for (int i = 0; i < n; i++)
			scanf("%d", &b[i]);

	do {
		if (m == 1) {
			if (++co == k) {
				for (int i = 0; i < n; i++)
					printf("%d ", a[i]);
				puts("");
				break;
			}
		}
		else {
			bool same = true;
			int i;
			for (i = 0; i < n; i++)
				if (a[i] != b[i]) {
					same = false; break;
				}
			if (same)
				printf("%d\n", i - 1);
		}
	} while (next_permutation(n, a));
	return 0;
}