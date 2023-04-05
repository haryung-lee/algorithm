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

// 4MB
int n;
int arr[100001][3]; // 4 * 300000
int dp[2][3];

int main() {
    pii ans = {0, 1e9};
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // max
    for(int i = 1; i <= n; i++) {
        dp[1][0] = max(dp[0][0], dp[0][1]) + arr[i][0];
        dp[1][1] = max(max(dp[0][0], dp[0][1]), dp[0][2]) + arr[i][1];
        dp[1][2] = max(dp[0][1], dp[0][2]) + arr[i][2];

        dp[0][0] = dp[1][0];
        dp[0][1] = dp[1][1];
        dp[0][2] = dp[1][2];
    }

    for(int i = 0; i < 3; i++) {
        ans.first = max(ans.first, dp[1][i]);
    }

    memset(dp, 0x3f, sizeof(dp));

    for(int i = 0; i < 3; i++) dp[0][i] = 0;
    // min
    for(int i = 1; i <= n; i++) {
        dp[1][0] = min(dp[0][0], dp[0][1]) + arr[i][0];
        dp[1][1] = min(min(dp[0][0], dp[0][1]), dp[0][2]) + arr[i][1];
        dp[1][2] = min(dp[0][1], dp[0][2]) + arr[i][2];

        dp[0][0] = dp[1][0];
        dp[0][1] = dp[1][1];
        dp[0][2] = dp[1][2];
    }

    for(int i = 0; i < 3; i++) {
        ans.second = min(ans.second, dp[1][i]);
    }
    printf("%d %d", ans.first, ans.second);
}