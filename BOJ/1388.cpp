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
int dy[] = {0, 0, 1, -1}, dx[] = {-1, 1, 0, 0};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<char, int> pci;
typedef pair<axis, char> pac;

// 풀이 1
char arr[50][50];
int vis[50][50];
int ans = 0;
int n, m;

void DFS(axis t) {
    int start, end;
    if (arr[t.x][t.y] == '|') start = 0, end = 2;
    else start = 2, end = 4;
    for(int i = start; i < end; i++) {
        int x = t.x + dx[i], y = t.y + dy[i];
        if (x < 0 or y < 0 or x >= n or y >= m) continue;
        if (vis[x][y]) continue;
        if (arr[x][y] != arr[t.x][t.y]) continue;
        vis[x][y] = 1;
        DFS({x, y});
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            vis[i][j] = 1;
            ans++;
            DFS({i, j});
        }
    }
    printf("%d", ans);
}

// 풀이 2

int n, m;
char arr[50][50];

int go() {
    int ret = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (arr[i][j] == '-') {
                if (j == 0) ret++;
                else if (arr[i][j-1] != '-') ret++;
            }
        }
    }

    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            if (arr[i][j] == '|') {
                if (i == 0) ret++;
                else if (arr[i-1][j] != '|') ret++;
            }
        }
    }

    return ret;

}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }
    printf("%d", go());
}