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

vector<pii> v[50];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int dis[50];

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 0; i < road.size(); i++) {
        int a = road[i][0], b = road[i][1], c = road[i][2];
        a--; b--;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    pq.push({0, 0});
    dis[0] = 0;

    while(!pq.empty()) {
        int t = pq.top().second, cost = pq.top().first; pq.pop();
//        printf("t : %d, cost: %d\n", t+1, cost);
        if (dis[t] < cost) continue;
        for(pii i : v[t]) {
//            printf("next: %d\n", i.first + 1);
            if (dis[i.first] <= i.second + dis[t]) continue;
            dis[i.first] = i.second + dis[t];
            pq.push({i.second, i.first});
        }
    }

    for(int i = 0; i < N; i++) {
//        printf("%d\n", dis[i]);
        if (dis[i] <= K) answer++;
    }
    return answer;
}