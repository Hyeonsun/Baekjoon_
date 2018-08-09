#include <cstdio>
#include <algorithm>
using namespace std;

int a[1001][1001];
int d[1001][1001];
int max3(int x, int y, int z) {
    return max(max(x, y), z);
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=m;j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            d[i][j] = max3(d[i-1][j], d[i][j-1], d[i-1][j-1]) + a[i][j];
        }
    }
    
    printf("%d\n", d[n][m]);
    return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;
int max3(int x, int y, int z) {
    return max(x, max(y, z));
}
int a[1001][1001];
int d[1001][1001];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    d[1][1] = a[1][1];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            // ->
            if (j+1 <= m && d[i][j+1] < d[i][j] + a[i][j+1]) {
                d[i][j+1] = d[i][j] + a[i][j+1];
            }
            // 아래
            if (i+1 <= n && d[i+1][j] < d[i][j] + a[i+1][j]) {
                d[i+1][j] = d[i][j] + a[i+1][j];
            }
            // 대각선 아래 오른쪽
            if (i+1 <= n && j+1 <= m && d[i+1][j+1] < d[i][j] + a[i+1][j+1]) {
                d[i+1][j+1] = d[i][j] + a[i+1][j+1];
            }
        }
    }
    printf("%d\n",d[n][m]);
    return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;
int a[1001][1001];
int d[1001][1001];
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            d[i][j] = max(d[i-1][j],d[i][j-1])+a[i][j];
        }
    }
    printf("%d\n",d[n][m]);
    return 0;
}
