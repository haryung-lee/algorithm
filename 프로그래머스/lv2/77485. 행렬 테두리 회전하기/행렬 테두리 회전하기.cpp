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


vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer, tmp;
    vector<vector<int>> v(rows, vector<int>(columns));
    // 배열의 크기는 rows x columns
    int idx = 1;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            v[i][j] = idx++;
        }
    }

    for(int i = 0; i < queries.size(); i++) {
        int mn = 1e9;
        int x = queries[i][0] - 1, y = queries[i][1] - 1,
            xGap = queries[i][2] - queries[i][0], yGap = queries[i][3] - queries[i][1];
        tmp.clear();
        for(int j = 0; j < yGap; j++) {
            tmp.push_back(v[x][y++]);
        }
        for(int j = 0; j < xGap; j++) {
            tmp.push_back(v[x++][y]);
        }
        for(int j = 0; j < yGap; j++) {
            tmp.push_back(v[x][y--]);
        }
        for(int j = 0; j < xGap; j++) {
            tmp.push_back(v[x--][y]);
        }
        rotate(tmp.begin(), tmp.end() - 1, tmp.end()); // 오른쪽으로 한칸씩 이동
        idx = 0;
        for(int j = 0; j < yGap; j++) {
            mn = min(mn, tmp[idx]);
            v[x][y++] = tmp[idx++];
        }
        for(int j = 0; j < xGap; j++) {
            mn = min(mn, tmp[idx]);
            v[x++][y] = tmp[idx++];
        }
        for(int j = 0; j < yGap; j++) {
            mn = min(mn, tmp[idx]);
            v[x][y--] = tmp[idx++];
        }
        for(int j = 0; j < xGap; j++) {
            mn = min(mn, tmp[idx]);
            v[x--][y] = tmp[idx++];
        }
        answer.push_back(mn);

    }

    return answer;
}
