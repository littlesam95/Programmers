#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
vector<int> answer;

vector<int> solution(string msg) {
	map<string, int> dict;
	for (int i = 1; i <= 26; i++) {
		string tmp = "";
		tmp += (char)(64 + i);
		dict.insert(make_pair(tmp, i));
	}
	int index = 0;
	int dict_idx = 27;
	while (index < msg.size()) {
		int next_idx = 1;
		string now = "";
		now += msg[index];
		while (1) {
			string tmp = now + msg[index + next_idx];
			if (dict.find(tmp) == dict.end()) {
				answer.push_back(dict[now]);
				dict.insert(make_pair(tmp, dict_idx));
				dict_idx++;
				break;
			}
			else {
				now = tmp;
				next_idx++;
			}
		};
		index += next_idx;
	};

	return answer;
}