#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;
int arr[50000] = { 0, };

int solution(vector<int> people, int limit) {
	for (int i = 0; i < people.size(); i++) {
		arr[i] = 1;
	}
	sort(people.begin(), people.end(), greater<int>());
	int index = 0;
	int end = people.size() - 1;
	while (people[index] > (limit / 2)) {
		if (arr[index] == 1) {
			arr[index] = 0;
			if ((arr[end] == 1) && (people[end] + people[index] <= limit)) {
				arr[end] = 0;
				end--;
			}
			answer++;
			index++;
		}
		else if (arr[index] == 0) {
			index++;
		}
	};
	int person = 0;
	for (int i = 0; i < people.size(); i++) {
		if (arr[i] == 1) {
			person++;
		}
	}
	if (person % 2 == 0) {
		answer += (person / 2);
	}
	else if (person % 2 == 1) {
		answer += (person / 2) + 1;
	}

	return answer;
}