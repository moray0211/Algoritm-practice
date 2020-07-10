#include <string>
#include <vector>
#include <queue>

using namespace std;

queue <int> q;
int num = 0;

//Ư���� ���������κ��� ����� ���...�׸��� ������ ������ �˱� �����̹Ƿ� BFS ��� (�а� Ž��)
//BFS�� ��� ������ �ִ� ��� Ȥ�� Ư�� ��θ� ã�� ������ ���� ����
void BFS(int n, vector<vector<int>> computers) {
	vector<bool> discovered(n, false);

	//��� ��ǻ�� ���� ����
	for (int k = 0; k<n; k++) {

		//ó�� �߰��ߴٸ� ��Ʈ��ũ �� ���� �� ť�� �߰�.
		//��� ��Ʈ��ũ�� ���� ��ǻ�ʹ� �Ʒ� while������ �߰��� �� �����Ƿ�, �߰ߵ��� ���ߴٸ� �� ��Ʈ��ũ�� ���Ե��� �ǹ�.
		if (!discovered[k]) {
			num++;
			q.push(k);
			discovered[k] = true;
		}

		//ť�� ��������(���� ��ǻ�Ϳ� ������������ ����� ��ǻ�͸� ��� �߰�, �湮�Ҷ�����) �ݺ�
		while (!q.empty()) {
			int here = q.front();
			q.pop();
			for (int i = 0; i<n; i++) {
				if (computers[here][i] == 1 && !discovered[i]) {
					discovered[i] = true;
					q.push(i);
				}
			}
		}
	}

}

//��ǻ���� ���� n, ���������� ����� computers
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	BFS(n, computers);
	answer = num;

	return answer;
}