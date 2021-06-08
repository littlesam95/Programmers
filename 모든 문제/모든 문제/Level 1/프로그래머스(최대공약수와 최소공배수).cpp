#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> answer;

int gcd(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	};
	return a;
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

vector<int> solution(int n, int m) {
	int tmp;
	if (n > m) {
		tmp = n;
		n = m;
		m = tmp;
	}
	answer.push_back(gcd(n, m));
	answer.push_back(lcm(n, m));
	return answer;
}