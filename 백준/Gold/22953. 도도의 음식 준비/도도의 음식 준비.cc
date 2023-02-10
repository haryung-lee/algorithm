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

int n, k, c;
ll ans = 1e18;
ll arr[10];

void binarySearch() {
    ll le = 1, ri = 1000000000000, mi;

    while(le <= ri) {
        mi = (le + ri) / 2;
        ll sum = 0;
        for(int i = 0; i < n; i++) sum += (mi / arr[i]);
        if (sum >= k) {
            ri = mi - 1;
            ans = min(ans, mi);
        } else le = mi + 1;
    }
}

void go(int cnt) {
    if (cnt <= c) {
        binarySearch();
    }
    if (cnt < c) {
        for(int i = 0; i < n; i++) {
            if (arr[i] == 1) continue;
            arr[i]--;
            go(cnt + 1);
            arr[i]++;
        }
    }

}

int main() {
    scanf("%d %d %d", &n, &k, &c);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    go(0);
    printf("%lld", ans);
}