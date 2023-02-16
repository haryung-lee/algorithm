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
int dy[] = {1, 0}, dx[] = {0, 1};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;

int n, m, t;
int dp[16][16][2];

int go(int a, int b, int isTarget) {
    if (a == n and b == m) {
        if (isTarget == 0) return 1;
        return 0;
    }

    int ret = 0;
    for(int i = 0; i < 2; i++) {
        int x = dx[i] + a, y = dy[i] + b;
        if (x > n or y > m) continue;
        ret += go(x, y, (t == (m*(x-1)+y)) ? isTarget - 1 : isTarget);
    }
    return dp[a][b][isTarget] = ret;
}

int main() {
    scanf("%d %d %d", &n, &m, &t);
    printf("%d", go(1, 1, t ? 1 : 0));

}