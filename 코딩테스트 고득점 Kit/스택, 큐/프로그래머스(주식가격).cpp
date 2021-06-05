#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> answer;
int arr[100001] = { 0, };

vector<int> solution(vector<int> prices) {
	for (int i = 0; i < prices.size(); i++) {
		for (int j = i + 1; j < prices.size(); j++) {
			if ((prices[i] > prices[j]) || (j == prices.size() - 1)) {
				arr[i] = j - i;
				break;
			}
			else continue;
		}
	}

	for (int i = 0; i < prices.size(); i++) {
		answer.push_back(arr[i]);
	}

	return answer;
}