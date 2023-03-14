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

// 지점의 개수 n
// 출발지점 s
// A의 도착지점 a
// B의 도착지점 b

vector<pii> v[200];
int dis[200][200]; // dis[i] 어딘가까지 같이 감

void go(int s) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s}); //s
    dis[s][s] = 0;
    while (!pq.empty()) {
        int cur = pq.top().second, cost = pq.top().first; pq.pop();
        if (dis[s][cur] < cost) continue;
        for(pii i : v[cur]) {
            if (dis[s][i.first] <= i.second + dis[s][cur]) continue;
            dis[s][i.first] = i.second + dis[s][cur];
            pq.push({i.second, i.first});
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1e9; s--; a--; b--;
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 0; i < fares.size(); i++) {
        int st = fares[i][0], en = fares[i][1], c = fares[i][2];
        st--;
        en--;
        v[st].push_back({en, c});
        v[en].push_back({st, c});
    }
    for(int i = 0; i < n; i++) {
//        printf("%d ============\n", i+1);

        go(i);
    }
    for(int i = 0; i < n; i++) {
        if(dis[s][i] == 1061109567 or dis[i][a] == 1061109567 or dis[i][b] == 1061109567) continue;
        printf("%d %d %d\n", dis[s][i], dis[i][a], dis[i][b]);

        answer = min(answer, dis[s][i] + dis[i][a] + dis[i][b]);
    }
    return answer;
}
