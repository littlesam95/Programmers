#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

bool isRight(char c, int diff, int num) {
	if (c == '=') {
		return diff == num;
	}
	else if (c == '<') {
		return diff < num;
	}
	else if (c == '>') {
		return diff > num;
	}
}

int solution(int n, vector<string> data) {
	int answer = 0;
	string friends = "ACFJMNRT";

	do {
		bool b = true;
		for (string w : data) {
			char bf = w[0]; // ù ��° ������
			char nf = w[2]; // �� ��° ������
			char comp = w[3]; // ��ȣ/�ε�ȣ
			int num = w[4] - '0'; // ����
			int diff = friends.find(bf) - friends.find(nf); // ���� �������� ù ��°�� �� ��° �������� ��ġ ����
			int dis = abs(diff) - 1; // �Ÿ�
			if (isRight(comp, dis, num)) continue; // ������ �����ϴ��� Ȯ��, �����ϸ� ���� ������� Ȯ��
			b = false; // �������� �ʴ´ٸ� break �� ���� ������ ������.
			break;
		}
		if (b) answer++; // ���������� �� ������ ��� ������ �����ϸ� �������� �ϳ� �ø���.
	} while (next_permutation(friends.begin(), friends.end())); // ������ ��� �����鼭 ������ �����ϴ� �� Ȯ���Ѵ�.

	return answer;
}