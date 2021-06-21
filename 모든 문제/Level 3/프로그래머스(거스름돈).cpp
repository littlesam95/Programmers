#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;
long long dp[100001];

int solution(int n, vector<int> money) {
	dp[0] = 1; // 0원을 만들 수 있는 가짓수는 1가지
	for (int i = money[0]; i <= n; i += money[0]) { // money의 첫 번째 화폐 단위로 만들 수 있는 i원은 1가지씩 존재한다.
		dp[i] = 1;
	}

	for (int i = 1; i < money.size(); i++) {
		for (int j = 0; j <= n; j++) {
			if (j >= money[i]) {
				dp[j] += dp[j - money[i]] % 1000000007;
			}
		}
	}
	answer = dp[n];
	return answer;
}

/*
	#include <string>
	#include <vector>
	#include <algorithm>

	using namespace std;
	int answer = 0;

	// 백트래킹을 사용하여 풀어서 테스트케이스는 다 통과했지만 효율성에서 시간 초과가 발생하였다.
	void calc(vector<int> money, int idx, int charge) {
		if (idx < money.size()) {
			if (charge < 0) {
				return;
			}
			else if (charge == 0) {
				answer++;
				if (answer > 1000000007) {
					answer %= 1000000007;
				}
				return;
			}
			else {
				for (int i = 0; i <= (charge / money[idx]); i++) {
					calc(money, idx + 1, charge - (money[idx] * i));
				}
			}
		}
		else if (idx == money.size()) {
			if (charge < 0) {
				return;
			}
			else if (charge == 0) {
				answer++;
				if (answer > 1000000007) {
					answer %= 1000000007;
				}
				return;
			}
		}
	}

	int solution(int n, vector<int> money) {
		int idx = 0;
		for (int i = 0; i <= (n / money[idx]); i++) {
			calc(money, idx + 1, n - (money[idx] * i));
		}

		return answer;
	}
*/