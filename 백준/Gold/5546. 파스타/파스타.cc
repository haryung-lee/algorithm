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
#define MOD 10000
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef long long ll;
int dy[] = {0, 1, 0, -1}, dx[] = {-1, 0, 1, 0};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;


int arr[101][4][4][4];
int n, k;
int fx[101];

int go(int ix, int a, int b, int c) {
    if (arr[ix][a][b][c] != -1) return arr[ix][a][b][c];
    if (a > 2) return 0;
    if (b > 2) return 0;
    if (c > 2) return 0;
    if (ix == n) return 1;
    int ret = 0;

    if (fx[ix+1] == 1) {
        ret += (go(ix + 1, a + 1, 0, 0) ) % MOD;
    } else if (fx[ix+1] == 2) {
        ret += (go(ix + 1, 0, b + 1, 0)) % MOD;
    } else if (fx[ix+1] == 3) {
        ret += (go(ix + 1, 0, 0, c + 1)) % MOD;
    } else {
        ret += (go(ix + 1, a + 1, 0, 0)) % MOD;
        ret += (go(ix + 1, 0, b + 1, 0)) % MOD;
        ret += (go(ix + 1, 0, 0, c + 1)) % MOD;
    }

    return arr[ix][a][b][c] = ret % MOD;
}

int main() {
    memset(arr, -1, sizeof(arr));
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        fx[a] = b;
    }

   printf("%d", go(0, 0, 0, 0));

}