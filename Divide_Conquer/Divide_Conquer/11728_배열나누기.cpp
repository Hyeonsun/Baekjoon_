#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	int k = 0;
	vector<int> a(n);
	vector<int> b(m);
	vector<int> temp(n + m);

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int j = 0; j < m; j++)
		cin >> b[j];
	int i = 0, j = 0;
	for (; i < n && j < m; ) {
		if (a[i] <= b[j])
			temp[k++] = a[i++];
		else
			temp[k++] = b[j++];
	}
	if (i < n)
		for (i; i < n; ) temp[k++] = a[i++];
	if (j < m)
		for (j; j < m; )temp[k++] = b[j++];
	for (int i = 0; i < n + m; i++)
		cout << temp[i] << ' ';
	return 0;
}