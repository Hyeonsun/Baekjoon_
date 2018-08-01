#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
int ans = 0;
int a[15][15];

bool check(int row, int col) {
    for(int i = 0;i<n;i++) {
        if(i==row) continue;
        
        if(a[i][col])
            return false;
    }
    
    //왼쪽 위 대각선
    int x = row - 1;
    int y = col - 1;
    while(x >= 0 && y >= 0) {
        if(a[x][y] == true)
            return false;
        x--; y--;
    }
    
    //오른쪽 대각선
    x = row - 1;
    y = col + 1;
    while(x>= 0 && y<n) {
        if(a[x][y] == true)
            return false;
        x--; y++;
    }
    return true;
}


void calc(int row) {
    //정답인 경우
    if(row == n)
        ans++;
    
    //다음 경우
    for(int col = 0; col < n;col++) {
        a[row][col] = true;
        if(check(row, col))
            calc(row + 1);
        a[row][col] = false;
    }
}


int main(void)
{
    cin >> n;
    calc(0);
    cout << ans << '\n';
    return 0;
}
