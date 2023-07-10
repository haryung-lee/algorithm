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
typedef tuple<int, int, int> tup;

int tc, n, m;

void go() {
    scanf("%d %d", &n, &m);
    vector<pii> v[400];
    for(int j = 0; j < m; j++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c); a--; b--;
        v[a].push_back({b, c});
    }
    priority_queue<tup, vector<tup>, greater<tup>> pq;
    int dis[400][400];
    memset(dis, 0x3f, sizeof(dis));

    for(int i = 0; i < n; i++) {
        for(pii j : v[i]) {
            pq.push({j.second, i, j.first});
        }
    }

    while(!pq.empty()) {
        tup t = pq.top(); pq.pop();
        int d = get<0>(t), start = get<1>(t), cur = get<2>(t);
        if (dis[start][cur] < 1e9) continue; // 이미 방문한 곳이라면 패스. dij에서는 먼저 방문한게 최소거리
        dis[start][cur] = d;
        if (start == cur) {
            printf("%d\n", d);
            return;
        }
        for(auto [nx, cost] : v[cur]) {
            pq.push({d + cost, start, nx});
        }
    }
    printf("-1\n");
}

int main() {
    scanf("%d", &tc);
    for(int i = 1; i <= tc; i++) {
        printf("#%d ", i);
        go();
    }
    return 0;
}