#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;

int solution(int n) {
	for (int i = 1; i <= (n / 2); i++) {
		int sum = 0;
		int index = i;
		while (1) {
			if (sum < n) {
				sum += index;
				index++;
			}
			else if (sum > n) {
				break;
			}
			else {
				answer++;
				break;
			}
		};
	}
	return answer + 1;
}