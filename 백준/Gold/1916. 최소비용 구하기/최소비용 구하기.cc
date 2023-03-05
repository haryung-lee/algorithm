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
#define MOD 1234567
#define INF 987654321
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef pair<char, int> pci;
typedef pair<pii, int> piii;
typedef pair<pii, pii> piiii;
typedef pair<tuple<int, int, int>, int> ptii;
typedef pair<string, int> psi;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
struct axis{int x, y;};
struct togo{int s, e;};
typedef pair<axis, int> pai;

int n, m, dis[1001];
vector<pii> v[1001];
togo ix;

void dij(int o) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, o});
    dis[o] = 0;

    while (!pq.empty()) {
        pii t = pq.top();
        pq.pop();

        if (dis[t.second] < t.first) continue;

        for (auto i : v[t.second]) {
            if (dis[i.second] <= dis[t.second] + i.first) continue;
            dis[i.second] = dis[t.second] + i.first;
            pq.push({i.first, i.second});
        }
    }
}

int main() {
    memset(dis, 0x3f, sizeof(dis));

    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--; b--;
        v[a].push_back({c, b});
    }
    scanf("%d %d", &ix.s, &ix.e);
    ix.s--; ix.e--;
    dij(ix.s);
    printf("%d", dis[ix.e]);
}