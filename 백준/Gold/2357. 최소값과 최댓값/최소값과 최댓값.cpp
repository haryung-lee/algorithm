#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, m;
int arr[100000];
pii tree[400001];

pii init(int le, int ri, int node) {
    if (le == ri) return tree[node] = {arr[le], arr[le]};
    int mi = (le + ri) / 2;
    pii ln = init(le, mi, node*2);
    pii rn = init(mi+1, ri, node*2+1);
    return tree[node] = {min(ln.first, rn.first), max(ln.second, rn.second)};
}

pii find(int le, int ri, int node, int st, int en) {
    if (ri < st or en < le) return {1e9, 0};
    if (le >= st and en >= ri) return tree[node];
    if (le == ri) return tree[node];
    int mi = (le + ri) / 2;
    pii ln = find(le, mi, node*2, st, en), rn = find(mi+1, ri, node*2+1, st, en);
    return {min(ln.first, rn.first), max(ln.second, rn.second)};
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    init(0, n-1, 1);

    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        pii t = find(0, n-1, 1, a, b);
        printf("%d %d\n", t.first, t.second);
    }
}