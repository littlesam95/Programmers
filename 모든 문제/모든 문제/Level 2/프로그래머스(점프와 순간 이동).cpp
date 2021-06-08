#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int ans = 0;

int solution(int n) {
	while (n > 0) {
		if (n % 2 == 0) {
			n /= 2;
		}
		else if (n % 2 == 1) {
			n -= 1;
			ans++;
		}
	};

	return ans;
}