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

#define MOD 1000000007

ll go(int cnt) {
    ll ret = 1;
    while(cnt--) {
        ret *= 3;
        ret %= MOD;
    }

    return ret;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    if(n < m) swap(n, m);

    ll ans = 0;
    if (n % 3 == 0 or m % 3 == 0) {
        if (n%3 == 0) {
            int tmp = n/3;
            ans = go(tmp * m);
        } else {
            int tmp = m/3;
            ans = go(tmp * n);
        }
    } else if (n%3 == 1) {
        if (m%3 == 1) { // 둘다 나머지1
            int tmp = max((n/3) - 1, 0);
            ans = go(n * (max((m-1), 0)/3) + tmp);
            if (n >= 4) ans *= 4;
        } else { // n만 나머지 1
            int tmp = (m/3);
            ans = go(m * (max((n-1), 0))/3 + tmp);
            if (m >= 2) ans *= 2;
        }
    } else if (n%3 == 2) {
        if (m % 3 == 1) {
            int tmp = n/3;
            ans = go(n * (max(m-1, 0))/3 + tmp);
            if (n >= 2) ans *= 2;
        } else {
            int tmp = (n / 3) * 2;
            ans = go(n * (max(m - 2, 0))/3 + tmp);
            if (n >= 2) ans *= 4;
        }
    }

    printf("%lld", ans % MOD);
}