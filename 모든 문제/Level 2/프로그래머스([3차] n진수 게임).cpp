#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string answer = "";

string change(int number, int n) {
	string res = "";
	if (number > 0) {
		while (number > 0) {
			if (number % n == 10) {
				res += "A";
			}
			else if (number % n == 11) {
				res += "B";
			}
			else if (number % n == 12) {
				res += "C";
			}
			else if (number % n == 13) {
				res += "D";
			}
			else if (number % n == 14) {
				res += "E";
			}
			else if (number % n == 15) {
				res += "F";
			}
			else {
				res += to_string(number % n);
			}
			number /= n;
		};
	}
	else if (number == 0) {
		res += "0";
	}
	reverse(res.begin(), res.end());
	return res;
}

string solution(int n, int t, int m, int p) {
	int number = -1; // change(number, n)이 빈 문자열이 되면 number는 증가
	int number_idx = 0; // 현재 말해야 할 숫자
	int person = 1; // 현재 말해야 할 사람 차례. person == p면 튜브가 말함
	int idx = 0; // 튜브가 말한 횟수, idx가 t가 되는 순간 반복문 종료
	string str = "";
	while (1) {
		if ((number_idx == str.size()) || (str == "")) {
			number++;
			number_idx = 0;
			str = change(number, n);
		}
		if (person == p) {
			answer += str.substr(number_idx, 1);
			idx++;
			if (idx == t) {
				break;
			}
		}
		number_idx++;
		person++;
		if (person > m) { // 한 바퀴 다 돌면 다시 처음 사람 차례가 된다.
			person = 1;
		}
	};

	return answer;
}