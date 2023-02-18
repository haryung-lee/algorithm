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

int n, t;
pii arr[100];
int dp[100][10001];

int go(int ix, int sm) {
    if (ix == n) {
        return 0;
    }
    if (dp[ix][sm] != -1) return dp[ix][sm];
    int ret = go(ix + 1, sm);
    if (sm + arr[ix].first <= t) ret = max(ret, go(ix + 1, sm + arr[ix].first) + arr[ix].second);

    return dp[ix][sm] = ret;
}

int main() {
    scanf("%d %d", &n, &t);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d", go(0, 0));
}