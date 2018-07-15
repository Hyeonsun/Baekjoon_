// 숫자 버튼을 누르고 + / - 를 눌러줘야 한다.
// 같은 채널을 두번 방문했으면 굳이 앞에걸 방문 안해도 되니까 정답이 될 수 없다. (중복방문)
// 1<= N <= 50만
#include <cstdio>
#include <algorithm>
using namespace std;

bool broken[10];

// 테스트 할때는 최솟값이나 최댓값을 넣었을떄! 
int possible(int c) {
	if (c == 0) {	// c==0일경우 예외처리
		return broken[0] ? 0 : 1;
	}
	int len = 0;
	while (c > 0) {	// c==0일 경우 제외 (0이 고장난 경우 제외)
		if (broken[c % 10])
			return 0;
		len++;
		c /= 10;
	}
	return len;	// 불가능하면 0 가능하면 몇번 눌러야 하나!
}

int main(void)
{
	// 이동하려는 채널 숫자버튼을 눌러서 어디로 이동해야할지를 결정해야해.
	// 0부터 50만까지 for을 도는데 고장난 버튼이 있는지 확인하면서 돌면 돼


	// 이동할 채널 C결정 --> 전체체널만들고 고장난채널 빼기(쉬워) / 정상버튼 잘 조합해서 전체만들기(어려워) - 시간복잡도 동일
	// C에 포함되어있는 숫자 중에 고장난 버튼이 있는지 확인한다.
	// 망가진 버튼이 없다면 |C-N| 을 계산해 +나 -버튼을 총 몇번 눌러야하나 계산

	int n;
	scanf("%d", &n);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		broken[x] = true;
	}
	int ans = n - 100;	// 가장 처음에 보고있는 채널이 100! ( 초기값을 n-100으로 설정!)
	if (ans < 0)
		ans = -ans; //50 --> -50

					// 망가진 버튼이 없다면 |C-N|을 계산해 + 나 -버튼을 총 몇 번 눌러야하는지를 계산한다.
	for (int i = 0; i <= 1000000; i++) {
		// 전체채널만들고 고장난채널 빼기
		int c = i;
		int len = possible(c);		// 몇번 눌러야하는지!
		if (len > 0) {
			int press = c - n;	// +나 -를 몇번 눌러야하나?
			if (press < 0)
				press = -press;
			if (ans > len + press)
				ans = len + press;
		}
	}
	printf("%d\n", ans);
	return 0;
}