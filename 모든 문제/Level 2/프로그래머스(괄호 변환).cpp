#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 이해안돼서 다른사람꺼보고함
bool check(string p) {
	int t{};
	for (size_t i = 0; i < p.size(); i++) {
		if (p[i] == '(') {
			t++;
		}
		else {
			if (!t) {
				return false;
			}
			t--;
		}
	}

	return true;
}

string recursion(string p) {
	if (p == "") {
		return p;
	}
	string u{}, v{};
	int count_l{}, count_r{};
	for (size_t i = 0; i < p.size(); i++) {
		if (p[i] == '(') {
			count_l++;
		}
		else {
			count_r++;
		}
		if (count_l == count_r) {
			u = p.substr(0, i + 1);
			v = p.substr(i + 1);
			break;
		}
	}

	if (check(u)) {
		return u + recursion(v);
	}
	else {
		string tmp = { "(" };
		tmp += recursion(v) + ")";
		u = u.substr(1, u.size() - 2);
		for (size_t i = 0; i < u.size(); i++) {
			if (u[i] == '(') {
				tmp += ")";
			}
			else {
				tmp += "(";
			}
		}
		return tmp;
	}
}

string solution(string p) {
	if (check(p)) return p;
	return recursion(p);
}