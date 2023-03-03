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

int zero = 0, one = 0;

int chkSame(vector<vector<int>> &arr, int sn, int sm, int en, int em) {
    int tmp = arr[sn][sm];
    for(int i = sn; i < en; i++) {
        for(int j = sm; j < em; j++) {
            if (arr[i][j] != tmp) return 0;
        }
    }
    return 1;
}

void go(vector<vector<int>> &arr, int sn, int sm, int en, int em) {
    if (chkSame(arr, sn, sm, en, em) or (sn+1 == en and sm+1 == em)) {
        arr[sn][sm] ? one++ : zero++;
    } else {
        int a = (sn+en) / 2, b = (sm+em) / 2;
        go(arr, a, b, en, em);
        go(arr, sn, sm, a, b);
        go(arr, a, sm, en, b);
        go(arr, sn, b, a, em);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    int n = arr.size(), m = arr[0].size();
    go(arr, 0, 0, n, m);
    return {zero, one};
}