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

ll dp[1<<4][10001];
int tc;
string s;

ll go(int st, int ix) { // ix에 있으면서 st인 상태
    if (ix == (s.size() - 1)) {
        return 1;
    }
    if (dp[st][ix] != -1) return dp[st][ix];
    ll ret = 0;

    for(int i = 1; i < 16; i++) {
        if ((i & (1 << int(s[ix+1] - 'A'))) and (i & st)) {
            ret += go(i, ix + 1) % MOD;
        }
    }
    return dp[st][ix] = ret % MOD;
}

int main() {
    scanf("%d", &tc);

    for(int i = 1; i <= tc; i++) {
        printf("#%d ", i);
        cin >> s;
        s = '0' + s;
        memset(dp, -1, sizeof(dp));
        printf("%lld\n", go(1, 0));
    }
}