#include <string>
#include <vector>

using namespace std;
vector<int> answer;

string toBinary(int n) {
	string r;
	while (n != 0) {
		r += (n % 2 == 0 ? "0" : "1");
		n /= 2;
	}
	return r;
}

vector<int> solution(string s) {
	int zero_cnt = 0;
	int repeat = 0;
	while (s != "1") {
		string newS = "";
		for (int i = 0; i < s.length(); i++) {
			if (s.substr(i, 1) == "1") {
				newS += "1";
			}
			else if (s.substr(i, 1) == "0") {
				zero_cnt++;
			}
		}
		s = newS;
		int c = s.length();
		s = toBinary(c);
		repeat++;
	};

	answer.push_back(repeat);
	answer.push_back(zero_cnt);

	return answer;
}