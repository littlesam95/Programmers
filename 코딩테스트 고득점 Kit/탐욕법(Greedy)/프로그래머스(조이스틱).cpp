#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;
int arr[20];

int solution(string name) {
	for (int i = 0; i < name.size(); i++) {
		if (name[i] != 'A') {
			arr[i] = 1;
		}
		else {
			arr[i] = 0;
		}
	}
	int idx = 0;
	while (1) {
		if (name[idx] - 'A' <= 12) {
			answer += (name[idx] - 'A');
		}
		else {
			answer += abs(name[idx] - 'A' - 26);
		}
		arr[idx] = 0;
		bool b = true;
		for (int i = 0; i < name.size(); i++) {
			if (arr[i] == 1) {
				b = false;
				true;
			}
		}
		if (b) {
			break;
		}
		else {
			for (int move = 1; move < name.size(); move++) {
				int left = idx - move;
				int right = idx + move;
				if (left < 0) {
					left = name.size() + left;
				}
				if (right > name.size() - 1) {
					right = right - name.size();
				}
				if ((arr[left] == 1) && (arr[right] == 0)) {
					answer += move;
					idx = left;
					break;
				}
				else if ((arr[left] == 0) && (arr[right] == 1)) {
					answer += move;
					idx = right;
					break;
				}
				else if ((arr[left] == 1) && (arr[right] == 1)) {
					answer += move;
					idx = right;
					break;
				}
				else if ((arr[left] == 0) && (arr[right] == 0)) {
					continue;
				}
			}
		}
	}

	return answer;
}