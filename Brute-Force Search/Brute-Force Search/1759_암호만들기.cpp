#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool check(string password) {
    int ja = 0;
    int mo = 0;
    for(char x: password) {
        if(x=='a' || x == 'e' || x=='i' || x=='o' || x=='u')
            mo++;
        else
            ja++;
    }
    return ja>=2 && mo>=1;
}

void go(int n, vector<char> &alpha, string password, int i) {
    
    //정답이 되는경우
    if(password.length() == n){
        if(check(password))
            cout<<password <<'\n';
        return;
    }
    //정답이 안되는경우
    if(alpha.size() == i) return;
    
    //다음경우
    go(n, alpha, password + alpha[i], i +1); //패스워드 가능한 문자
    go(n, alpha, password, i+1); //패스워드 불가능한 문자
}

int main(void)
{
    int l, c;
    cin >> l >> c;
    vector<char> alpha(c);
    for(int i = 0;i<c;i++) {
        cin >> alpha[i];
    }
    sort(alpha.begin(), alpha.end());
    go(l, alpha, "", 0);
    
    return 0;
}

