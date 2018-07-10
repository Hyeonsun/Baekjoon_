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

	//���� ���ʺ����� ������ ���Ѵ�.
	for (int i = 1; i <= n; i++)
		dl[i] = max(dl[i - 1] + a[i], a[i]);


	//�����ʺ����� �������� ���Ѵ�.
	for (int i = n; i >= 1; i--)
		dr[i] = max(dr[i + 1] + a[i], a[i]);

	//���ʺ����� �����տ��� �ִ��� ���Ѵ�.
	int ans = dl[1];
	for (int i = 2; i <= n; i++)
		if (ans < dl[i])
			ans = dl[i];

	//���ʺ����� �����հ� �����ʿ����� �������� ���� �̿��Ͽ� �����Ҷ��� �ִ��� ���Ѵ�.
	for (int i = 2; i <= n - 1; i++)
		if (ans < dl[i - 1] + dr[i + 1])
			ans = dl[i - 1] + dr[i + 1];

	printf("%d\n", ans);

	return 0;
}