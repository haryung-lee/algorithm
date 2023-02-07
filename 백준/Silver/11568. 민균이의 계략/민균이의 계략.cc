#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[1001], dp[1001][1001];

int go(int ix, int pre) {
    if (ix == n + 1) {
        return 0;
    }

    if (dp[ix][pre] != -1) return dp[ix][pre];
    int ret = 0;

    if (arr[pre] < arr[ix]) {
        ret = max(go(ix + 1, ix) + 1, go(ix + 1, pre));
    } else {
        ret = max(ret, go(ix + 1, pre));
    }

    return dp[ix][pre] = ret;
}

int main() {
    scanf("%d", &n);
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    printf("%d", go(1, 0));
}