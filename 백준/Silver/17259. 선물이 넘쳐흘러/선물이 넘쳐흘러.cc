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
int dy[] = {0, 1, 0 }, dx[] = {1,  0, -1 };
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;

struct info {
    int id; // 아이디
    int t; // 시간
    int cnt; // 선물 포장하는데 남은 시간
};

int n, b, m, ans = 0; // 공장 크기, 직원 수, 선물 개수
info arr[100][100]; // 선물과 직원의 id가 0보다 큼

int main() {
    scanf("%d %d %d", &n, &b, &m);
    for(int i = 0; i < b; i++) {
        int r, c, t;
        scanf("%d %d %d", &r, &c, &t);
        arr[r][c] = {i+1, t , 0}; // 직원 아이디, 걸리는 시간, 남은 시간 (0이라면 작업하지 않고 있음)
    }
    int tt = 100000;
    while(tt--) {
        // 1. 왼쪽으로
        for(int i = 1; i < n; i++) {
            arr[n-1][i-1] = arr[n-1][i];
        }

        // 2. 아래로
        for(int i = n - 2; i >= 0; i--) {
            arr[i+1][n-1] = arr[i][n-1];
        }

        // 3. 오른쪽으로
        for(int i = n - 2; i >= 0; i--) {
            arr[0][i+1] = arr[0][i];
        }

        // 컨베이어 벨트에 선물 추가하기
        if (m) {
            arr[0][0] = {m, 0, 1}; // 여기서 cnt는 선물 포장 전(1), 포장 후(0)
            m--;
        } else {
            arr[0][0] = {0, 0, 0};
        }

        // 직원들 확인하기
        // 1. 맨 위 라인
        for(int i = 0; i < n - 1; i++) {
            if (arr[1][i].id and arr[1][i].cnt) {
                arr[1][i].cnt--;
                if (arr[1][i].cnt == 0) ans++;
            }
            if (arr[1][i].id and !arr[1][i].cnt) { // 직원이 있고 하는게 없으면
                for(int j = 0; j < 3; j++) {
                    int x = 1 + dx[j], y = i + dy[j];
                    if (x < 0 or y < 0 or x >= n or y >= n) continue;
                    if (arr[x][y].id and arr[x][y].cnt and !arr[x][y].t) { // 상품이 있고 포장 전이라면
                        arr[x][y].cnt = 0; // 상품에 포장 후라는 표시
                        arr[1][i].cnt = arr[1][i].t; // 직원에게 남아 있는 시간 설정
                        break;
                    }
                }
            }
        }

        // 2. 오른쪽 라인
        for(int i = 2; i < n - 1; i++) {
            if (arr[i][n-2].id and arr[i][n-2].cnt) {
                arr[i][n-2].cnt--;
                if (arr[i][n-2].cnt == 0) ans++;
            }
            if (arr[i][n-2].id and !arr[i][n-2].cnt) { // 직원이 있고 하는게 없으면
                for(int j = 0; j < 3; j++) {
                    int x = i + dx[j], y = n-2 + dy[j];
                    if (x < 0 or y < 0 or x >= n or y >= n) continue;
                    if (arr[x][y].id and arr[x][y].cnt and !arr[x][y].t) { // 상품이 있고 포장 전이라면
                        arr[x][y].cnt = 0;
                        arr[i][n-2].cnt = arr[i][n-2].t;
                        break;
                    }
                }
            }
        }

        // 3. 아래 라인
        for(int i = n-3; i >= 0; i--) {
            if (arr[n-2][i].id and arr[n-2][i].cnt) {
                arr[n-2][i].cnt--;
                if (arr[n-2][i].cnt == 0) ans++;
            }
            if (arr[n-2][i].id and !arr[n-2][i].cnt) { // 직원이 있고 하는게 없으면
                for(int j = 0; j < 3; j++) {
                    int x = n-2 + dx[j], y = i + dy[j];
                    if (x < 0 or y < 0 or x >= n or y >= n) continue;
                    if (arr[x][y].id and arr[x][y].cnt and !arr[x][y].t) { // 상품이 있고 포장 전이라면
                        arr[x][y].cnt = 0;
                        arr[n-2][i].cnt = arr[n-2][i].t;
                        break;
                    }
                }
            }
        }
    }

    printf("%d", ans);
}