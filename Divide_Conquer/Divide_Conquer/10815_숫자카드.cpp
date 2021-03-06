#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n, m;
int a[500000];

int binary_search(int num) {
	int l = 0;
	int r = n - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (a[mid] == num) {
			return 1; // 찾았다!
		}
		else if (a[mid] > num) {
			r = mid - 1; // 찾는 값이 중간값보다 작으면
		}
		else
			l = mid + 1;  // 찾는 값이 중간값보다 크면
	}
	return 0;
}

int main(void)
{
	/*scanf("%d", &n);
	for (int i = 0; i < n; i++) {
	scanf("%d", &a[i]);
	}
	sort(a, a + n);
	scanf("%d", &m);
	while (m--) {
	int num;
	scanf("%d", &num);
	printf("%d", binary_search(num));
	}
	printf("\n");
	return 0;*/

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	scanf("%d", &m);
	while (m--) {
		int num;
		scanf("%d", &num);
		printf("%d ", binary_search(a, a + n, num));
	}
	puts("");
}