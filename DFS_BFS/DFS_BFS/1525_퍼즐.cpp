#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main(void)
{
    int n = 3;
    int start = 0;
    for(int i = 0;i<3;i++) {
        for(int j = 0;j<3;j++) {                // 1 12 123
            int temp;                           // ....
            cin >> temp;
            if(temp == 0) temp = 9;
            start = start * 10 + temp;          // 123456789 이런식으로 start는 하나의 정수로 나열된다.
        }
    }
    queue<int> q;
    map<int, int> dist; // key에 대한 value값을 저장하는 java의 hashmap 과 같다.
    dist[start] = 0;    // 처음의 퍼즐 상태가 key 로 그때의 distance 가 0으로 세팅한다.
    q.push(start);      // queue 에 푸쉬!
    
    while(!q.empty()) {
        int now_num = q.front();
        string now = to_string(now_num);    //현재의 퍼즐을 스트링으로 바꿔서
        q.pop();
        int z = now.find('9');
        int x = z/3;        // 9의 위치는 공백이므로 9의 위치를 찾고 그때의 x와 y좌표의 값을 찾는다.
        int y = z%3;
        
        for(int k = 0;k<4;k++) {
            int nx = x + dx[k];     //좌표값을 이동해주면서 거리를 계산한다.
            int ny = y + dy[k];
            
            if(nx>=0 && nx<n && ny>=0 && ny< n){
                string next = now;
                swap(next[x*3 + y], next[nx*3+ny]);
                int num = stoi(next);
                if(dist.count(num)==0) {    // 아직 확인되지 않은 퍼즐이면
                    dist[num] = dist[now_num] + 1;  // +1해준다.
                    q.push(num);
                }
            }
        }
    }
    if(dist.count(123456789) == 0)  // 아직 123456789가 발견되지 않았다면 -1 출력
        cout << -1 << '\n';
    else
        cout << dist[123456789] << '\n';
    
    return 0;
}
