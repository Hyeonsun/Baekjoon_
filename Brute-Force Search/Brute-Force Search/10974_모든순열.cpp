#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int a[10];

//bool next_permutation(int n, int a[]) {
//	int i = n - 1;
//	while (i > 0 && a[i - 1] >= a[i]) i--;
//	if (i <= 0) return false;
//	int j = n - 1;
//	while (a[j] <= a[i - 1]) j--;
//	swap(a[i - 1], a[j]);
//	j = n - 1;
//	while (i < j) {
//		swap(a[i], a[j]);
//		i++; j--;
//	}
//	return true;
//}


int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		a[i] = i + 1;

	do {
		for (int i = 0; i < n; i++)
			printf("%d ", a[i]);
		puts("");
	} while (next_permutation(a, a + n));
	return 0;
}