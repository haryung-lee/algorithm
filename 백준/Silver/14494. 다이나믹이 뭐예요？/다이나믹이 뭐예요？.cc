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
#define MOD 1000000007
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef long long ll;
int dy[] = {0, 1, 0, -1}, dx[] = {-1, 0, 1, 0};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;

int n, m;
int dp[1001][1001];

int go(int tn, int tm) {
    if (tn == n or tm == m) {
        if (tn == n and tm == m) return 1;
        return 0;
    }
    if (dp[tn][tm] != -1) return dp[tn][tm];

    int ret = 0;
    if (tn < n and tm < m) ret = (go(tn + 1, tm) % MOD + go(tn, tm + 1) % MOD) % MOD + go(tn+1, tm+1);
    else if (tn < n) ret = go(tn + 1, tm);
    else if (tm < m) ret = go(tn, tm + 1);

    return dp[tn][tm] = ret % MOD;
}

int main() {
    memset(dp, -1, sizeof(dp));

    scanf("%d %d", &n, &m);
    printf("%d", go(0, 0));
}