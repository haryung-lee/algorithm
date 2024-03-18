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

char ch[8] = {'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N'};
map<char, axis> mp;

void init() {
    for(int i = 0; i < 8; i++) {
        mp.insert({ch[i], {i / 2, i % 2}});
    }
}

string solution(vector<string> survey, vector<int> choices) {
    init();
    int ans[4][2]; // 각 유형별로 몇점인지 기록
        memset(ans, 0, sizeof(ans));

    for(int i = 0; i < survey.size(); i++) {
        int ch = choices[i];
        int pk = 0;
        
        if (ch > 4) pk = 1;
        else if (ch == 4) continue;
        
        axis ad = mp[survey[i][pk]];
        
        if (ch == 2 or ch == 6) ans[ad.x][ad.y] += 2;
        else if (ch == 1 or ch == 7) ans[ad.x][ad.y] += 3;
        else ans[ad.x][ad.y]++;
    }
    
    string answer = "";
    for(int i = 0; i < 4; i++) {
        if (ans[i][0] < ans[i][1]) answer += ch[i * 2 + 1];
        else answer += ch[i * 2];
    }
    return answer;
}
