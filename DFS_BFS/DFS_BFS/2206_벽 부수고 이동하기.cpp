#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <tuple>
using namespace std;

int a[1000][1000];
int d[1000][1000][2]; // 벽인경우와 아닌경우를 판단하며 미로탐색
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    
    queue<tuple<int, int, int>> q;  // 세개 이상의 파라미터 -> tuple을 이용한다.
    d[0][0][0] = 1;
    q.push(make_tuple(0, 0, 0));
    while(!q.empty()) {
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();
        
        for(int i = 0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(a[nx][ny] == 0 && d[nx][ny][z] == 0) {
                d[nx][ny][z] = d[x][y][z] + 1;
                q.push(make_tuple(nx, ny, z));
            }
            if(z==0 && a[nx][ny] == 1 && d[nx][ny][z+1] == 0) {
                d[nx][ny][z+1] = d[x][y][z] + 1;
                q.push(make_tuple(nx, ny, z+1));
            }
        }
    }
    
    if(d[n-1][m-1][0] != 0 && d[n-1][m-1][1] != 0)
        cout << min(d[n-1][m-1][0], d[n-1][m-1][1]);
    else if(d[n-1][m-1][0] != 0)
        cout << d[n-1][m-1][0];
    else if(d[n-1][m-1][1] != 0)
        cout << d[n-1][m-1][1];
    else
        cout << -1;
    
    puts("");
    return 0;
}
