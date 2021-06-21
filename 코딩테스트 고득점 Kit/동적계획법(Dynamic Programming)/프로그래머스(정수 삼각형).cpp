#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;
int arr[500][500] = { 0, };

int solution(vector<vector<int>> triangle) {
	for (int i = 0; i < triangle.size(); i++) {
		if (i == 0) {
			arr[i][0] = triangle[i][0];
			answer = max(answer, arr[i][0]);
		}
		else {
			for (int j = 0; j < triangle[i - 1].size(); j++) {
				arr[i][j] = max(arr[i][j], arr[i - 1][j] + triangle[i][j]);
				answer = max(answer, arr[i][j]);
				arr[i][j + 1] = max(arr[i][j + 1], arr[i - 1][j] + triangle[i][j + 1]);
				answer = max(answer, arr[i][j + 1]);
			}
		}
	}

	return answer;
}