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

int n, m, T;
int k, a, b;

char arr[102][102]; // * 생명, . 빈칸
int cnt[102][102]; // 누적 합 (행 누적 합, 전체 누적합)

int main() {
    scanf("%d %d %d", &n, &m, &T);
    scanf("%d %d %d", &k, &a, &b);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }

    while(T--) {
        // 누적합 계산
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cnt[i][j] = cnt[i][j-1];
                if (arr[i][j] == '*') cnt[i][j]++;
            }
        }
        char newArr[102][102];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                axis mx = {min(i + k, n), min(j + k, m)};
                axis mn = {max(i - k, 0), max(j - k - 1, 0)};
                int total = 0;
                for(int z = mn.x; z <= mx.x; z++) {
                    total += cnt[z][mx.y] - cnt[z][mn.y];
                }
                if (arr[i][j] == '*') { // 현재 칸에 생명이 있다면
                    total--;
                    if (a <= total and total <= b) newArr[i][j] = '*';
                    else if (total < a) newArr[i][j] = '.';
                    else if (total > b) newArr[i][j] = '.';
                } else {
                    if (total > a and total <= b) newArr[i][j] = '*';
                    else newArr[i][j] = '.';
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                arr[i][j] = newArr[i][j];
            }
        }

    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}