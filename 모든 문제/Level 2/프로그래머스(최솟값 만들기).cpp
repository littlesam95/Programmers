#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;

int solution(vector<int> A, vector<int> B) {
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());
	for (int i = 0; i < A.size(); i++) {
		answer += A[i] * B[i];
	}

	return answer;
}