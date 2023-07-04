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

int total = 0;
vector<int> ans(11), lion, apeach;

void go(int n, int ix, int t) {
    if (ix == 10) {
        lion.push_back(n - t);
        int p = 0, l = 0;
        for(int i = 0; i < 11; i++) {
            if (lion[i] > apeach[i]) {
                l += (10 - i);
            } else if (lion[i] <= apeach[i] and apeach[i] > 0) {
                p += (10 - i);
            }
        }
        if (l > p and total < (l - p)) { // 더 큰 차이로 우승
            total = l - p;
            for(int i = 0; i < 11; i++) ans[i] = lion[i];
        } else if (l > p and total == (l - p)) { // 차이가 같음
            int flag;
            for(int i = 10; i >= 0; i--) {
                if (ans[i] != lion[i]) {
                    if (ans[i] < lion[i]) flag = 1;
                    else flag = 0;
                    break;
                }
            }
            if (flag) {
                for(int i = 0; i < 11; i++) ans[i] = lion[i];
            }
        }
        lion.pop_back();
        return;
    }
//    printf("t : %d\n", t);
    if (t + apeach[ix] + 1 <= n) {
        lion.push_back(apeach[ix] + 1);
        go(n, ix + 1, t + apeach[ix] + 1);
        lion.pop_back();
    }
    lion.push_back(0);
    go(n, ix + 1, t);
    lion.pop_back();

}

vector<int> solution(int n, vector<int> info) {
    apeach = info;
    go(n, 0, 0);
    if (total == 0) ans = {-1};
    return ans;
}
