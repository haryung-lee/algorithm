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
string s[1001];
int dp[1001][1001];
int ans = 0;

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (i == 0 or j == 0) {
                dp[i][j] = s[i][j] - '0';
                continue;
            }
            if (s[i][j] == '0') dp[i][j] = 0;
            else if (s[i-1][j-1] == '1' and s[i-1][j] == '1' and s[i][j-1] == '1') dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
            else dp[i][j] = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    printf("%d", ans * ans);
}