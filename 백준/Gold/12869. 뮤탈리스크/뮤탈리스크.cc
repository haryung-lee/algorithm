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
int arr[3];
int dp[61][61][61];

int go(int a, int b, int c) {
    if (dp[a][b][c] != -1) return dp[a][b][c];
    if (a >= arr[0] and b >= arr[1] and c >= arr[2]) return 0;

    int ret = 1e9;

    if (a < arr[0] and b < arr[1] and c < arr[2]) {
        ret = min(ret, go(min(a + 9, 60), min(b + 3, 60), min(c + 1, 60)) + 1);
        ret = min(ret, go(min(a + 9, 60), min(b + 1, 60), min(c + 3, 60)) + 1);
        ret = min(ret, go(min(a + 3, 60), min(b + 9, 60), min(c + 1, 60)) + 1);
        ret = min(ret, go(min(a + 3, 60),min(b + 1, 60),min(c + 9, 60)) + 1);
        ret = min(ret, go(min(a + 1, 60), min(b + 9, 60), min(c + 3, 60)) + 1);
        ret = min(ret, go(min(a + 1, 60), min(b + 3, 60), min(c + 9, 60)) + 1);
    } else if (a < arr[0] and b < arr[1]) {
        ret = min(ret, go(min(a + 9, 60), min(b + 3, 60), c) + 1);
        ret = min(ret, go(min(a + 3, 60), min(b + 9, 60), c) + 1);
    } else if (a < arr[0] and c < arr[2]) {
        ret = min(ret, go(min(a + 9, 60), b, min(c + 3, 60)) + 1);
        ret = min(ret, go(min(a + 3, 60), b, min(c + 9, 60)) + 1);
    } else if (b < arr[1] and c < arr[2]) {
        ret = min(ret, go(a, min(b + 9, 60), min(c + 3, 60)) + 1);
        ret = min(ret, go(a, min(b + 3, 60), min(c + 9, 60)) + 1);
    } else if (a < arr[0]) {
        ret = min(ret, go(min(a + 9, 60), b, c) + 1);
    } else if (b < arr[1]) {
        ret = min(ret, go(a, min(b + 9, 60), c) + 1);
    } else if (c < arr[2]) {
        ret = min(ret, go(a, b, min(c + 9, 60)) + 1);

    }

    return dp[a][b][c] = ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d", go(0, 0, 0));
}