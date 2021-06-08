#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
vector<int> answer;

vector<int> solution(vector<int> arr) {
	int index = 0;
	while (index < arr.size()) {
		int num = arr[index];
		index++;
		for (int i = index; i < arr.size(); i++) {
			if (num == arr[i]) {
				index++;
			}
			else {
				break;
			}
		}
		answer.push_back(num);
	};

	return answer;
}