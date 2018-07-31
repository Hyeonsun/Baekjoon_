#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> lotto;
void go(vector<int> &a, int index, int cnt) {
    //정답이 되는경우
    if(cnt == 6) {
        for(int num:lotto)
            cout<<num << ' ';
        cout<<'\n';
        return;
    }
    
    
    //정답이 되지 않는 경우
    if(index == a.size()) return;
    
    //다음 경우
    lotto.push_back(a[index]);
    go(a, index + 1, cnt + 1);
    lotto.pop_back();
    go(a, index + 1, cnt);
}

int main(void)
{
    
    while(true) {
        int n;
        cin >> n;
        if(n==0) break;
        vector<int> a(n);
        
        for(int i = 0;i<n;i++)
            cin>>a[i];
        
        go(a, 0, 0);
        cout<<'\n';
    }
    
    return 0;
}
