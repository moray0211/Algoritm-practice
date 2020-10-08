#include <iostream>
#include <string>
using namespace std;

typedef long long num;

num A, B;

num GCD(num a, num b) {
	if (b == 0) return a;
	return GCD(b, a%b);
}

int main() {
	cin >> A >> B;

	num tmp = GCD(A, B);
	string result = "";
	while (tmp--) result += '1';
	cout << result;
}