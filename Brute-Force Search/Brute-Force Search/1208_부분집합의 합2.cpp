#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    int n, s;
    cin >> n >> s;
    long long ans = 0;
    vector<int> a(n);
    for(int i = 0;i<n;i++)
        cin >> a[i];
    int m = n/2;
    n = n-m;
    vector<int> first(1<<n);
    for(int i = 0;i<(1<<n);i++) {
        for(int k = 0;k<n;k++) {
            if(i&(1<<k))
                first[i] += a[k];
        }
    }
    vector<int> second(1<<m);
    for(int i = 0;i<(1<<m);i++) {
        for(int k = 0;k<m;k++) {
            if(i & (1<<k))
                second[i] += a[k+n];
        }
    }
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    reverse(second.begin(), second.end());
    n = (1<<n);
    m = (1<<m);
    int i = 0, j = 0;
    
    while(i<n && j<m) {
        if(first[i] + second[j] == s) {
            long long c1 = 1, c2 = 1;
            i++; j++;
            while(i<n && first[i] == first[i-1]){
                c1++; i++;
            }
            while(j<m && second[j] == second[j-1]){
                c2++; j++;
            }
            ans += c1 * c2;
        }
        else if(first[i] + second[j] <s)
            i++;
        else j++;
    }
    
    if(s==0) ans --;
    cout << ans << '\n';
    return 0;
}
