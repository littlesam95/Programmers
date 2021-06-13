#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string answer = "";

string solution(string new_id) {
	// 1단계. 대문자를 소문자로 치환
	for (int i = 0; i < new_id.size(); i++) {
		if (isupper(new_id[i])) {
			new_id[i] = tolower(new_id[i]);
		}
	}
	// 2단계. 소문자, 숫자, -, _, . 제외한 모든 문자 제거
	for (int i = 0; i < new_id.size(); i++) {
		if ((!islower(new_id[i])) && ((new_id[i] < 48) || (new_id[i] > 57)) && (new_id[i] != '-') &&
			(new_id[i] != '_') && (new_id[i] != '.')) {
			new_id.erase(new_id.begin() + i);
			i--;
		}
	}
	// 3단계. 마침표 연속인 부분 제거
	int idx = 0;
	new_id += "#";
	while (idx < new_id.size()) {
		if (new_id[idx] == '.') {
			for (int i = idx + 1; i < new_id.size(); i++) {
				if (new_id[i] == '.') {
					new_id.erase(new_id.begin() + i);
					i--;
				}
				else {
					idx = i;
					break;
				}
			}
		}
		else {
			idx++;
		}
	};
	int last = new_id.size() - 1;
	new_id.erase(new_id.begin() + last);
	// 4단계. 처음이나 끝에 위치한 마침표 제거
	if (!new_id.empty()) {
		if (new_id[0] == '.') {
			new_id.erase(new_id.begin() + 0);
		}
	}
	if (!new_id.empty()) {
		int end = new_id.size() - 1;
		if ((new_id[end] == '.') && (!new_id.empty())) {
			new_id.erase(new_id.begin() + end);
		}
	}
	// 5단계. 빈 문자열이면 a 대입
	if (new_id.empty()) {
		new_id += "a";
	}
	// 6단계. 16자 이상이면 첫 15개의 문자를 제외한 나머지 문자 제거
	if (new_id.size() >= 16) {
		string tmp = new_id.substr(0, 15);
		new_id = tmp;
		int end = new_id.size() - 1;
		if (new_id[end] == '.') {
			new_id.erase(new_id.begin() + end);
		}
	}
	// 7단계. 2자 이하라면 길이가 3이 될 때까지 마지막 문자 계속 나열
	if (new_id.size() <= 2) {
		int end = new_id.size() - 1;
		int size = new_id.size();
		char end_char = new_id[end];
		for (int i = 0; i < (3 - size); i++) {
			new_id += end_char;
		}
	}
	answer = new_id;
	return answer;
}