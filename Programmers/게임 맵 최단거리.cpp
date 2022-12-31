#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int dy[] = {0, 1, 0, -1}, dx[] = {-1, 0, 1, 0};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, int> pai;

int solution(vector<vector<int> > maps)
{
    int answer = 1e9;
    int n = maps.size(), m = maps[0].size();
    int vis[n][m];
    memset(vis, 0, sizeof(vis));

    queue<pai> q;
    q.push({{0, 0}, 0});

    while (!q.empty()) {
        pai t = q.front(); q.pop();
        if (t.first.x == n-1 and t.first.y == m-1) answer = min(answer, t.second);
        for(int i = 0; i < 4; i++) {
            int x = t.first.x + dx[i], y = t.first.y + dy[i];
            if (x < 0 or y < 0 or x >= n or y >= m) continue;
            if (!maps[x][y] or vis[x][y]) continue;
            vis[x][y] = 1;
            q.push({{x, y}, t.second + 1});
        }
    }

    return answer == 1e9 ? -1 : answer + 1;
}