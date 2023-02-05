#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int tc, n, m, arr[30][30];

int sol(int a, int b) {
    if (arr[a][b]) return arr[a][b];
    if (a == b or a == 1) return 1;
    else if (b == 1) return a;
    int ret = sol(a - 1, b - 1) + sol(a - 1, b);
    return arr[a][b] = ret;
}

int main() {
    scanf("%d", &tc);
    while (tc--){
        scanf("%d %d", &n, &m);
        printf("%d\n", sol(m, n));
    }
}
