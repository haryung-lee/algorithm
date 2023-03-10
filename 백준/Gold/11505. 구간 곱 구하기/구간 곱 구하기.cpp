#include <cstdio>
using namespace std;
typedef long long ll;

ll MOD = 1000000007;
ll n, m, k;
ll tree[4000001];
ll arr[1000000];

ll init(ll le, ll ri, ll node) {
    if (le == ri) return tree[node] = arr[le];
    ll mi = (le + ri) / 2;
    return tree[node] = (((init(le, mi, node * 2)) % MOD) * (init(mi + 1, ri, node*2 + 1) % MOD)) % MOD;
}

ll cal(ll le, ll ri, ll node, ll st, ll en) {
    if (ri < st or en < le) return 1;
    if (st <= le and ri <= en) return tree[node];
    ll mi = (le + ri) / 2;
    return (cal(le, mi, node*2, st, en) % MOD * cal(mi + 1, ri, node*2 + 1, st, en) % MOD) % MOD;
}

ll update(ll le, ll ri, ll node, ll u, ll p) {
    if (ri < u or u < le) return tree[node];
    if (le == ri) return tree[node] = p;
    ll mi = (le + ri) / 2;
    return tree[node] = ((update(le, mi, node * 2, u, p) % MOD) * (update(mi + 1, ri, node*2 + 1, u, p) % MOD)) % MOD;
}


int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    init(0, n-1, 1);

    for(int i = 0; i < m+k; i++) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a == 1) {
            update(0, n-1, 1, b-1,  c);
            arr[b-1] = c;
        } else {
            printf("%lld\n", cal(0, n-1, 1, b-1, c-1));
        }
    }
}