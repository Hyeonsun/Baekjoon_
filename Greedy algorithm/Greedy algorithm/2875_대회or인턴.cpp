#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n, male, intern;
	int female;
	cin >> n >> male >> intern;	// ���� n�� ���� male�� ���� intern�� ��ŭ �Է¹޾�

	while (intern-->0) {	// ������ �̴µ�
		female = n / 2;	// �������� 2���̴ϱ� �ϴ� 2�� ��������
		if (female >= male)	// 2�� ���� ���� ���ں��� ������
			n--;		//���ڸ� ����
		else {
			if (male == 0) break;	//���ڰ� 0�ϰ��� ���ʿ� ������ break���ش�.
			male--;		//�ƴϸ� ���ڸ� ����
		}
	}
	int ans = n / 2 <= male ? n / 2 : male;	//���ڿ� ������ ���̰� ���ϰ� �� ��� ����Ͽ� ���ǹ��߰�.
	cout << ans << '\n';
	return 0;
}