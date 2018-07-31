#include <iostream>
#include <vector>
using namespace std;

int n;
int t[15], p[15];
int solve(int day, int sum) {
    //정답이 되는 경우
    if(day == n)
        return sum + p[day];
    
    //정답이 되지 않는 경우
    if(day > n) return 0;
    
    //다음 경우
    return max(solve(day + t[day], sum + p[day]), solve(day + 1, sum));
}

int main(void)
{
    cin >> n;
    for(int i = 0;i<n;i++)
        cin >> t[i] >> p[i];
    
    printf("%d\n", solve(0, 0));
    
    return 0;
}
