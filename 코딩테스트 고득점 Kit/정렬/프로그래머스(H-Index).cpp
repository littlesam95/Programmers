#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int res = 0;

int solution(vector<int> citations) {
	sort(citations.begin(), citations.end());
	for (int i = 0; i <= 10000; i++) {
		int up = citations.size() - (lower_bound(citations.begin(), citations.end(), i) - citations.begin());
		if (up == 0) {
			break;
		}
		else {
			if (i <= up) {
				res = max(res, i);
			}
		}
	}

	return res;
}