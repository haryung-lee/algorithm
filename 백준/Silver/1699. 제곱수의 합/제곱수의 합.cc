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
int dp[100000];

int go(int total, int tmp) {
    if (total == n) {
       return 0;
    }
    if (dp[total] != -1) return dp[total];

    int ret = 1e9;
    for(int i = tmp; i*i+total <= n; i++) {
        ret = min(ret, go(total + i*i, i)+ 1);
    }
    return dp[total] = ret;
}

int main() {
    scanf("%d", &n);
    memset(dp, -1 ,sizeof(dp));
    printf("%d", go(0, 1));
}