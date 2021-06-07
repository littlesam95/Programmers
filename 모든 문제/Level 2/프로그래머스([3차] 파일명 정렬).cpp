#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
vector<string> answer;

bool comp(pair<tuple<string, string, string>, int> A, pair<tuple<string, string, string>, int> B) {
	for (int i = 0; i < get<0>(A.first).size(); i++) {
		if ((int(get<0>(A.first)[i]) >= 65) && (int(get<0>(A.first)[i]) <= 90)) {
			get<0>(A.first)[i] = (char)(int(get<0>(A.first)[i]) + 32);
		}
	}
	for (int i = 0; i < get<0>(B.first).size(); i++) {
		if ((int(get<0>(B.first)[i]) >= 65) && (int(get<0>(B.first)[i]) <= 90)) {
			get<0>(B.first)[i] = (char)(int(get<0>(B.first)[i]) + 32);
		}
	}
	int numA = stoi(get<1>(A.first));
	int numB = stoi(get<1>(B.first));
	if (get<0>(A.first) == get<0>(B.first)) {
		if (numA < numB) {
			return true;
		}
		else if (numA > numB) {
			return false;
		}
		else {
			return A.second < B.second;
		}
	}
	else if (get<0>(A.first) < get<0>(B.first)) {
		return true;
	}
	else if (get<0>(A.first) > get<0>(B.first)) {
		return false;
	}
}

vector<string> solution(vector<string> files) {
	vector<pair<tuple<string, string, string>, int> > hnt;
	for (int i = 0; i < files.size(); i++) {
		int index = 0;
		int num = 0;
		string head = "";
		string number = "";
		string tail = "";
		while (index < files[i].size()) {
			if ((num == 0) && ((int(files[i][index]) < 48) || (int(files[i][index]) > 57))) {
				head += files[i][index];
				index++;
			}
			else if ((num >= 0) && (num <= 4) && (int(files[i][index]) >= 48) && (int(files[i][index]) <= 57)) {
				number += files[i][index];
				num++;
				index++;
			}
			else if ((num >= 5) || ((int(files[i][index]) < 48) || (int(files[i][index]) > 57))) {
				num = 5;
				tail += files[i][index];
				index++;
			}
		};
		hnt.push_back(make_pair(make_tuple(head, number, tail), i));
	}
	sort(hnt.begin(), hnt.end(), comp);

	for (int i = 0; i < hnt.size(); i++) {
		string tmp = get<0>(hnt[i].first) + get<1>(hnt[i].first) + get<2>(hnt[i].first);
		answer.push_back(tmp);
	}

	return answer;
}