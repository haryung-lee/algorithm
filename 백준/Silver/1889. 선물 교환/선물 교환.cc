#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n;
int graph[200000]; // i를 지목한 사람 수
pii arr[200000]; // i가 지목한 pair
int vis[200000]; // 문제 있는 애들
queue<int> q;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        graph[a]++; // i가 a를 투표함
        graph[b]++; // i가 b를 투표함
        arr[i] = {a, b};
    }
    for(int i = 0; i < n; i++) {
        if (graph[i] < 2) {
            vis[i] = 1;
            q.push(i);
        }
    }

    while(!q.empty()) {
        int t = q.front(); q.pop();

        if (--graph[arr[t].first] < 2 and !vis[arr[t].first]) {
            q.push(arr[t].first);
            vis[arr[t].first] = 1;
        }
        if (--graph[arr[t].second] < 2 and !vis[arr[t].second]) {
            q.push(arr[t].second);
            vis[arr[t].second] = 1;
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if (vis[i]) cnt++;
    }

        printf("%d\n", n - cnt);
        for(int i = 0; i < n; i++) {
            if (vis[i]) continue;
            printf("%d ", i + 1);
        }
    
}