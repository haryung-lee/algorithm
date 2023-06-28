#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef long long ll;
int dy[] = {0, 1, 0, -1}, dx[] = {-1, 0, 1, 0};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;


string sol(string s) {
    string ret = "";
    stack<char> st;
    int n = 0;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            if (st.size() < 2) st.push(s[i]);
            else if (st.top() == '1') {
                st.pop();
                if (st.top() == '1') {// 11이 연속으로 있다면
                    st.pop();
                    n++;
                }
                else { // 아니라면 원상복구
                    st.push('1');
                    st.push('0');
                }
            } else st.push('0');
        } else st.push('1');
    }

//    printf(":: %d\n", n);
    while(!st.empty()) {
        char t = st.top(); st.pop();
//        cout << t;
        if (t == '0' and n) {
            for(int i = 0; i < n; i++) ret += "011";
            ret += t;
            n = 0;
        } else ret += t;
    }
    if (n) for(int i = 0; i < n; i++) ret += "011";
//    printf("\n============\n");
    reverse(ret.begin(), ret.end());
    return ret;
}

vector<string> solution(vector<string> s) {
    vector<string> ans;

    for(string t : s) {
        ans.push_back(sol(t));
    }
    return ans;
}
