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
#define MOD 1000000007

int tc;
int n;
ll dp[1000001][2];

ll go(int ix, int st) {
    if (ix == 0) {
        return 1;
    };
    if (dp[ix][st] != -1) return dp[ix][st];
    ll ret = 0;

    if (st == 0) {
        ret = (go(ix - 1, 0) * 2) % MOD + (go(ix - 1, 1)) % MOD;
    } else {
        ret = (go(ix - 1, 0) * 4) % MOD + (go(ix - 1, 1) * 3) % MOD;
    }


    return dp[ix][st] = ret % MOD;
}

int main() {
    memset(dp, -1, sizeof(dp));

    scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &n);
        printf("%lld\n", go(n, 1));
    }
}