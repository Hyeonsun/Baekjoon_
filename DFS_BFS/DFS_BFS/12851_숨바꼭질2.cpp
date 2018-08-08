#include <iostream>
#include <queue>
using namespace std;
const int MAX = 200000;
bool check[MAX + 1];
int dist[MAX + 1];
long long cnt[MAX + 1];

int main(void)
{
    int n, m;
    cin >> n >> m;
    dist[n] = 0;
    check[n] = true;
    cnt[n] = 1;
    
    queue<int> q;
    q.push(n);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        
        for(int next : {now-1, now+1, now*2}) {
            if(0<=next && next <=MAX ) {
                if(check[next] == false) {
                    dist[next] = dist[now] + 1;
                    check[next] = true;
                    cnt[next] = cnt[now];
                    q.push(next);
                }
                else if(dist[next] == dist[now] + 1) {
                    cnt[next] += cnt[now];
                }
            }
        }
    }
    cout << dist[m] << '\n';
    cout << cnt[m] << '\n';
    return 0;
}
