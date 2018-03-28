#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int a[2188][2188];
int result[3]; // -1, 0, 1

int checkSameNum(int startRow, int endRow, int startCol, int endCol);
void solve(int startRow, int endRow, int startCol, int endCol);

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	solve(0, n - 1, 0, n - 1);

	for (int i = 0; i < 3; i++)
		cout << result[i] << ' ';
	return 0;
}
int checkSameNum(int startRow, int endRow, int startCol, int endCol)
{
	int temp = a[startRow][startCol];
	for (int i = startRow; i <= endRow; i++)
		for (int j = startCol; j <= endCol; j++)
			if (a[i][j] != temp)
				return -2;
	return temp;
}

void solve(int startRow, int endRow, int startCol, int endCol)
{
	int sameNum = checkSameNum(startRow, endRow, startCol, endCol);
	if (sameNum == -2) {
		int length = (endRow - startRow + 1) / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				solve(startRow + i * length, startRow + i * length + length - 1, startCol + j * length, startCol + j * length + length - 1);
			}
		}
	}
	else
		result[sameNum + 1]++;
}