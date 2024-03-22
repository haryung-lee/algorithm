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

int vis[200];
vector<int> v[200];

void go(int n) {
    queue<int> q;
    q.push(n);
    vis[n] = 1;

    while(!q.empty()) {
        int t = q.front(); q.pop();

        for(int i = 0; i < v[t].size(); i++) {
            if (vis[v[t][i]]) continue;
            vis[v[t][i]] = 1;
            q.push(v[t][i]);
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    memset(vis, 0, sizeof(vis));

    for(int i = 0; i < computers.size(); i++) {
       for(int j = 0; j < computers[0].size(); j++) {
           if (computers[i][j]) {
               v[i].push_back(j);
               v[j].push_back(i);
           }
       }
    }

    for(int i = 0; i < n; i++) {
        if (vis[i]) continue;
        answer++;
        go(i);
    }

    return answer;
}