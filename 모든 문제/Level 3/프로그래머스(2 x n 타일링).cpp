#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;
int arr[60001];

void facto(int n) {
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		arr[i] = ((arr[i - 1] % 1000000007) + (arr[i - 2] % 1000000007)) % 1000000007;
	}
}

int solution(int n) {
	facto(n);
	answer = arr[n];
	return answer;
}