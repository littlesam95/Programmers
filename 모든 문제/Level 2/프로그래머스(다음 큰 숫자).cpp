#include <string>
#include <vector>

using namespace std;
int answer = 0;

int change(int N) {
	int one_cnt = 0;
	while (N > 0) {
		int num = (N % 2 == 1) ? 1 : 0;
		if (num == 1) {
			one_cnt++;
		}
		N /= 2;
	};

	return one_cnt;
}

int solution(int n) {
	int n_one_cnt = change(n);
	while (1) {
		n++;
		if (n_one_cnt == change(n)) {
			answer = n;
			break;
		}
		else continue;
	};

	return answer;
}