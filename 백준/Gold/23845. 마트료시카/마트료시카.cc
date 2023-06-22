#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef long long ll;
int dy[] = {0, 1, 0, -1}, dx[] = {-1, 0, 1, 0};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;
typedef pair<ll, ll> pll;

ll n;
int cnt[100001];
ll mx = 0, ans = 0;


int main() {
    scanf("%lld", &n);
    vector<int> doll(n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &doll[i]);
        cnt[doll[i]]++;
    }

    sort(doll.begin(), doll.end());
    for(int i = 0; i < n; i++) {
        if (cnt[doll[i]] == 0) continue;
        cnt[doll[i]]--;
        mx = doll[i];
        ll t = 1;
        for(int j = doll[i]+1;; j++) {
            if (cnt[j] <= 0) {
                ans += mx * t;
                break;
            } else {
                mx = j;
                cnt[j]--;
                t++;
            }
        }
    }
    printf("%lld\n", ans);
}