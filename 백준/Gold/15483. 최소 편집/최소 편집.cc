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

int dp[2001][2001];
string a, b;

int go(int ix1, int ix2) {
    if (ix2 == b.size()) {
        if (ix1 != a.size()) {
            if (ix1 > a.size()) return ix1 - a.size();
            return a.size() - ix1;
        }
        return 0;
    }
    if (dp[ix1][ix2] != -1) return dp[ix1][ix2];

    int ret = 1e9;

    if (a[ix1] == b[ix2]) ret = min(go(ix1 + 1, ix2 + 1), ret);
    else {
        ret = min(ret, go(ix1, ix2+1) + 1);
        ret = min(ret, go(ix1 + 1, ix2) + 1);
        ret = min(ret, go(ix1 + 1, ix2 + 1) + 1);
    }

    return dp[ix1][ix2] = ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> a >> b;

    printf("%d", go(0, 0));
}