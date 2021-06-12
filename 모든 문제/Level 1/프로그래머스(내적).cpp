#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;

int solution(vector<int> a, vector<int> b) {
	for (int i = 0; i < a.size(); i++) {
		answer += (a[i] * b[i]);
	}

	return answer;
}