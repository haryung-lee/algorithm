#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
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

int tc;

void go() {
    int n, k, arr[11];
    scanf("%d", &n);
    unordered_map<int, int> mp;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    scanf("%d", &k);
    pq.push({0, k});
    mp[k] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first, cur = pq.top().second;
        pq.pop();
        if (cur == 0) {
            printf("%d\n", cost);
            return;
        }
        for (int i = 0; i < n; i++) {
            if ((cur % arr[i]) == 0) {
                if (mp.find(cur/arr[i]) != mp.end() and mp[cur/arr[i]] <= cost) continue;
                pq.push({cost, cur / arr[i]});
                mp[cur/arr[i]] = cost;
            } else if (cur - (cur % arr[i]) >= 0) {
                if (mp.find(cur-(cur%arr[i])) != mp.end() and mp[cur-(cur%arr[i])] <= cost + (cur % arr[i])) {
                    continue;
                }
                pq.push({cost + (cur % arr[i]), cur - (cur % arr[i])});
                mp[cur-(cur%arr[i])] = cost + (cur % arr[i]);
            }
        }
    }
}


int main() {
    scanf("%d", &tc);
    for(int i = 1; i <= tc; i++) {
        printf("#%d ", i);
        go();
    }
}