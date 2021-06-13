#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string answer = "";

string solution(string new_id) {
	// 1�ܰ�. �빮�ڸ� �ҹ��ڷ� ġȯ
	for (int i = 0; i < new_id.size(); i++) {
		if (isupper(new_id[i])) {
			new_id[i] = tolower(new_id[i]);
		}
	}
	// 2�ܰ�. �ҹ���, ����, -, _, . ������ ��� ���� ����
	for (int i = 0; i < new_id.size(); i++) {
		if ((!islower(new_id[i])) && ((new_id[i] < 48) || (new_id[i] > 57)) && (new_id[i] != '-') &&
			(new_id[i] != '_') && (new_id[i] != '.')) {
			new_id.erase(new_id.begin() + i);
			i--;
		}
	}
	// 3�ܰ�. ��ħǥ ������ �κ� ����
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
	// 4�ܰ�. ó���̳� ���� ��ġ�� ��ħǥ ����
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
	// 5�ܰ�. �� ���ڿ��̸� a ����
	if (new_id.empty()) {
		new_id += "a";
	}
	// 6�ܰ�. 16�� �̻��̸� ù 15���� ���ڸ� ������ ������ ���� ����
	if (new_id.size() >= 16) {
		string tmp = new_id.substr(0, 15);
		new_id = tmp;
		int end = new_id.size() - 1;
		if (new_id[end] == '.') {
			new_id.erase(new_id.begin() + end);
		}
	}
	// 7�ܰ�. 2�� ���϶�� ���̰� 3�� �� ������ ������ ���� ��� ����
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