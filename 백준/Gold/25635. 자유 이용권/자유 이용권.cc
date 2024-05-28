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
ll arr[100001];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &arr[i]);
    }
    sort(arr + 1, arr + n + 1);
    for(int i = 1; i <= n; i++) {
        arr[i] += arr[i-1];
    }

    ll ans = 0;
    for(int i = n; i > 0; i--) {
        ll cur = arr[i] - arr[i-1] - 1; // 지금 필요한거

        if (cur > arr[i-1] + ans) {
            ans += arr[i-1] + 1;
        } else ans += arr[i] - arr[i-1];
    }

    printf("%lld", ans);

}