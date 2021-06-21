#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;
long long dp[100001];

int solution(int n, vector<int> money) {
	dp[0] = 1; // 0���� ���� �� �ִ� �������� 1����
	for (int i = money[0]; i <= n; i += money[0]) { // money�� ù ��° ȭ�� ������ ���� �� �ִ� i���� 1������ �����Ѵ�.
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

	// ��Ʈ��ŷ�� ����Ͽ� Ǯ� �׽�Ʈ���̽��� �� ��������� ȿ�������� �ð� �ʰ��� �߻��Ͽ���.
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