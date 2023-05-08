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

int n, tc = 1;
int arr[100000][3];
int dp[100000][3];

int go(int x, int y) {
    if (x == n-1) {
        if (y == 1) return arr[x][y];
        else if (y == 0) return arr[x][y] + arr[x][y+1];
        else return 1e9;
    }
    if (dp[x][y] != -1) return dp[x][y];
    int ret;
    if (y == 0) { // 가장 왼쪽
        ret = min(go(x, y + 1) + arr[x][y], go(x + 1, y) + arr[x][y]);
        ret = min(ret, go(x + 1, y + 1) + arr[x][y]);
    } else if (y == 1) { // 중간
        ret = min(go(x, y + 1) + arr[x][y], go(x + 1, y) + arr[x][y]);
        ret = min(ret, go(x + 1, y + 1) + arr[x][y]);
        ret = min(ret, go(x + 1, y - 1) + arr[x][y]);
    } else { // 가장 오른쪽
        ret = min(go(x + 1, y) + arr[x][y], go(x + 1, y - 1) + arr[x][y]);
    }

    return dp[x][y] = ret;
}

int main() {
    while(1) {
        scanf("%d", &n);
        memset(dp, -1, sizeof(dp));
        if (n == 0) break;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 3; j++) {
                scanf("%d", &arr[i][j]);
            }
        }

        printf("%d. %d\n", tc, go(0, 1));
        tc++;
    }
}