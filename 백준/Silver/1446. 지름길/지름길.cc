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

int n, d;
vector<pii> v[10001];
int dis[10001];

int main() {
    scanf("%d %d", &n, &d);
    for(int i = 0; i < n; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({b, c});
    }
    for(int i = 0; i <= d; i++) dis[i] = 1e9;
    dis[0] = 0;

    for(int i = 0; i <= d; i++) {
        dis[i] = min(dis[i-1]+1, dis[i]);

        for(pii t : v[i]) {
            if (dis[t.first] < dis[i] + t.second) continue;
            dis[t.first] = dis[i] + t.second;
        }
    }
    printf("%d", dis[d]);
}