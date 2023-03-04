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
typedef pair<axis, int> pai;

int n, m, k, x;
vector<int> v[300000];
int vis[300000];
vector<int> ans;

void go() {
    queue<pii> q;
    q.push({x, 0});
    vis[x] = 1;

    while (!q.empty()) {
        int t = q.front().first, cnt = q.front().second; q.pop();
        if (cnt == k) {
            ans.push_back(t);
        } else {
            for(int i : v[t]) {
                if (vis[i]) continue;
                vis[i] = 1;
                q.push({i, cnt + 1});
            }
        }

    }

}

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &x);
    x--;
    for(int a, b, i = 0; i < m; i++) {
        scanf("%d %d", &a, &b); a--; b--;
        v[a].push_back(b);
    }
    go();
    sort(ans.begin(), ans.end());
    if (ans.size() != 0) for(int i : ans) printf("%d\n", i+1);
    else printf("-1");
}