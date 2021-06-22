#include <string>
#include <vector>
#include <algorithm>

using namespace std;
long long answer = 0;
long long arr[2001];

void func(int n) {
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		arr[i] = ((arr[i - 1] % 1234567) + (arr[i - 2] % 1234567)) % 1234567;
	}
}

long long solution(int n) {
	func(n);
	answer = arr[n];

	return answer;
}