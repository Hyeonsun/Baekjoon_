#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		vector<int> a(n);
		for (int i = 0; i < n; i++)	
			cin >> a[i];
		vector<int> d;
		for (int i = 0; i < n - 6; i++) // n-6만큼 0을 입력받는다.
			d.push_back(0);
		for (int i = 0; i < 6; i++)	// 1을 6개 입력만는다.
			d.push_back(1);

		vector<vector<int>> ans;

		do {
			vector<int> current;
			for (int i = 0; i < n; i++)
				if (d[i] == 1)	// 1의 갯수는 6개이므로 6개로 만들 수 있는 모든 경우의 수가 나온다.
					current.push_back(a[i]);	// 그 모든 경우의 수를 current 벡터에 넣어주고
			ans.push_back(current);	// 만들어진 경우의 수를 ans벡터에 넣어줍니다.
		} while (next_permutation(d.begin(), d.end()));	// d의 순열을 구해서 거기서 1만 뽑아낸다. 
		sort(ans.begin(), ans.end());

		for (auto &v : ans) {
			for (int i = 0; i < v.size(); i++)
				cout << v[i] << ' ';
			cout << '\n';
		}
		cout << '\n';
	}

	return 0;
}