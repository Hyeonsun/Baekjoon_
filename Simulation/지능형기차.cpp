#include <iostream>
using namespace std;

int main(void)
{
    int people = 0;
    int max = 0;
    
    for(int i = 0;i<4;i++) {
        int n, m;
        cin >> n >> m;
        people -= n;
        if(people <0) people = 0;
        people += m;
        if(people > max)
            max = people;
    }
    cout << max << '\n';
    return 0;
}
