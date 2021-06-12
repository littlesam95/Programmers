#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> answer;

long long calc(long long num) {
	long long res = 1;
	num /= 2;
	while (1) {
		if (num % 2 == 0) {
			break;
		}
		else if (num % 2 == 1) {
			res *= 2;
		}
		num /= 2;
	};

	return res;
}

vector<long long> solution(vector<long long> numbers) {
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] % 2 == 0) {
			answer.push_back(numbers[i] + 1);
		}
		else if (numbers[i] % 2 == 1) {
			answer.push_back(numbers[i] + calc(numbers[i]));
		}
	}

	return answer;
}