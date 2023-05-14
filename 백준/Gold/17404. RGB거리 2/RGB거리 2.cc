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
struct color {int r, g, b;};
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;

int n;
color arr[1000];
int dp[1000][3][3];

int go(int ix, int pre, int st) {
    if (ix == n-1) {
        if ((st == 0 && pre == 1) or (st == 1 && pre == 0)) return arr[ix].b;
        if ((st == 0 && pre == 2) or (st == 2 && pre == 0)) return arr[ix].g;
        if ((st == 1 && pre == 2) or (st == 2 && pre == 1)) return arr[ix].r;
        if (st == 0 && pre == st) return min(arr[ix].g, arr[ix].b);
        if (st == 1 && pre == st) return min(arr[ix].r, arr[ix].b);
        if (st == 2 && pre == st) return min(arr[ix].r, arr[ix].g);
        return 1e9;
    }
    if (pre != -1 and dp[ix][pre][st] != -1) return dp[ix][pre][st];

    int ret;
    if (pre == -1) {
      ret = min(go(ix + 1, 1, 1) + arr[ix].g, go(ix + 1, 2, 2) + arr[ix].b);
      ret = min(ret, go(ix + 1, 0, 0) + arr[ix].r);
    } else if (pre == 0) { // red
        ret = min(go(ix + 1, 1, st)+ arr[ix].g, go(ix + 1, 2, st) + arr[ix].b);
    } else if (pre == 1) { // green
        ret = min(go(ix + 1, 0, st) + arr[ix].r, go(ix + 1, 2, st) + arr[ix].b);
    } else { // blue
        ret = min(go(ix + 1, 0, st) + arr[ix].r, go(ix + 1, 1, st)+ arr[ix].g);
    }

    return dp[ix][pre][st] = ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &arr[i].r, &arr[i].g, &arr[i].b);
    }
    printf("%d", go(0, -1, 0));
}