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

int n, m;
char arr[10][10];
char originArr[10][10];
axis target, red, blue, originRed, originBlue;
vector<int> v;
int ans = 0;
//pii isGoal = {0, 0};

// R 구슬 움직이기
void goURed() {
    if (red.x < 0) return;
    for(int i = red.x - 1; i >= 0; i--) {
        if (arr[i][red.y] == '#' or arr[i][red.y] == 'B') {
            arr[red.x][red.y] = '.';
            red = {i + 1, red.y};
            arr[red.x][red.y] = 'R';
            break;
        }
        if (arr[i][red.y] == 'O') {
            arr[red.x][red.y] = '.';
            red = {-1, -1}; // R 구슬 구멍엥 들어감
            break;
        }
    }
}

void goUBlue() {
    if (blue.x < 0) return;
    for(int i = blue.x - 1; i >= 0; i--) {
        if (arr[i][blue.y] == '#' or arr[i][blue.y] == 'R') {
            arr[blue.x][blue.y] = '.';
            blue = {i + 1, blue.y};
            arr[blue.x][blue.y] = 'B';
            break;
        }
        if (arr[i][blue.y] == 'O') {
            arr[blue.x][blue.y] = '.';
            blue = {-1, -1};
            break;
        }
    }
}

void goU() {
    // R, B 중 더 위에 있는 구슬부터 이동
    if (red.x < blue.x) {
        goURed();
        goUBlue();
    } else {
        goUBlue();
        goURed();
    }
}

void goDRed() {
    if (red.x < 0) return;
    for(int i = red.x + 1; i < n; i++) {
        if (arr[i][red.y] == '#' or arr[i][red.y] == 'B') {
            arr[red.x][red.y] = '.';
            red = {i - 1, red.y};
            arr[red.x][red.y] = 'R';
            break;
        }
        if (arr[i][red.y] == 'O') {
            arr[red.x][red.y] = '.';
            red = {-1, -1}; // R 구슬 구멍엥 들어감
            break;
        }
    }
}

void goDBlue() {
    if (blue.x < 0) return;
    for(int i = blue.x + 1; i < n; i++) {
        if (arr[i][blue.y] == '#' or arr[i][blue.y] == 'R') {
            arr[blue.x][blue.y] = '.';
            blue = {i - 1, blue.y};
            arr[blue.x][blue.y] = 'B';
            break;
        }
        if (arr[i][blue.y] == 'O') {
            arr[blue.x][blue.y] = '.';
            blue = {-1, -1};
            break;
        }
    }
}

// 아래로 이동
void goD() {
    // R, B중 더 아래에 있는 구슬부터 이동
    if (red.x > blue.x) {
        goDRed();
        goDBlue();
    } else {
        goDBlue();
        goDRed();
    }
}

void goLRed() {
    if (red.x < 0) return;
    for(int i = red.y - 1; i >= 0; i--) {
        if (arr[red.x][i] == '#' or arr[red.x][i] == 'B') {
            arr[red.x][red.y] = '.';
            red = {red.x, i + 1};
            arr[red.x][red.y] = 'R';
            break;
        }
        if (arr[red.x][i] == 'O') {
            arr[red.x][red.y] = '.';
            red = {-1, -1}; // R 구슬 구멍엥 들어감
            break;
        }
    }
}

void goLBlue() {
    if (blue.x < 0) return;
    for(int i = blue.y - 1; i >= 0; i--) {
        if (arr[blue.x][i] == '#' or arr[blue.x][i] == 'R') {
            arr[blue.x][blue.y] = '.';
            blue = {blue.x, i + 1};
            arr[blue.x][blue.y] = 'B';
            break;
        }
        if (arr[blue.x][i] == 'O') {
            arr[blue.x][blue.y] = '.';
            blue = {-1, -1}; // B 구슬 구멍엥 들어감
            break;
        }
    }
}

// 왼쪽으로 이동
void goL() {
    // R, B중 더 왼쪽에 있는 구슬부터 이동
    if (red.y < blue.y) {
        goLRed();
        goLBlue();
    } else {
        goLBlue();
        goLRed();
    }
}

void goRRed() {
    if (red.x < 0) return;
    for(int i = red.y + 1; i < m; i++) {
        if (arr[red.x][i] == '#' or arr[red.x][i] == 'B') {
            arr[red.x][red.y] = '.';
            red = {red.x, i - 1};
            arr[red.x][red.y] = 'R';
            break;
        }
        if (arr[red.x][i] == 'O') {
            arr[red.x][red.y] = '.';
            red = {-1, -1}; // R 구슬 구멍엥 들어감
            break;
        }
    }
}

void goRBlue() {
    if (blue.x < 0) return;
    for(int i = blue.y + 1; i < m; i++) {
        if (arr[blue.x][i] == '#' or arr[blue.x][i] == 'R') {
            arr[blue.x][blue.y] = '.';
            blue = {blue.x, i - 1};
            arr[blue.x][blue.y] = 'B';
            break;
        }
        if (arr[blue.x][i] == 'O') {
            arr[blue.x][blue.y] = '.';
            blue = {-1, -1}; // B 구슬 구멍엥 들어감
            break;
        }
    }
}

// 오른쪽으로 이동
void goR() {
    // R, B중 더 오른쪽에 있는 구슬부터 이동
    if (red.y > blue.y) {
        goRRed();
        goRBlue();
    } else {
        goRBlue();
        goRRed();
    }
}

void go() {
    if (v.size() == 10) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                arr[i][j] = originArr[i][j];
            }
        }
        red = originRed;
        blue = originBlue;
        for(int i : v) {
            if (i == 0) { // 왼쪽
                goL();
            } else if (i == 1) { // 오른쪽
                goR();
            } else if (i == 2) { // 위
                goU();
            } else if (i == 3) { // 아래
                goD();
            }
//            printf("i : %d\n", i);
//            for(int ii = 0; ii < n; ii++) {
//                for(int jj = 0; jj < m; jj++) {
//                    printf("%c", arr[ii][jj]);
//                }
//                printf("\n");
//            }
//            printf("============\n");
            if (red.x == -1 and blue.x != -1) {
                ans = 1;
                return;
            } else if (red.x == -1 and blue.x == -1) return;
        }
//        printf("\n\n");
    } else {
        for(int i = 0; i < 4; i++) {
            v.push_back(i);
            go();
            v.pop_back();
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++ ) {
        for(int j = 0; j < m; j++) {
            scanf(" %c", &originArr[i][j]);
            if (originArr[i][j] == 'O') target = {i, j};
            if (originArr[i][j] == 'R') originRed = {i, j};
            if (originArr[i][j] == 'B') originBlue = {i, j};
        }
    }
    go();
    printf("%d", ans);
}