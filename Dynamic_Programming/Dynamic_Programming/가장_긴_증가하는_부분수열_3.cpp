#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	vector<long long> v;
	scanf("%d", &n);
	v.push_back(-1000000001);
	while (n--)
	{
		int tmp;
		scanf("%d", &tmp);
		if (tmp > v.back())
			v.push_back(tmp);
		else
			*lower_bound(v.begin(), v.end(), tmp) = tmp;
	}
	printf("%d\n", v.size() - 1);
	return 0;
}