#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string answer = "";

string solution(string s, int n) {
	for (int i = 0; i < s.size(); i++) {
		if ((s[i] >= 65) && (s[i] <= 90)) {
			if (int(s[i]) + n > 90) {
				s[i] += (n - 26);
			}
			else {
				s[i] += n;
			}
		}
		else if ((s[i] >= 97) && (s[i] <= 122)) {
			if (int(s[i]) + n > 122) {
				s[i] += (n - 26);
			}
			else {
				s[i] += n;
			}
		}
	}
	answer = s;
	return answer;
}