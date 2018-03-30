#include <cstdio>
#include <vector>
using namespace std;

vector<int> From, To;

void move(int from, int to) {
	From.push_back(from);
	To.push_back(to);
}
void hanoi(int n, int from, int by, int to) {
	if (n == 1) {
		move(from, to);
		return;
	}
	hanoi(n - 1, from, to, by);
	move(from, to);
	hanoi(n - 1, by, from, to);
}
int main(void)
{
	int num;
	scanf("%d", &num);

	hanoi(num, 1, 2, 3);
	printf("%d\n", From.size());
	for (int i = 0; i < From.size(); i++)
		printf("%d %d\n", From[i], To[i]);

	return 0;
}