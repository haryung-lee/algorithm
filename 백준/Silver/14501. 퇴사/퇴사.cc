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
pii arr[15];
int dp[15*5];

int go(int ix) {
    if (ix >= n) {
        if (ix == n) return 0;
        return -1e9;
    }
    int ret = 0;

    // 현재 ix.. 할 수 있는건 먹느냐 안먹느냐.
    ret = max(go(ix + arr[ix].first) + arr[ix].second, go(ix + 1));

    return dp[ix] = ret;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        arr[i] = {a, b};
    }
    printf("%d", go(0));
}