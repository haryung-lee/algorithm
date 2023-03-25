#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#define MOD 10007
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;

int n, m, vis[101], ans = 10000000, tmp, tans, ansi = 0;
vector<int> v[101];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 0; i < n; i++) {
        memset(vis, 0, sizeof(vis));
        vis[i] = 1; tans = 0;
        queue<pii> q;
        q.push({i, 1});
        while (!q.empty()) {
            pii t = q.front();
            q.pop();
            for(int j : v[t.first]) {
                if (vis[j]) continue;
                q.push({j, t.second + 1});
                vis[j] = 1;
                tans += t.second;
            }
        }
        if (tans < ans) {
            ansi = i;
            ans = tans;
        }
    }
    printf("%d", ansi + 1);
}