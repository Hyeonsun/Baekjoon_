#include <cstdio>
#include <algorithm>
using namespace std;
long long d[1001];
int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i = 1;i<=n;i++) {
        d[i] = d[i-1] + 1; // a만 누를경우
        for(int j = 1;j<=i-3;j++) {
            long long cur = d[i-(j+2)] * (j+1);
            d[i] = max(d[i], cur);
        }
    }
    printf("%lld\n", d[n]);
    return 0;
}
