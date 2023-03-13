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
int dy[] = {0, 1, -1}, dx[] = {-1, 0, -1};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;

bool isFirst = true;

vector<int> solution(int n) {
    vector<int> answer;
    int cnt = (n * (n+1)) / 2, tmp = 1;
    int arr[n][n], x = 0, y = 0, le = 0, ri = n-1, to = 0, bo = n-1;
    while(1) {
        x = to;
        while(cnt > 0) {
            arr[x][y] = tmp++;
            x++;
            cnt--;
            if (x >= bo) break;
        }
        y = le++;
        to = isFirst ? to + 1 : to + 2;

        while(cnt > 0) {
            arr[x][y] = tmp++;
            y++;
            cnt--;
            if (y >= ri) break;
        }
        isFirst = false;
//        y--;
        while(cnt > 0) {
            arr[x][y] = tmp++;
            x--; y--;
            cnt--;
            if (x <= to) break;
        }
        ri = isFirst ? ri - 1 : ri - 2;


        bo--;
        if (cnt <= 0) break;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            answer.push_back(arr[i][j]);
        }
    }
    return answer;
}
