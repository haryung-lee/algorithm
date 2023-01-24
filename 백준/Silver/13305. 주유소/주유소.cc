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

int n, ans = 0;
int arr[100000];
int dis[100000];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i++) scanf("%d", &dis[i]);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    pq.push(arr[0]);
    for(int i = 1; i < n; i++) {
        ans += pq.top() * dis[i];
        pq.push(arr[i]);
    }
    printf("%d", ans);
}