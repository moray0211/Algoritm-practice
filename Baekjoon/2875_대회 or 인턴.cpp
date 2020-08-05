#include <iostream>
#include <vector>

using namespace std;

int N; //여학생 수
int M; //남학생 수
int K; //인턴쉽에 참여해야 하는 사람 수
	   //2명의 여학생 + 1명의 남학생 -> 1팀
	   //즉, (2n+1m)에 의해 팀이 만들어 질 수 있다. 

int main() {
	cin >> N >> M >> K;

	while (K > 0) {

		int n = N > 1 ? N / 2 : 0; //(남학생 충분하다고 가정 시)만들 수 있는 팀의 수

		int lack = n - M; //부족한 남학생의 수
		if (lack>0) {
			//남학생이 부족할 시 부족한 만큼 여학생을 인턴에 보냄 (남학생 1명 부족시 여학생 2명 인턴 투입)
			N -= lack * 2;
			K -= lack * 2;
		}
		if (K <= 0) break;

		//팀이 만들어 질 수 있어도 학생이 부족하므로 인턴에 보내는 경우
		if (N % 2 == 0) {
			//여학생이 짝수일경우
			M -= 1;
			K -= 1;
		}
		else {
			//여학생이 홀수일경우
			N -= 1;
			K -= 1;
		}
	}

	if (N / 2 <= M) cout << N / 2; //남학생 수 충분할 시 여학생 수/2 
	else cout << M; //남학생 수 불충분할시 남학생 수
}