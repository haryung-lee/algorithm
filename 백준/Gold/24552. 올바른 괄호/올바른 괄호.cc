#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
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
typedef pair<char, int> pci;

stack<int> st;
string s;
int ls = 0, rs = 0;

int main() {
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '(') ls++;
        else rs++;
    }

    if (ls < rs) { // ) 가 더 많으면 s 뒤집기
        string tmp = "";
        for(int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') tmp += ')';
            else tmp += '(';
        }
        s = tmp;
    }

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') st.push(i);
        else st.pop();
    }

    int t = st.top(), ans = 0;
    for(int i = t; i < s.size(); i++) {
        if (s[i] == '(') ans++;
    }
    printf("%d", ans);

}