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
int mod; // -1: 정방향, 1: 역방향
int st, en;

int main() {
    cin >> s >> t;

    st = 0;
    en = t.size() - 1;
    mod = -1;

    while(en - st + 1 != s.size()) {
        if (mod == -1) { // 정방향
            if (t[en] == 'B') {
             mod = 1;
            }
            en--;
        } else { // 역방향
            if (t[st] == 'B') {
                mod = -1;
            }
            st++;
        }
    }
    string tmp = t.substr(st, s.size());
    if (mod == 1) { // 역방향
        reverse(tmp.begin(), tmp.end());
    }
    
    if (tmp == s) printf("1");
    else printf("0");
}