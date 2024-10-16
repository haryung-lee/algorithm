#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') answer += ' ';
        else if (s[i] >= 'A' and s[i] <= 'Z') answer += char((int(s[i]) - int('A') + n) % (int('Z') - int('A') + 1) + int('A'));
        else answer += char((int(s[i]) - int('a') + n) % (int('z') - int('a') + 1) + int('a'));
    }
    return answer;
}