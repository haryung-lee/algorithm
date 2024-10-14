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

int main() {
    ll h; int n, q;
    ll arr[300000];
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    scanf("%lld", &h);
    scanf("%d %d", &n, &q);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    sort(arr, arr + n);
    ll sm = 0;

    for(int i = n-1; i >= 0; i--) {
        sm += arr[i];
        pq.push(arr[i]);

        if (sm >= h) {
            break;
        }
    }

    printf("%d\n", sm >= h ? pq.size() : -1);

    while(q--) {
        ll a; scanf("%lld", &a);

        if (sm < h) {
            pq.push(a);
            sm += a;
            printf("%d\n", sm >= h ? pq.size() : -1);
            continue;
        } else if (pq.top() > a) {
            printf("%d\n", pq.size());
            continue;
        }
        pq.push(a);
        sm += a;
        while(!pq.empty()) {
            if (sm - pq.top() >= h) {
                sm -= pq.top();
                pq.pop();
            } else {
                break;
            }
        }

        printf("%d\n", pq.size());
    }
}