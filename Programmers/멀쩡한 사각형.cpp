using namespace std;

//�ִ�����
int gcd(int a, int b) {
	return (a%b == 0) ? b : gcd(b, a%b);
}

long long solution(int w, int h) {
	long long answer = 1;

	//�� ��Ͽ��� (���� + ���� - 1) ��ŭ ��������
	//ū ����� ���� ��ϵ�� ������ Ǯ��
	//8*12����� 2*3��� 4��(�ִ�����)�� ���� �� �ִ�. -> (2+3-1) * 4 = 16���� ��� �ս�

	long long area = (long long)w * (long long)h; //������ ����
	int n = gcd(w, h);
	long long errorBlock = w + h - n;

	answer = area - errorBlock;

	return answer;
}

