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
map<int, int> mp;

int main() {
    cin >> s >> t;

    int ans = 0;

    for(int i = 0; i < t.size() - 1; i++) {
        mp[t[i]] = 0;
    }

    for(int i = 0; i < s.size(); i++) {
        if (mp.find(s[i]) == mp.end() and s[i] != t[t.size() - 1]) continue;

        if (s[i] == t[t.size() - 1]) {
            // 마지막 값이라면, 이전 값들에 대해 계산.
            // 모든 문자열이 다 있는지 체크
            int chk = 1;
            for(pii j : mp) {
                if (!j.second and j.first != t[t.size() - 1]) chk = 0;
            }
            // 다 있다면,
            if (chk) {
                ans++;
                int flag = 0;
                for(int j = 0; j < t.size() - 1; j++) {
                    if (flag) mp[t[j]] = 0;
                    else {
                        mp[t[j]]--;
                        if (!mp[t[j]]) flag = 1;
                    }

                }
            } else {
                int j = 0;
                for(; j < t.size() - 1; j++) {
                    if (!mp[t[j]]) break;
                }
                for(; j < t.size() - 1; j++) {
                    mp[t[j]] = 0;
                }
            }
        } else {
            mp[s[i]]++;
            int mn = 1e9;
            for(int j = 0; j < t.size() - 1; j++) {
                if (t[j] == s[i]) break;
                mn = min(mn, mp[t[j]]);
            }
            mp[s[i]] = min(mp[s[i]], mn);
        }
    }


    printf("%d", ans);
}