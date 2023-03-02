#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef long long ll;
int dy[] = {0, 1, 0, -1}, dx[] = {-1, 0, 1, 0};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;

// +, -, *
string op[] = {"+", "-", "*"};
vector<string> v; // expression
vector<string> pr; // 연산자 우선순위
int vis[3];
ll answer = 0;

string cal(string a, string b, string oper) {
    if (oper == "+") return to_string(stoll(a) + stoll(b));
    if (oper == "-") return to_string(stoll(a) - stoll(b));
    return to_string(stoll(a) * stoll(b));
}

void go(string op) { // v에서 op연산 하기
    deque<string> st;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == op) {
            if (i+1 < v.size()) {
//                cout << "계산 해요 : " << st.back() << ", " << v[i+1] << ": " << cal(st.back(), v[i+1], v[i])<< endl;
                string b = st.back(); st.pop_back();
                st.push_back(cal(b, v[i+1], v[i]));
                i++;
            }
        } else {
            st.push_back(v[i]);
        }
    }
    v.clear();
    for(int i = 0; i < st.size(); i++) v.push_back(st[i]);

//    printf("결과\n");
//    for(string s : v) cout << s << ", ";
//    printf("\n===============\n");
}


void go2(vector<string> vv) {
    if (pr.size() == 3) {
       for(int i = 0; i < pr.size(); i++) {
           go(pr[i]);
       }
       answer = max(answer, abs(stoll(v.back())));
        v = vv;
    } else {
        for(int i = 0; i < 3; i++) {
            if (vis[i]) continue;
            vis[i] = 1;
            pr.push_back(op[i]);
            go2(vv);
            vis[i] = 0;
            pr.pop_back();
        }
    }
}

long long solution(string expression) {
    vector<string> ex;
    string tmp = "";
    for(int i = 0; i < expression.size(); i++) {
        if (expression[i] == '+' or expression[i] == '-' or expression[i] == '*') {
            ex.push_back(tmp);
            tmp = ""; tmp += expression[i];
            ex.push_back(tmp);
            tmp = "";
        } else {
            tmp += expression[i];
        }
    }
    ex.push_back(tmp);
    v = ex;
    go2(ex);
    return answer;
}
