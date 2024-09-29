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

int main() {
    int n, k;
    int pre[200000], box[200000];
    map<int, int> mp;

    scanf("%d %d", &n, &k);
    for(int i = 0; i < n ;i++) {
        scanf("%d", &pre[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &box[i]);
    }
    sort(pre, pre + n);
    sort(box, box + n);

    for(int i = 0; i < k; i++) {
        int a; scanf("%d", &a);
        mp[a]++;
    }

    int tar;
    for(int i = n-1; i >= 0; i--) {
        if (mp[box[i]]) {
            mp[box[i]]--;
        } else {
            tar = box[i];
            break;
        }
    }
    printf("%d",  pre[upper_bound(pre, pre + n, tar) -1- pre]);
}