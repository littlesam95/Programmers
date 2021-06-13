#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> answer;
int zero_cnt = 0;
int one_cnt = 0;

void quad(vector<vector<int>> arr) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if ((i == 0) && (j == 0)) {
				vector<vector<int>> new_arr;
				int block = arr[0][0];
				bool check = true;
				for (int k = 0; k < (arr.size() / 2); k++) {
					vector<int> tmp;
					for (int l = 0; l < (arr[0].size() / 2); l++) {
						tmp.push_back(arr[k][l]);
						if (block != arr[k][l]) {
							check = false;
						}
					}
					new_arr.push_back(tmp);
				}
				if (check) {
					if (block == 0) {
						zero_cnt++;
					}
					else if (block == 1) {
						one_cnt++;
					}
				}
				else {
					quad(new_arr);
				}
			}
			else if ((i == 0) && (j == 1)) {
				vector<vector<int>> new_arr;
				int block = arr[0][(arr[0].size() / 2)];
				bool check = true;
				for (int k = 0; k < (arr.size() / 2); k++) {
					vector<int> tmp;
					for (int l = (arr[0].size() / 2); l < arr[0].size(); l++) {
						tmp.push_back(arr[k][l]);
						if (block != arr[k][l]) {
							check = false;
						}
					}
					new_arr.push_back(tmp);
				}
				if (check) {
					if (block == 0) {
						zero_cnt++;
					}
					else if (block == 1) {
						one_cnt++;
					}
				}
				else {
					quad(new_arr);
				}
			}
			else if ((i == 1) && (j == 0)) {
				vector<vector<int>> new_arr;
				int block = arr[(arr.size() / 2)][0];
				bool check = true;
				for (int k = (arr.size() / 2); k < arr.size(); k++) {
					vector<int> tmp;
					for (int l = 0; l < (arr[0].size() / 2); l++) {
						tmp.push_back(arr[k][l]);
						if (block != arr[k][l]) {
							check = false;
						}
					}
					new_arr.push_back(tmp);
				}
				if (check) {
					if (block == 0) {
						zero_cnt++;
					}
					else if (block == 1) {
						one_cnt++;
					}
				}
				else {
					quad(new_arr);
				}
			}
			else if ((i == 1) && (j == 1)) {
				vector<vector<int>> new_arr;
				int block = arr[(arr.size() / 2)][(arr[0].size() / 2)];
				bool check = true;
				for (int k = (arr.size() / 2); k < arr.size(); k++) {
					vector<int> tmp;
					for (int l = (arr[0].size() / 2); l < arr[0].size(); l++) {
						tmp.push_back(arr[k][l]);
						if (block != arr[k][l]) {
							check = false;
						}
					}
					new_arr.push_back(tmp);
				}
				if (check) {
					if (block == 0) {
						zero_cnt++;
					}
					else if (block == 1) {
						one_cnt++;
					}
				}
				else {
					quad(new_arr);
				}
			}
		}
	}
}

vector<int> solution(vector<vector<int>> arr) {
	int block = arr[0][0];
	bool check = true;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			if (block != arr[i][j]) {
				check = false;
				break;
			}
		}
	}
	if (check) {
		if (block == 0) {
			zero_cnt++;
		}
		else if (block == 1) {
			one_cnt++;
		}
	}
	else {
		quad(arr);
	}
	answer.push_back(zero_cnt);
	answer.push_back(one_cnt);
	return answer;
}