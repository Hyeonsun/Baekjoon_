#include <cstdio>
#include <algorithm>
using namespace std;

int dl[100001], dr[100001], a[100001];

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	//먼저 왼쪽부터의 연속합 구한다.
	for (int i = 1; i <= n; i++)
		dl[i] = max(dl[i - 1] + a[i], a[i]);


	//오른쪽부터의 연속합을 구한다.
	for (int i = n; i >= 1; i--)
		dr[i] = max(dr[i + 1] + a[i], a[i]);

	//왼쪽부터의 연속합에서 최댓값을 구한다.
	int ans = dl[1];
	for (int i = 2; i <= n; i++)
		if (ans < dl[i])
			ans = dl[i];

	//왼쪽부터의 연속합과 오른쪽에서의 연속합의 합을 이용하여 제외할때의 최댓값을 구한다.
	for (int i = 2; i <= n - 1; i++)
		if (ans < dl[i - 1] + dr[i + 1])
			ans = dl[i - 1] + dr[i + 1];

	printf("%d\n", ans);

	return 0;
}