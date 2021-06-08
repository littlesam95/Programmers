#include <string>
#include <vector>

using namespace std;
string answer = "";

string solution(string phone_number) {
    for (int i = 0; i < phone_number.length() - 4; i++) {
        answer += "*";
    }
    for (int i = phone_number.length() - 4; i < phone_number.length(); i++) {
        answer += phone_number.substr(i, 1);
    }
    return answer;
}