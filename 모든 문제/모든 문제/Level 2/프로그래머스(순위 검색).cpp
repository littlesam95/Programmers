#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
vector<int> answer;

vector<string> querySplit(string str) {
	vector<string> vec;
	string tmp;
	for (char c : str) {
		if (c == ' ') {
			vec.push_back(tmp);
			tmp = "";
		}
		else {
			tmp += c;
		}
	}
	vec.push_back(tmp);
	return vec;
}

vector<int> infoSplit(string str) {
	vector<int> vec;
	string tmp;
	int n;
	for (char c : str) {
		if (c == ' ') {
			if ((tmp == "cpp") || (tmp == "backend") || (tmp == "junior") || (tmp == "chicken")) {
				n = 0;
			}
			else if (tmp == "python") {
				n = 2;
			}
			else {
				n = 1;
			}
			vec.push_back(n);
			tmp = "";
		}
		else {
			tmp += c;
		}
	}
	vec.push_back(stoi(tmp));
	return vec;
}

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> data[3][2][2][2];
	for (int i = 0; i < info.size(); i++) {
		vector<int> tmp = infoSplit(info[i]);
		data[tmp[0]][tmp[1]][tmp[2]][tmp[3]].push_back(tmp[4]);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) {
					sort(data[i][j][k][l].begin(), data[i][j][k][l].end());
				}
			}
		}
	}

	for (int q = 0; q < query.size(); q++) {
		vector<string> tmp = querySplit(query[q]);

		int lefti, righti, leftj, rightj, leftk, rightk, leftl, rightl;
		if (tmp[0] == "cpp") {
			lefti = righti = 0;
		}
		else if (tmp[0] == "java") {
			lefti = righti = 1;
		}
		else if (tmp[0] == "python") {
			lefti = righti = 2;
		}
		else {
			lefti = 0;
			righti = 2;
		}

		if (tmp[2] == "backend") {
			leftj = rightj = 0;
		}
		else if (tmp[2] == "frontend") {
			leftj = rightj = 1;
		}
		else {
			leftj = 0;
			rightj = 1;
		}

		if (tmp[4] == "junior") {
			leftk = rightk = 0;
		}
		else if (tmp[4] == "senior") {
			leftk = rightk = 1;
		}
		else {
			leftk = 0;
			rightk = 1;
		}

		if (tmp[6] == "chicken") {
			leftl = rightl = 0;
		}
		else if (tmp[6] == "pizza") {
			leftl = rightl = 1;
		}
		else {
			leftl = 0;
			rightl = 1;
		}

		int res = 0;
		int score = stoi(tmp[7]);
		for (int i = lefti; i <= righti; i++) {
			for (int j = leftj; j <= rightj; j++) {
				for (int k = leftk; k <= rightk; k++) {
					for (int l = leftl; l <= rightl; l++) {
						int n = data[i][j][k][l].size();
						if (n == 0) continue;
						auto it = lower_bound(data[i][j][k][l].begin(), data[i][j][k][l].end(), score);
						if (it == data[i][j][k][l].end()) {
							continue;
						}
						res += n - (it - data[i][j][k][l].begin());
					}
				}
			}
		}
		answer.push_back(res);
	}


	return answer;
}