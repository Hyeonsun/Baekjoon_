#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[2187][2187];
int n, m, p;

int ternary_search(int num) {
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		int first = (left + right) / 3;
		int second = (left + right) * (2 / 3);
		if (a)
	}
}
int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	int zeroCount = 0, oneCount = 0, minusCount = 0;

}