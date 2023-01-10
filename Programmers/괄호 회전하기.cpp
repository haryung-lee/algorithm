#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int chkPair(char a, char b) {
    if (a == '(') return b == ')';
    if (a == '{') return b == '}';
    if (a == '[') return b == ']';
}

string moveLeft(string s) {
    string tmp = "";
    for(int i = 0; i < s.size(); i++) {
        tmp += s[(i+1) % s.size()];
    }
    return tmp;
}

int solution(string s) {
    int answer = 0;

    for(int i = 0; i < s.size(); i++) {
        int chk = 1;
        stack<char> st;

        for(int j = 0; j < s.size(); j++) {
            if (s[j] == '(' or s[j] == '[' or s[j] == '{') st.push(s[j]);
            else {
                if (st.empty()) chk = 0;
                else {
                    char tmp = st.top(); st.pop();
                    if (!chkPair(tmp, s[j])) chk = 0;
                }
            }
        }
        if (!st.empty()) chk = 0;
        s = moveLeft(s);
        answer += chk;
    }
    return answer;
}