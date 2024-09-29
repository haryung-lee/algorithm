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
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    int n, m;
    int anX[] = {1, 10}, anY[] = {1, 10};
    int X = -1, Y = -1;
    scanf("%d %d", &n, &m);

    anX[1] = min(anX[1], n);
    anY[1] = min(anY[1], n);
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        c--;

        pii tmp = {dx[c], dy[c]};
        if (tmp.first < 0) {
            anX[1] = min(anX[1], a - 1);
        } else if (tmp.first > 0) {
            anX[0] = max(anX[0], a + 1);
        } else
            X = a;

        if (tmp.second < 0) {
            anY[1] = min(anY[1], b - 1);
        } else if (tmp.second > 0) {
            anY[0] = max(anY[0], b + 1);
        } else
            Y = b;
    }

    if (X != -1)
        printf("%d ", X);
    else
        printf("%d ", anX[1]);

    if (Y != -1)
        printf("%d", Y);
    else
        printf("%d", anY[1]);
}
