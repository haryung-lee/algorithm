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
int dy[4] = {0, 1, 1, 0}, dx[4] = { 1, 0, 1, 0};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;

int vis[30][30];

vector<string> rearrangement(int n, int m, vector<string> v) {
    vector<string> ret;
    for(int i = 0; i < n; i++) {
        ret.emplace_back("");
        int cnt = 0;
        for(int j = 0; j < m; j++) {
            if (vis[i][j]) cnt++;
            else ret[i].push_back(v[i][j]);
        }
        while(cnt--) {
            ret[i].push_back('.');
        }
    }
    return ret;
};


int solution(int m, int n, vector<string> board) {// m행 n열
    int answer = 0;
    bool isContinue = false;
    vector<string> newBoard;

    for(int i = 0; i < n; i++) {
        newBoard.emplace_back("");
        for(int j = m-1; j >= 0; j--) {
            newBoard[i].push_back(board[j][i]);
        }
    }

    while (1) {
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (newBoard[i][j] == '.') continue;
                bool isSame = true;
                for(int k = 0; k < 3; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= n or y >= m) isSame = false;
                    else if (newBoard[i][j] != newBoard[x][y]) isSame = false;
                }
                if (isSame) {
                    isContinue = true;
                    for(int k = 0; k < 4; k++) {
                        int x = i + dx[k], y = j + dy[k];
                        if (x >= n or y >= m) continue;
                        if (!vis[x][y]) {
                            answer++;
                            vis[x][y] = 1;
                        }
                    }
                }

            }
        }
        newBoard = rearrangement(n, m, newBoard);
        if (!isContinue) break;
        else isContinue = false;
    }
    return answer;
}
