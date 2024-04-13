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

string s;
stack<char> st;

int main() {
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == ')') {
            if (st.empty()) ans++;
            else st.pop();
        } else st.push(s[i]);
    }

    printf("%d", ans + st.size());
}