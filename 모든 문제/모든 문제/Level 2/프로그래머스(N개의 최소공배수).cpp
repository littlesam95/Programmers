#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;

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

int solution(vector<int> arr) {
	sort(arr.begin(), arr.end());
	for (int i = 0; i < (arr.size() - 1); i++) {
		answer = lcm(arr[i], arr[i + 1]);
		arr[i + 1] = answer;
	}

	return answer;
}