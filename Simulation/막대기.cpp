#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int getsum(vector<int> &length) {
    int s = 0;
    for(int i = 0;i<length.size();i++)
        s+=length[i];
    
    return s;
}

int main(void)
{
    vector<int> length;
    int n;
    cin >> n;
    length.push_back(64);
    while(true) {
        int sum = getsum(length);
        if(sum > n) {
            int temp = length[length.size()-1];
            length.pop_back();
            length.push_back(temp/2);
            
            if(getsum(length)>n)
                continue;
            else if(getsum(length) == n){
                cout << length.size() << '\n';
                break;
            }
            else
                length.push_back(temp/2);
        }
        else if(sum == 64){
            cout << "1" << '\n';
            break;
        }
    }
    return 0;
}



