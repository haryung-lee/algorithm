#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <deque>
#include <set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

int n;
multiset<pii> mp;

int main() {
    int ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        mp.insert({a, b});
    }

    while(!mp.empty()) {
        auto it = mp.begin(); ans++;
        pii itValue = *mp.begin();

        mp.erase(it);
        while(mp.lower_bound({itValue.second, -1}) != mp.end()) {
            it = mp.lower_bound({itValue.second, -1});
            itValue = *it;
            mp.erase(it);
        }
    }
    printf("%d", ans);
}