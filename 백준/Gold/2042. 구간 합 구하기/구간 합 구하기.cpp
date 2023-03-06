#include <cstdio>
using namespace std;
typedef long long ll;

ll arr[1000000];
ll tree[4000001];
ll n, m, k, a;

// start: 시작 인덱스, end: 끝 인덱스
ll init(ll start, ll end, ll node) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

ll sum(ll start, ll end, ll node, ll left, ll right) {
    if (left > end or right < start) return 0; // 범위 벗어나는 경우
    if (left <= start and end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2 + 1, left, right);
}

// start: 시작 인덱스, end: 끝 인덱스
// index: 구간 합을 수정하고자 하는 노드
// dif: 수정할 값
void update(ll start, ll end, ll node, ll index, ll dif) {
    if (index > end or index < start) return; // 범위 벗어나면 그냥 return
    tree[node] += dif; // 상위 노드인 node도 dif 반영
    if (start == end) return;
    ll mid = (start + end) / 2;
    update(start, mid, node*2, index, dif);
    update(mid+1, end, node*2+1, index, dif);
}

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    for(int i = 0; i < n; i++) scanf("%lld", &arr[i]);
    init(0, n-1, 1);
    for(int i = 0; i < m+k; i++) {
        ll b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a == 1) {
            update(1, n, 1, b, c - arr[b-1]);
            arr[b-1] = c;
        } else {
            printf("%lld\n", sum(1, n, 1, b, c));
        }
    }
}