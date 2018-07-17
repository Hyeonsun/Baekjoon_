#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int a[10001];

bool next_permutation(int n, int a[]) {
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) i--; 
	if (i <= 0) return false; // 다음순열 없음
	int j = n - 1;
	while (a[j] <= a[i - 1]) j--;
	swap(a[i - 1], a[j]);
	j = n - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i++; j--;
	}
	return true;	// next_permutaion success
}


int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	if (next_permutation(n, a)) {
		for (int i = 0; i < n; i++)
			printf("%d ", a[i]);
		puts("");
	}
	else
		printf("-1\n");

	return 0;
}