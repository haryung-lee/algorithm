#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
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

string s, t;
int dir = 0; // ri가 0, le가 1
int le, ri, ans = 0;

void go() {
    if (s.size() == (ri - le + 1)) {
        int flag = 1;
        if (dir) {
            for(int i = 0; i < s.size(); i++) {
                if (s[i] != t[ri - i]) flag = 0;
            }
        } else {
            for(int i = 0; i < s.size(); i++) {
                if (s[i] != t[le + i]) flag = 0;
            }
        }
        if (flag) ans = 1;
        return;
    }
    if (dir == 0) {
        if (t[le] == 'B') { // 방향을 바꿔야 함
            dir = !dir;
            le++;
            go();
            le--;
            dir = !dir;
        }
        if (t[ri] == 'A') { // 방향 그대로
            ri--;
            go();
            ri++;
        }
    } else {
        if (t[ri] == 'B') {
            ri--;
            dir = !dir;
            go();
            ri++;
            dir = !dir;
        }
        if (t[le] == 'A') {
            le++;
            go();
            le--;
        }
    }
}

int main() {
    cin >> s >> t;
    le = 0, ri = t.size() - 1;
    go();
    printf("%d", ans);
}