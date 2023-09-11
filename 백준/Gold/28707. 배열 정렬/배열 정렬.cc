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
typedef pair<int, string> pis;

struct info {
    int l, r, c;
};

int n, m;
string s;
vector<info> v;
unordered_map<string, int> mp;

int chk(string t) {
    for(int i = 1; i < t.size(); i++) {
        if (t[i-1] > t[i]) return 0;
    }
    return 1;
}

void go() {
    priority_queue<pis, vector<pis>, greater<pis>> pq;
    mp[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {
        pis t = pq.top(); pq.pop();
        if (mp.find(t.second) != mp.end() and mp[t.second] < t.first) continue;
        if (chk(t.second)) { // 비내림차순인지 확인
            printf("%d", t.first);
            return;
        }
        for(info i : v) {
            string newS = t.second;
            newS[i.l] = t.second[i.r];
            newS[i.r] = t.second[i.l];
            if (mp.find(newS) != mp.end() and mp[newS] <= t.first + i.c) continue;
            mp[newS] = t.first + i.c;
            pq.push({mp[newS], newS});
        }
    }

    printf("-1");
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        a--;
        s += a;
    }

    scanf("%d", &m);
    while(m--) {
        int l, r, c;
        scanf("%d %d %d", &l, &r, &c); l--; r--;
        v.push_back({l, r, c});
    }
    go();
}