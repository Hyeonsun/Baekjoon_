#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n, male, intern;
	int female;
	cin >> n >> male >> intern;	// 여자 n명 남자 male명 인턴 intern명 만큼 입력받아

	while (intern-->0) {	// 인턴을 뽑는데
		female = n / 2;	// 여자팀은 2명이니까 일단 2로 나눈다음
		if (female >= male)	// 2로 나눈 값이 남자보다 많으면
			n--;		//여자를 빼고
		else {
			if (male == 0) break;	//남자가 0일경우는 뺄필요 없으니 break해준다.
			male--;		//아니면 남자를 뺀다
		}
	}
	int ans = n / 2 <= male ? n / 2 : male;	//남자와 여자의 차이가 심하게 날 경우 대비하여 조건문추가.
	cout << ans << '\n';
	return 0;
}