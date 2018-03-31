#include <cstdio>
using namespace std;

int inorder[100001];
int postorder[100001];
int position[100001];

void getPreorder(int inStart, int inEnd, int postStart, int postEnd) {
	if (inStart > inEnd || postStart > postEnd) return;
	int root = postorder[postEnd];
	printf("%d ", root);
	int p = position[root];
	int left = p - inStart;
	getPreorder(inStart, p - 1, postStart, postStart + left - 1);
	getPreorder(p + 1, inEnd, postStart + left, postEnd - 1);
}

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
	for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);
	for (int i = 0; i < n; i++) position[inorder[i]] = i;
	getPreorder(0, n - 1, 0, n - 1);
	puts("");
	return 0;
}