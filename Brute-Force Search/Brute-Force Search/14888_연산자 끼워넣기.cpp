#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int calc(vector<int> &a, vector<int> &b) {
	int n = a.size();	// ���� ����
	int ans = a[0];
	for (int i = 1; i < n; i++) {
		if (b[i - 1] == 0)
			ans = ans + a[i];
		else if (b[i - 1] == 1)
			ans = ans - a[i];
		else if (b[i - 1] == 2)
			ans = ans*a[i];
		else
			ans = ans / a[i];
	}

	return ans;
}


int main(void)
{
	int n;
	scanf("%d", &n);
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	vector<int> b;
	for (int i = 0; i < 4; i++) {
		int cnt;
		scanf("%d", &cnt);		// �����ڸ� �Է¹ް�
		for (int k = 0; k < cnt; k++)
			b.push_back(i);	// �������� ������ŭ b�� Ǫ����! 0 �̸� + / 1�̸� - / 2�̸� * / 3�̸� /
	}

	sort(b.begin(), b.end());
	vector<int> result;
	do {
		int temp = calc(a, b);
		result.push_back(temp);
	} while (next_permutation(b.begin(), b.end()));

	auto ans = minmax_element(result.begin(), result.end());
	printf("%d\n", *ans.second);
	printf("%d\n", *ans.first);

	return 0;

}