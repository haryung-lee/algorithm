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
int dy[] = {0, 1, 1, -1, 0}, dx[] = {1, 0, 1, 0, -1};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;

int n;
int arr[32][32];
ll dp[32][32][3];

bool chk(int x, int y) {
    for(int j = 3; j < 5; j++) {
        int xx = x + dx[j], yy = y + dy[j];
        if (arr[xx][yy]) return true;
    }
    return false;
}

ll go(axis ix, int type) { // 0: 아래, 1: 오, 2: 대각선
    if (ix.x == n-1 and ix.y == n-1) return 1;

    if (dp[ix.x][ix.y][type] != -1 ) return dp[ix.x][ix.y][type];
    ll ret = 0;

    for(int i = 0; i < 3; i++) { // 아래 - 오 - 대각선
        if (i == 0 and type == 1) continue;
        if (i == 1 and type == 0) continue;
        int x = ix.x + dx[i], y = ix.y + dy[i];
        if (x >= n or y >= n or arr[x][y]) continue;
        if (i == 2) {
            if (chk(x, y)) continue;
        }
        ret += go({x, y}, i);
    }

    return dp[ix.x][ix.y][type] = ret;
}

int main() {
    scanf("%d", &n);
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("%lld", go({0, 1}, 1));
}