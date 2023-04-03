#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef long long ll;
int dy[] = {0, 1, 1, -1, 0}, dx[] = {1, 0,  1, 0, -1};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;

int n;
int arr[16][16];
int ans = 0;

void go(axis cur, int mode) { // 0: 아래, 1: 오, 2: 대각선
    if (cur.x == n-1 and cur.y == n-1) {
        ans++;
        return;
    } else {
        if (mode == 0) {
            for (int i = 0; i < 3; i++) {
                if (i == 1) continue;
                int x = cur.x + dx[i], y = cur.y + dy[i];
                if (x >= n or y >= n) continue;
                if (arr[x][y]) continue;
                bool check = true;
                if (i == 2) {
                    for(int j = 3; j < 5; j++) {
                        int xx = x + dx[j], yy = y + dy[j];
                        if (xx < 0 or yy < 0 or xx >= n or yy >= n or arr[xx][yy]) {
                            check = false;
                            break;
                        }
                    }
                }
                if (check) {
                    go({x, y}, i);
                }
            }
        } else if (mode == 1) {
            for (int i = 2; i >= 1; i--) {
                int x = cur.x + dx[i], y = cur.y + dy[i];
                if (x >= n or y >= n) continue;
                if (arr[x][y]) continue;
                bool check = true;
                if (i == 2) {
                    for(int j = 3; j < 5; j++) {
                        int xx = x + dx[j], yy = y + dy[j];
                        if (xx < 0 or yy < 0 or xx >= n or yy >= n or arr[xx][yy]) {
                            check = false;
                            break;
                        }
                    }
                }
                if (check) {
                    go({x, y}, i);
                }
            }
        } else {
            for (int i = 0; i < 3; i++) {
                int x = cur.x + dx[i], y = cur.y + dy[i];
                if (x >= n or y >= n) continue;
                if (arr[x][y]) continue;
                bool check = true;
                if (i == 2) {
                    for(int j = 3; j < 5; j++) {
                        int xx = x + dx[j], yy = y + dy[j];
                        if (xx < 0 or yy < 0 or xx >= n or yy >= n or arr[xx][yy]) {
                            check = false;
                            break;
                        }
                    }
                }
                if (check) {
                    go({x, y}, i);
                }
            }
        }
    }

}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    go({0, 1}, 1);
    printf("%d", ans);
}