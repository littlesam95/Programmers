#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<long long> answer;

vector<long long> solution(int x, int n) {
	int start = 0;
	for (int i = 1; i <= n; i++) {
		answer.push_back(start + (x * i));
	}
	return answer;
}