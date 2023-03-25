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
#include <set>
#define MOD 100000007
#define INF 987654321
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<pii, pii> piiii;
typedef pair<tuple<int, int, int>, int> ptii;
typedef pair<string, int> psi;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
struct axis{int x, y;};
typedef pair<axis, int> pai;

int n, a, b, vis[51], ans[51], mn = 51, cnt;
vector<int> v[51];
queue<pii> q;
int BFS(int idx) {
    int ret;
    q.push({idx, 0});
    vis[idx] = 1;
    while (!q.empty()) {
        pii t = q.front();
        q.pop();
        ret = t.second;
        for(int i : v[t.first]) {
            if (vis[i]) continue;
            q.push({i, t.second + 1});
            vis[i] = 1;
        }
    }
    return ret;
}


int main() {
    scanf("%d", &n);

    while (1) {
        scanf("%d %d", &a, &b);
        if (a == -1) break;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        memset(vis, 0, sizeof(vis));
        ans[i] = BFS(i);
        mn = min(ans[i], mn);
    }
    for(int i = 0; i < n; i++)
        if (mn == ans[i]) cnt++;
    printf("%d %d\n", mn, cnt);
    for(int i = 0; i < n; i++) {
        if (ans[i] == mn)
            printf("%d ", i + 1);
    }
}