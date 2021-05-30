#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
vector<string> answer;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> arrStr1;
	vector<string> arrStr2;
	for (int i = 0; i < n; i++) {
		int k = pow(2, 15);
		string str1 = "";
		string str2 = "";
		while (k > 0) {
			int tmp1 = arr1[i] / k;
			int tmp2 = arr2[i] / k;
			str1 += to_string(tmp1);
			str2 += to_string(tmp2);
			arr1[i] -= (k * tmp1);
			arr2[i] -= (k * tmp2);
			k /= 2;
		};

		string strTmp = "";
		int len1 = str1.length();
		for (int i = len1 - n; i < len1; i++) {
			strTmp += str1.substr(i, 1);
		}
		str1 = strTmp;

		strTmp = "";
		int len2 = str2.length();
		for (int i = len2 - n; i < len2; i++) {
			strTmp += str2.substr(i, 1);
		}
		str2 = strTmp;
		arrStr1.push_back(str1);
		arrStr2.push_back(str2);
	}

	for (int i = 0; i < n; i++) {
		string tmp = "";
		for (int j = 0; j < n; j++) {
			if ((arrStr1[i].substr(j, 1) == "0") && (arrStr2[i].substr(j, 1) == "0")) {
				tmp += " ";
			}
			else {
				tmp += "#";
			}
		}
		answer.push_back(tmp);
	}

	return answer;
}