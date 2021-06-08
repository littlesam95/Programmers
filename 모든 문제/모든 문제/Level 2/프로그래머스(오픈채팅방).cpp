#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
vector<string> answer;
queue<tuple<string, string, string> > q;
unordered_map<string, string> m;
queue<pair<string, string> > answerQ;

vector<string> split(string str) {
	vector<string> internal;
	string tmp = "";
	int index = 0;
	while (index < str.size()) {
		if (index < str.size() - 1) {
			if (str[index] == ' ') {
				internal.push_back(tmp);
				tmp = "";
			}
			else {
				tmp += str[index];
			}
		}
		else if (index == str.size() - 1) {
			tmp += str[index];
			internal.push_back(tmp);
		}
		index++;
	};

	return internal;
}

vector<string> solution(vector<string> record) {
	for (int i = 0; i < record.size(); i++) {
		vector<string> tmp = split(record[i]);
		if (tmp[0] == "Leave") {
			q.push(make_tuple(tmp[0], tmp[1], " "));
		}
		else {
			q.push(make_tuple(tmp[0], tmp[1], tmp[2]));
		}
	}

	while (!q.empty()) {
		if (get<0>(q.front()) == "Enter") {
			if (m.find(get<1>(q.front())) != m.end()) {
				m.erase(get<1>(q.front()));
			}
			m.insert(make_pair(get<1>(q.front()), get<2>(q.front())));
			answerQ.push(make_pair("Enter", get<1>(q.front())));
		}
		else if (get<0>(q.front()) == "Leave") {
			answerQ.push(make_pair("Leave", get<1>(q.front())));
		}
		else if (get<0>(q.front()) == "Change") {
			m.erase(get<1>(q.front()));
			m.insert(make_pair(get<1>(q.front()), get<2>(q.front())));
		}
		q.pop();
	}

	while (!answerQ.empty()) {
		if (answerQ.front().first == "Enter") {
			string tmp = m[answerQ.front().second] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
			answer.push_back(tmp);
		}
		if (answerQ.front().first == "Leave") {
			string tmp = m[answerQ.front().second] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
			answer.push_back(tmp);
		}
		answerQ.pop();
	}

	return answer;
}