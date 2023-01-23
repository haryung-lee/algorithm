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
typedef pair<pii, int> piii;

int n;
pii arr[200000];
map<pii, int> mp;

int main() {
    int ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        mp[{a, b}]++;
    }

    while(!mp.empty()) {
        auto it = mp.begin(); ans++;
        piii itValue = *mp.begin();
//        printf("1 : %d %d %d\n", itValue.first.first, itValue.first.second, itValue.second);
        if (itValue.second > 1) mp[itValue.first]--;
        else mp.erase(it);
        while(mp.lower_bound({itValue.first.second, -1}) != mp.end()) {
            it = mp.lower_bound({itValue.first.second, -1});
            itValue = *it;

            if (itValue.second > 1) mp[itValue.first]--;
            else mp.erase(it);
//            printf("2 : %d %d %d\n", itValue.first.first, itValue.first.second, itValue.second);
        }
    }
    printf("%d", ans);
}