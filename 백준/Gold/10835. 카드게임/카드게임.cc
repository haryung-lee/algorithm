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
int arr[2000][2];
int dp[2000][2000];

int go(int le, int ri) {
    if (le == n or ri == n) return 0;

    if (dp[le][ri] != -1) return dp[le][ri];
    int ret = max(go(le+1, ri), go(le+1, ri+1));

    if (arr[le][0] > arr[ri][1]) { // 오른쪽 카드가 더 작다면
        ret = max(ret, go(le, ri + 1) + arr[ri][1]);
    }

    return dp[le][ri] = ret;
}


int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i][0]);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i][1]);

    memset(dp, -1, sizeof(dp));
    printf("%d", go(0, 0));
}