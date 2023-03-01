#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <vector>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef long long ll;
int dy[] = {0, 1, 0, -1}, dx[] = {-1, 0, 1, 0};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;

int ans;

int chk(vector<int> v, ll n, int k) {
    int le = -1, ri = 0, tmp = 1;

    while(ri < v.size()) {
        if (v[ri] < n) {
            tmp = max(tmp, ri - le + 1);
            ri++;
        } else {
            v[ri] -= n;
            le = ri;
            ri++;
        }
        if (tmp > k) return 0;
    }
    return 1;
}

void go(vector<int> v, ll n, int k) {
    ll ri = n, le = 1, mi;

    while(le <= ri) {
        mi = (le + ri) / 2;
        if (chk(v, mi, k)) {
            le = mi + 1;
            ans = mi;
        }
        else ri = mi - 1;
//        printf("%lld %lld %lld : %d\n", le, mi, ri, chk(v, mi, k));
//        printf("\n================\n");
    }


}

ll solution(vector<int> stones, int k) {
    ll t = 200000*200000000;
    go(stones, t, k);
    return ans;
}
