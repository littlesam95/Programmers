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
	int number = -1; // change(number, n)�� �� ���ڿ��� �Ǹ� number�� ����
	int number_idx = 0; // ���� ���ؾ� �� ����
	int person = 1; // ���� ���ؾ� �� ��� ����. person == p�� Ʃ�갡 ����
	int idx = 0; // Ʃ�갡 ���� Ƚ��, idx�� t�� �Ǵ� ���� �ݺ��� ����
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
		if (person > m) { // �� ���� �� ���� �ٽ� ó�� ��� ���ʰ� �ȴ�.
			person = 1;
		}
	};

	return answer;
}