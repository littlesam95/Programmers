#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
int zeroCnt = 0;
int correct = 0;
int high = 0;
int low = 6;
vector<int> answer;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	sort(lottos.begin(), lottos.end());
	for (int i = 0; i < lottos.size(); i++) {
		if (lottos[i] == 0) {
			zeroCnt++;
		}
		else {
			break;
		}
	}
	for (int i = zeroCnt; i < lottos.size(); i++) {
		for (int j = 0; j < win_nums.size(); j++) {
			if (lottos[i] == win_nums[j]) {
				correct++;
				break;
			}
		}
	}
	if (correct <= 1) {
		low = 6;
		if (zeroCnt == 6) {
			high = 1;
		}
		else {
			high = low - zeroCnt;
		}
	}
	else if (correct > 1) {
		low -= correct - 1;
		high = low - zeroCnt;
	}
	answer.push_back(high);
	answer.push_back(low);
	return answer;
}