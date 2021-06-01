#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

long long gcd(int a, int b) {
	int mod = a % b;
	while (mod > 0) {
		a = b;
		b = mod;
		mod = a % b;
	};
	return b;
}

long long solution(int w, int h) {
	long long newW = w;
	long long newH = h;
	int num = w + h - gcd(w, h);
	long long mul = newW * newH;
	long long answer = mul - num;
	return answer;
}