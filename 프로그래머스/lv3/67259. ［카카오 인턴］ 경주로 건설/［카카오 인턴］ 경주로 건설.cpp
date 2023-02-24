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
int dy[] = {0, 1, 0, -1}, dx[] = {-1, 0, 1, 0}; // 위, 오, 아래, 왼
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<int, axis> pia;
typedef pair<pia, int> piai;

struct compare {
    bool operator()(piai a, piai b) {
        if (a.first.first == b.first.first) {
            if (a.first.second.x == b.first.second.x) return a.first.second.y < b.first.second.y;
            return a.first.second.x < b.first.second.x;
        }
        return a.first.first < b.first.first;
    }
};

priority_queue<piai, vector<piai>, compare> pq;
int dis[25][25][4], n, m;

int solution(vector<vector<int>> board) {
    int answer = 1e9;
    n = board.size(), m = board[0].size();
    pq.push({{0, {0, 0}}, -1});
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < 4; k++) dis[i][j][k] = 1e9;
        }
    }
    for(int i = 0; i < 4; i++) dis[0][0][i] = 0;
    while (!pq.empty()) {
        piai t = pq.top();
        axis cur = pq.top().first.second;
        int dir = pq.top().second, cost = pq.top().first.first; pq.pop();
        for(int i = 0; i < 4; i++) {
            int x = cur.x + dx[i], y = cur.y + dy[i];
            if (x < 0 or y < 0 or x >= n or y >= m) continue;
            if (board[x][y] or dis[x][y][i] < cost) continue;
            int nextDis = ((dir == -1 or (dir == i % 2)) ? 100 : 600) + cost;
            if (nextDis <= dis[x][y][i]) {
                dis[x][y][i] = nextDis;
                pq.push({{nextDis, {x, y}}, i % 2});
            }
        }

    }
    for(int i = 0; i < 4; i++) answer = min(answer, dis[n-1][m-1][i]);
    return answer;
}