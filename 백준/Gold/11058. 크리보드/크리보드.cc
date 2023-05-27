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
ll dp[101];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i-1] + 1;
        for(int j = i - 3; j > 0; j--) {
            dp[i] = max(dp[i], dp[j] + dp[j] * (i-j-2));
        }
    }
    printf("%lld", dp[n]);
}