using namespace std;

//최대공약수
int gcd(int a, int b) {
	return (a%b == 0) ? b : gcd(b, a%b);
}

long long solution(int w, int h) {
	long long answer = 1;

	//한 블록에선 (가로 + 세로 - 1) 만큼 지나간다
	//큰 블록은 작은 블록들로 나누어 풀기
	//8*12블록은 2*3블록 4개(최대공약수)로 나눌 수 있다. -> (2+3-1) * 4 = 16개의 블록 손실

	long long area = (long long)w * (long long)h; //범위에 주의
	int n = gcd(w, h);
	long long errorBlock = w + h - n;

	answer = area - errorBlock;

	return answer;
}

