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

int n, w, l;
int arr[1000];
int ans = 0, cnt = 0;
deque<int> dq;

int main() {
    scanf("%d %d %d", &n, &w, &l);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int sm = 0, ix = 0;

    while(ix < n) {
        if (dq.size() == w) {
            sm -= dq.front();
            dq.pop_front();
        }
        if (sm + arr[ix] <= l) {
            sm += arr[ix];
            dq.push_back(arr[ix++]);
        } else {
            dq.push_back(0);
            ans++;
        }
    }
    printf("%d", ans + n + w);
}