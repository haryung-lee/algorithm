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
int dy[] = {0, 1}, dx[] = {1, 0};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, int> pai;
typedef pair<axis, psi> pas;

int n;
int arr[3][3];
int vis[3][3];
bool isEnd = false;
queue<pai> q;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    q.push({{0, 0}, arr[0][0]});
    vis[0][0] = 1;

    while(!q.empty()) {
        axis t = q.front().first;
        int num = q.front().second; q.pop();
        if (t.x == n-1 and t.y == n-1) {
            isEnd = true;
            break;
        }

        for(int i = 0; i < 2; i++) {
            int x = t.x + num * i, y = t.y + num * (1 - i);
            if (x < 0 or y < 0 or x >= n or y >= n) continue;
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            q.push({{x, y}, arr[x][y]});
        }
    }

    if (isEnd) printf("HaruHaru");
    else printf("Hing");
}