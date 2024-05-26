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

ll x, y;
vector<ll> v;

int main() {
    scanf("%lld %lld", &x, &y);
    ll tmp = (x + y) * 2;

    tmp = ll(sqrt(tmp));
    if (tmp * (tmp+1) == (x+y) * 2) {
        // 누적합 계산
        v.push_back(0);
        for(int i = 1; i <= tmp; i++) {
            v.push_back(v[i-1] + i);
        }
        ll ans = tmp;
        for(int i = tmp; i > 0; i--) {
            if (v[tmp] - v[i] >= x) {
                ans = tmp - i;
                break;
            }
        }

        printf("%lld", ans);
    } else {
        printf("-1");
    }
}