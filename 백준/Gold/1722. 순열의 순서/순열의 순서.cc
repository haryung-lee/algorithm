#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef long long ll;
int dy[] = {0, 1, 0, -1}, dx[] = {-1, 0, 1, 0};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;

ll n, k;
vector<int> v;
int vis[21];
ll ans = 0;

ll fac(ll a) {
    ll ret = 1;
    for(ll i = a; i >= 1; i--) {
        ret *= i;
    }
    return ret;
}

int main() {
    scanf("%lld", &n);
    int a; scanf("%d", &a);
    if (a == 1) { // k번째 수 찾기
         scanf("%lld", &k);
         for(ll i = n-1; i > 0; i--) { // i+1번째 숫자 정하기
             int cnt = 0;
             for(int j = 1; j <= n; j++) {
                 if (vis[j]) continue;
                 cnt++;
                 if (k <= cnt * fac(i)) {
                     vis[j] = 1;
                     v.push_back(j);
                     k -= (cnt - 1) * fac(i);
                     break;
                 }
             }
         }
         for(int i = 1; i <= n; i++) {
             if (vis[i]) continue;
             v.push_back(i);
             break;
         }
         for(int i : v) printf("%d ", i);
    } else { // 수열이 몇번째인지 찾기
        for(int i = 0; i < n; i++) {
            int t; scanf("%d", &t);
            v.push_back(t);
        }
        for(int i = 0; i < n; i++) {
            ll cnt = 0;
            // v[i]가 상대적으로 몇번째인지 찾아야 함
            for(int j = 1; j <= n; j++) {
                if (vis[j]) continue;
                cnt++;
                if (j == v[i]) break;
            }
            vis[v[i]] = 1;
            ans += (cnt - 1) * fac(n-i-1);
        }
        printf("%lld", ans + 1);
    }
}