#include <cstdio>
using namespace std;

int d[101][101];
int a[101];
int c[101][101];
int min = -32768 * 101;

int go(int n, int m) {
    if(m==0) return 0;
    if(n<=0) return min;
    if(c[n][m]) return d[n][m]; //memorization
    
    c[n][m] = true;
    int &ans = d[n][m];
    ans = go(n-1, m); // i번째수를 그룹에 추가하는경우
    int sum = 0;
    for(int k = n;k>=1;k--) {   // k번째부터 그룹에 추가
        sum += a[k];        // a[k] 부터 a[1] 까지 그룹에 추가해야하므로 sum 에 더해줌.
        int temp = go(k-2, m-1) + sum;  // k-2인경우는 붙어있으면 안되기 떄문에.
        if(ans < temp)ans = temp;
    }
    
    return ans;
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i<=n;i++)
        scanf("%d", &a[i]);
    
    printf("%d\n", go(n, m));
    return 0;
}
