#include <iostream>
#include <vector>
using namespace std;

int n, m;
int a[20];
int solve(int index, int sum) {
    //정답이 되는경우
    if(index == n && sum == m)
        return 1;
    
    //정답이 안되는 경우
    if(index == n && sum != m)
        return 0;
    
    //다음경우
    int now = 0;
    now += solve(index + 1, sum);
    now += solve(index + 1, sum + a[index]);
    
    return now;
    
}

int main(void)
{
    
    cin >>n >> m;
    
    
    for(int i = 0;i<n;i++) {
        cin >>a[i];
    }
    
    int ans = solve(0, 0);
    if(m==0) ans--; //m==0 일경우는 제외해준다.
    cout<<ans <<'\n';
    
    return 0;
}
