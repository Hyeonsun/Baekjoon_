#include <cstdio>
using namespace std;

int a[12];
int go(int sum, int goal) {
    if(sum >goal) return 0;
    if(sum == goal) return 1;
    
    int now = 0;
    for(int i = 1;i<=3;i++) {
        now += go(sum + i, goal);
    }
    return now;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i = 0;i<n;i++){
        scanf("%d", &a[i]);
        printf("%d\n", go(0, a[i]));
    }
    
    return 0;
}
