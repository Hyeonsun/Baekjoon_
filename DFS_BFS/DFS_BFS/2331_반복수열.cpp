#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> a[10000];
bool finish = false;

int power(int n, int p) {
	int Power = 0;
	while (n >= 1) {
		int a = n % 10;
		Power += pow(a, p);
		n /= 10;
	}
	return Power;
}

int main(void)
{
	int n, p;
	int Pow;
	int i = 1, j, save;
	scanf("%d %d", &n, &p);
	a[i++].push_back(n);
	while (1) {
		Pow = power(n, p);
		a[i++].push_back(Pow);
		for (j = 1; j < i - 1; j++) {
			if (a[j][0] == Pow) {
				finish = true;
				save = i;
				break;
			}
		}
		n = Pow;
		if (finish)
			break;
	}
	int ans = 0;
	for (int k = 1; k < save - 1; k++) {
		if (a[k][0] == a[save - 1][0])
			break;
		else
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}