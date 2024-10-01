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

struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;

int main() {
    int n, k, ans = 0;
    deque<int> dq;
    int arr[200000];

    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + n);

    for(int i = 0; i < n; i++) {
        if (arr[i] >= k) {
            ans++;
        } else {
            dq.push_back(arr[i]);
        }
    }

    while(!dq.empty()) {
        int b = dq.back(); dq.pop_back();

        while(!dq.empty()) {
            int f = dq.front(); dq.pop_front();
            if (b + f >= k) {
                ans++;
                break;
            }
        }
    }


    if (ans == 0) {
        printf("-1");
    } else printf("%d", ans);
}