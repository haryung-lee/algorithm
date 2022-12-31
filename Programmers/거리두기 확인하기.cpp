#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int dy[] = {0, 1, 0, -1}, dx[] = {-1, 0, 1, 0};
struct axis { int x, y; };

stack<axis> st;
char arr[5][5];
int vis[5][5];
int isRight = 1;

void dfs(axis a, int dis) {

    for(int i = 0; i < 4; i++) {
        int x = dx[i] + a.x, y = dy[i] + a.y;
        if (x < 0 or y < 0 or x >= 5 or y >= 5) continue;
        if (vis[x][y]) continue;
        vis[a.x][a.y] = 1;

        if (arr[x][y] == 'P' && dis < 2) {isRight = 0; return;}
        dfs({x, y}, dis + (arr[x][y] == 'X' ? 3 : 1));
        vis[a.x][a.y] = 0;
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i = 0; i < 5; i++) {
        isRight = 1;

        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                arr[j][k] = places[i][j][k];
                if (arr[j][k] == 'P') {
                    st.push({j, k});
                }
            }
        }
        while(!st.empty()) {
            memset(vis, 0, sizeof(vis));
            vis[st.top().x][st.top().y] = 1;
            dfs(st.top(), 0);
            st.pop();
        }

        answer.push_back(isRight);
    }
    return answer;
}
