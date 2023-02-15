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

int n, m;
int dp[30][10];

int go(int cnt, int ix) {
    if (cnt == m) return 1;

    if (dp[cnt][ix] != -1) return dp[cnt][ix];
    int ret = 0;
    for(int i = ix; i < n; i++) {
        ret += go(cnt + 1, i);
    }

    return dp[cnt][ix] = ret;
}

int main() {
    scanf("%d %d", &n, &m); m -= n;
    memset(dp, -1, sizeof(dp));
    printf("%d", go(0, 0));
}