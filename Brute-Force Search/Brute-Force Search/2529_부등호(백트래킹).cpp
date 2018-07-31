#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n;
char a[20];
vector<string> ans;
bool check[10];

bool good(char x, char y, char op) {
    if(op == '<')
        if(x>y) return false;
    if(op == '>')
        if(x<y) return false;
    return true;
}


void go(int index, string num) {
    //정답이 되는경우
    if(index == n + 1) {
        ans.push_back(num);
        return;
    }
    
    //정답이 안되는경우
    
    if(index > n+1)
        return;
    
    //다음경우
    for(int i = 0;i<=9;i++) {
        if(check[i]) continue;
        if(index == 0 || good(num[index-1], i + '0', a[index-1])){ //**backtracking**
            check[i] = true;
            go(index + 1, num + to_string(i));
            check[i] = false; // necessary
        }
    }
}
int main(void)
{
    cin >> n;
    for(int i = 0;i<n;i++)
        cin >> a[i];
    
    go(0, "");
    
    auto p = minmax_element(ans.begin(), ans.end());
    cout << *p.second <<'\n';
    cout << *p.first << '\n';
    return 0;
}
