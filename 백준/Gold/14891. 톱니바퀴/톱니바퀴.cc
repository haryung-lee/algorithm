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

int k, dir; // dir이 1이면 시계방향, -1이면 반시계 방향
deque<int> v[4];
// 2 6

void go(int ix, int d) { // ix를 d방향으로 회전시킴
    int darr[4]; // 회전해야 하는 방향 저장
    darr[ix] = d;

    int tmp = v[ix][2];

    // 1. 오른쪽에 있는 애들
    for(int i = ix + 1; i < 4; i++) {
        if (tmp == v[i][6]) { // 극이 같으면 회전 안함
            darr[i] = 0;
        } else { // 극이 다르면 반대 방향으로 회전함
            darr[i] = darr[i-1] * -1;
        }
        tmp = v[i][2];
    }

    tmp = v[ix][6];
    // 2. 왼쪽에 있는 애들
    for(int i = ix - 1; i >= 0; i--) {
        if (tmp == v[i][2]) {
            darr[i] = 0;
        } else {
            darr[i] = darr[i+1] * -1;
        }
        tmp = v[i][6];
    }

    for(int i = 0; i < 4; i++) {
        if (darr[i] == 0) continue; // 회전 안함
        if (darr[i] == 1) { // 시계 방향
            int t = v[i].back();
            v[i].pop_back();
            v[i].push_front(t);
        } else { // 반시계 방향
            int t = v[i].front();
            v[i].pop_front();
            v[i].push_back(t);
        }
    }
}

int main() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 8; j++) {
            int a; scanf("%1d", &a);
            v[i].push_back(a);
        }
    }

    scanf("%d", &k);
    while(k--) {
        int a, b; scanf("%d %d", &a, &b);
        a--;
        go(a, b);
    }

    int ans = 0;
    if (v[0][0]) ans += 1;
    if (v[1][0]) ans += 2;
    if (v[2][0]) ans += 4;
    if (v[3][0]) ans += 8;
    printf("%d", ans);
}