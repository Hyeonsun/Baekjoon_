#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int calc(vector<int> &a, vector<int> &b) {
	int n = a.size();	// 수의 갯수
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
		scanf("%d", &cnt);		// 연산자를 입력받고
		for (int k = 0; k < cnt; k++)
			b.push_back(i);	// 연산자의 갯수만큼 b에 푸쉬백! 0 이면 + / 1이면 - / 2이면 * / 3이면 /
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