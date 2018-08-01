#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
int sign[10][10];
int ans[10];

// 다시보기

bool check(int index) {
    int sum = 0;
    for(int i = index;i>=0;i--) {
        sum += ans[i];
        if(sign[i][index] == 0)
            if(sum != 0) return false;
        else if(sign[i][index] >0)
            if(sum <= 0) return false;
        else if(sign[i][index] <0)
            if(sum >= 0) return false;
    }
        return true;
}

bool go(int index) {
    //정답인 경우
    if(index == n) {
        return true;
    }
    //정답이 아닌경우
    if(index > n)
        return false;
    
    //다음 경우
    if(sign[index][index] == 0){
        ans[index] = 0;
        return check(index) && go(index + 1);
    }
    
    for(int i = 1;i<=10;i++) {
        ans[index] = sign[index][index] * i;
        if(check(index) && go(index + 1)) return true;
    }
    
    return false;
}

int main(void)
{
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            if(s[cnt] == '0')
                sign[i][j] = 0;
            else if(s[cnt] == '+')
                sign[i][j] = 1;
            else if(s[cnt] == '-')
                sign[i][j] = -1;
            cnt++;
        }
    }
    cout <<'\n';
    return 0;
}
