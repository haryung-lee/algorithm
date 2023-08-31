#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef long long ll;
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1}, dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;

struct info {
    int n, dir; // 번호와 방향 (0은 상어), n이 -1이면 아무것도 없는 칸
};

int ans = 0;
vector<int> v; // 상어가 이동하는 칸들
set<int> st; // 상어가 먹은 물고기들

void go(bool isGo, axis cur, int dir, info arr[4][4], axis d[31]) {
    if (!isGo) { // 상어가 더이상 못가면 max값 갱신
        int tmp = 0;
        for(int i : v) {
            tmp += i;
        }
        ans = max(ans, tmp);
        return;
    }

    int flag = 0;
    for(int i = 0; i < 4; i++) {
        int x = cur.x + dx[dir] * i, y = cur.y + dy[dir] * i; // 상어 위치
        if (x < 0 or y < 0 or x >= 4 or y >= 4) continue;
        if (st.find(arr[x][y].n) != st.end()) continue; // 물고기가 없으면 이동 못함
        flag = 1;

        info newArr[4][4];
        axis newD[31];
        for(int ii = 0; ii < 4; ii++) {
            for(int jj = 0; jj < 4; jj++){
                newArr[ii][jj] = arr[ii][jj];
            }
        }

        for(int ii = 0; ii < 31; ii++) {
            newD[ii] = d[ii];
        }

        v.push_back(newArr[x][y].n); // 벡터에 상어 이동한 곳 저장
        st.insert(newArr[x][y].n);

        for(int ii = 1; ii < 31; ii++) {
            if (newD[ii].x == x and newD[ii].y == y) continue; // 상어는 패스
            if (newD[ii].x < 0) continue;
            if (st.find(newArr[newD[ii].x][newD[ii].y].n) != st.end()) continue; // 아무것도 없는 곳은 패스
            int dirr = newArr[newD[ii].x][newD[ii].y].dir; // 물고기 방향

            bool isMove = false;


            // 반시계 방향으로 돌면서 이동할 수 있는 물고기 탐색
            for(int jj = dirr; jj < 8; jj++) {
                int xx = newD[ii].x + dx[jj], yy = newD[ii].y + dy[jj];
                if (xx < 0 or yy < 0 or xx >= 4 or yy >= 4) continue; // 경계를 벗어나거나
                if (xx == x and yy == y) continue; // 상어가 있으면 이동 못함
                newArr[newD[ii].x][newD[ii].y].dir = jj; // 돌린 방향 적용
                int B = newArr[xx][yy].n;

                swap(newArr[newD[ii].x][newD[ii].y], newArr[xx][yy]);
                swap(newD[ii], newD[B]);
                isMove = true;
                break;
            }
            if (isMove) continue;

            for(int jj = 0; jj < dirr; jj++) {
                int xx = newD[ii].x + dx[jj], yy = newD[ii].y + dy[jj];
                if (xx < 0 or yy < 0 or xx >= 4 or yy >= 4) continue; // 경계를 벗어나거나
                if (xx == x and yy == y) continue; // 상어가 있으면 이동 못함
                newArr[newD[ii].x][newD[ii].y].dir = jj;
                int B = newArr[xx][yy].n;

                swap(newArr[newD[ii].x][newD[ii].y], newArr[xx][yy]);
                swap(newD[ii], newD[B]);
                break;
            }
        }
        go(true, {x, y}, newArr[x][y].dir, newArr, newD);

        v.pop_back();
        st.erase(newArr[x][y].n);
    }
    if (!flag) go(false, {0, 0}, 0, arr, d);
}

int main() {
    info arr[4][4];
    axis d[31]; // 0번부터 30번까지의 생선이 있는 위치

    memset(d, -1, sizeof(d));
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            int a, b; scanf("%d %d", &a, &b); b--;
            arr[i][j] = {a, b};
            d[a] ={i, j};
        }
    }

    v.push_back(arr[0][0].n);
    st.insert(arr[0][0].n);

    // 물고기 이동

    for(int ii = 1; ii < 31; ii++) {
        if (d[ii].x <= 0 and d[ii].y <= 0) continue;
        int dirr = arr[d[ii].x][d[ii].y].dir;
        int A = arr[d[ii].x][d[ii].y].n;

        bool isMove = false;
        for(int jj = dirr; jj < 8; jj++) {
            int xx = d[ii].x + dx[jj], yy = d[ii].y + dy[jj];
            if (xx < 0 or yy < 0 or xx >= 4 or yy >= 4) continue; // 경계를 벗어나거나
            if (xx == 0 and yy == 0) continue; // 상어가 있으면 이동 못함
            int B = arr[xx][yy].n;

            arr[d[ii].x][d[ii].y].dir = jj;

            swap( arr[d[ii].x][d[ii].y], arr[xx][yy]);
            swap(d[A], d[B]);
            isMove = true;
            break;
        }
        if (isMove) continue;

        for(int jj = 0; jj < dirr; jj++) {
            int xx = d[ii].x + dx[jj], yy = d[ii].y + dy[jj];
            if (xx < 0 or yy < 0 or xx >= 4 or yy >= 4) continue; // 경계를 벗어나거나
            if (xx == 0 and yy == 0) continue; // 상어가 있으면 이동 못함
            arr[d[ii].x][d[ii].y].dir = jj;
            int B = arr[xx][yy].n;

            swap( arr[d[ii].x][d[ii].y], arr[xx][yy]);
            swap(d[A], d[B]);
            break;
        }
    }

    go(true, {0, 0}, arr[0][0].dir, arr, d);

    printf("%d", ans);
}