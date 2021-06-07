#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;
int answer = 0;

int solution(string str1, string str2) {
	vector<string> str_vec1;
	vector<string> str_vec2;
	for (int i = 0; i < (str1.length() - 1); i++) {
		string tmp = "";
		if ((int(str1[i]) >= 65) && (int(str1[i]) <= 90)) {
			tmp += str1[i];
		}
		else if ((int(str1[i]) >= 97) && (int(str1[i]) <= 122)) {
			tmp += (char)(int(str1[i]) - 32);
		}
		else continue;
		if ((int(str1[i + 1]) >= 65) && (int(str1[i + 1]) <= 90)) {
			tmp += str1[i + 1];
		}
		else if ((int(str1[i + 1]) >= 97) && (int(str1[i + 1]) <= 122)) {
			tmp += (char)(int(str1[i + 1]) - 32);
		}
		else continue;
		str_vec1.push_back(tmp);
	}
	for (int i = 0; i < (str2.length() - 1); i++) {
		string tmp = "";
		if ((int(str2[i]) >= 65) && (int(str2[i]) <= 90)) {
			tmp += str2[i];
		}
		else if ((int(str2[i]) >= 97) && (int(str2[i]) <= 122)) {
			tmp += (char)(int(str2[i]) - 32);
		}
		else continue;
		if ((int(str2[i + 1]) >= 65) && (int(str2[i + 1]) <= 90)) {
			tmp += str2[i + 1];
		}
		else if ((int(str2[i + 1]) >= 97) && (int(str2[i + 1]) <= 122)) {
			tmp += (char)(int(str2[i + 1]) - 32);
		}
		else continue;
		str_vec2.push_back(tmp);
	}
	if ((str_vec1.size() == 0) && (str_vec2.size() == 0)) {
		answer = 65536;
	}
	else {
		sort(str_vec1.begin(), str_vec1.end());
		sort(str_vec2.begin(), str_vec2.end());
		// 교집합
		vector<string> intersect_vec;
		int arr[1000] = { 0, };
		for (int i = 0; i < str_vec1.size(); i++) {
			for (int j = 0; j < str_vec2.size(); j++) {
				if ((str_vec1[i] == str_vec2[j]) && (arr[j] == 0)) {
					intersect_vec.push_back(str_vec1[i]);
					arr[j] = 1;
					break;
				}
			}
		}
		// 합집합
		int diff_str1 = str_vec1.size() - intersect_vec.size();
		int diff_str2 = str_vec2.size() - intersect_vec.size();
		int union_set = str_vec1.size() + str_vec2.size() - intersect_vec.size();

		double jacquard = (double)(intersect_vec.size()) / (double)(union_set);
		answer = jacquard * 65536;
	}

	return answer;
}