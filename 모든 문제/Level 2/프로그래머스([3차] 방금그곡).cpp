#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string answer = "";
int big_total_time = 0;

vector<string> musicinfo(string A) {
	vector<string> res;
	string tmp = "";
	int index = 0;
	while (index <= A.length()) {
		if ((A.substr(index, 1) == ",") || (index == A.length())) {
			res.push_back(tmp);
			tmp = "";
		}
		else {
			tmp += A.substr(index, 1);
		}
		index++;
	};

	return res;
}

string solution(string m, vector<string> musicinfos) {
	for (int i = 0; i < musicinfos.size(); i++) {
		string res_tmp;
		int res_time;
		vector<string> info = musicinfo(musicinfos[i]);
		int start_hour = stoi(info[0].substr(0, 2));
		int start_min = stoi(info[0].substr(3, 2));
		int end_hour = stoi(info[1].substr(0, 2));
		int end_min = stoi(info[1].substr(3, 2));
		int total_time = ((end_hour - start_hour) * 60) + (end_min - start_min);
		int index = 0;
		string score[1440];
		for (int j = 0; j < total_time; j++) {
			string tmp = "";
			tmp += info[3].substr(index, 1);
			if (info[3].substr(index + 1, 1) == "#") {
				tmp += info[3].substr(index + 1, 1);
				index++;
			}
			score[j] = tmp;
			index++;
			if (index == info[3].size()) {
				index = 0;
			}
		}
		string m_score[1440];
		index = 0;
		int m_score_idx = 0;
		while (index < m.length()) {
			string tmp = "";
			tmp += m.substr(index, 1);
			if (m.substr(index + 1, 1) == "#") {
				tmp += m.substr(index + 1, 1);
				index++;
			}
			m_score[m_score_idx] = tmp;
			index++;
			m_score_idx++;
		};
		// 여기서 m의 길이가 전체 악보의 길이보다 크다는 조건을 걸면 실패하는 테스트 케이스가 생긴다. 왜 그런지는 모르겠음.
		// 실패하는 테스트 케이스는 3, 6, 7, 18, 19
		for (int j = 0; j <= (total_time - m_score_idx); j++) {
			bool b = true;
			int m_idx = 0;
			for (int k = j; k < j + m_score_idx; k++) {
				if (m_score[m_idx] != score[k]) {
					b = false;
					break;
				}
				else {
					m_idx++;
				}
			}
			if (b) {
				res_tmp = info[2];
				res_time = total_time;
				break;
			}
		}
		if (answer == "") {
			answer = res_tmp;
			big_total_time = res_time;
		}
		else {
			if (big_total_time < res_time) {
				answer = res_tmp;
				big_total_time = res_time;
			}
		}
	}

	if (answer != "") {
		return answer;
	}
	else {
		return "(None)";
	}
}