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
typedef pair<int, int> pii;
typedef pair<axis, pii> paii;

int arr[5][5];
int vis[5][5];
axis start;
bool isSuccess = false;

void DFS(axis a, int cnt, int apple) {
    if (cnt == 3) {
        if (apple >= 2) isSuccess = true;
        return;
    }
    for(int i = 0; i < 4; i++) {
        int x = a.x + dx[i], y = a.y + dy[i];
        if (x < 0 or y < 0 or x >= 5 or y >= 5) continue;
        if (arr[x][y] == -1) continue;
        if (arr[x][y]) {
            arr[x][y] = -1;
            DFS({x, y}, cnt + 1, apple + 1);
            arr[x][y] = 1;
        } else {
            arr[x][y] = -1;
            DFS({x, y}, cnt + 1, apple);
            arr[x][y] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    scanf("%d %d", &start.x, &start.y);
    if (arr[start.x][start.y]) {
        arr[start.x][start.y] = -1;
        DFS(start, 0, 1);
    } else {
        arr[start.x][start.y] = -1;
        DFS(start, 0, 0);
    }
    printf("%d", isSuccess);
}