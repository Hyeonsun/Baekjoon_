#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

int main(void)
{
	stack<int> s;
	int co = 0;

	char str[100001];
	scanf("%s", str);

	int len = strlen(str);

	for (int i = 0; i < len; i++) {
		if (str[i] == '(') {
			s.push(i);
		}
		else {
			if (s.top() + 1 == i) { //�������� ���
				s.pop();
				co += s.size();
			}
			else {// �踷����ΰ��
				s.pop();
				co++;
			}
		}
	}

	printf("%d\n", co);
	return 0;
}