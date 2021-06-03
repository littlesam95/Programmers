#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;

int solution(vector<vector<int> > land) {
	vector<vector<int> > sumLand;
	int index = -1;
	int big;
	int first = 0;
	int second = 0;
	for (int i = 0; i < land.size(); i++) {
		big = 0;
		vector<int> tmp;
		int tmp_idx;
		for (int j = 0; j < land[i].size(); j++) {
			if (index == j) {
				int number = second + land[i][j];
				tmp.push_back(number);
			}
			else {
				int number = first + land[i][j];
				tmp.push_back(number);
			}
			if (big < tmp[j]) {
				big = tmp[j];
				tmp_idx = j;
			}
		}
		index = tmp_idx;
		sumLand.push_back(tmp);
		sort(sumLand[i].begin(), sumLand[i].end());
		first = sumLand[i][3];
		second = sumLand[i][2];
	}
	int size = sumLand.size();
	sort(sumLand[size - 1].begin(), sumLand[size - 1].end());
	answer = sumLand[size - 1][3];
	return answer;
}