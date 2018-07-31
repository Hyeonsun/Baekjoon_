#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int s[20][20];
int n;

int go(int index, vector<int> &first, vector<int> &second) {
    if(index == n) {
        //정답이 아닌경우
        if(first.size() != n/2) return -1;      //문제의 조건
        if(second.size() != n/2) return -1;
        
        //정답인경우
        int t1 = 0, t2 = 0;
        for(int i = 0;i<n/2;i++){
            for(int j = 0;j<n/2;j++) {
                if(i==j) continue;
                t1 += s[first[i]][first[j]];    //팀원간의 능력치의 합
                t2 += s[second[i]][second[j]];
            }
        }
        int diff = t1 - t2; //능력치의 합의 차이를 구해서 그값이 최소가 되게끔!
        if(diff<0) diff = -diff;
        return diff;
    }
    //다음경우
    int ans = -1;
    first.push_back(index);
    int t1 = go(index + 1, first, second);
    if(ans == -1 || (t1 != -1 && ans >t1))
        ans = t1;
    
    first.pop_back();
    second.push_back(index);
    int t2 = go(index +1, first, second);
    if(ans == -1 || (t2 != -1 && ans > t2))
        ans = t2;
    second.pop_back();
    return ans;
    
}

int main(void)
{
    cin >> n;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++)
            cin >> s[i][j];
    }
    
    vector<int> first, second;
    cout << go(0, first, second) << '\n';
    
    return 0;
}
