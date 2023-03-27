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

int n;
int arr[1001];
int dp[1001][10000];

int go(int ix, int total) {
    if (ix == n+1 or total >= n) {
        if (total != n) return -1e9;
        return 0;
    }

    if (dp[ix][total] != -1) return dp[ix][total];
    int ret = -1e9;
    for(int i = 0; total + i*ix <= n; i++) {
        ret = max(ret, go(ix + 1, total + i*ix) + arr[ix] * i);
    }

    return dp[ix][total] = ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for(int i = 1;i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d", go(1, 0));

}