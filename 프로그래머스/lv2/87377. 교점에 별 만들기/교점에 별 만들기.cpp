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
typedef pair<ll, ll> pll;
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;

// 교점을 찾기

vector<string> solution(vector<vector<int>> line) {
    pll mx = {-1e12, -1e12}, mn = {1e12, 1e12};
    vector<pll> lst;
    for(int i = 0; i < line.size(); i++) {
        for(int j = i + 1; j < line.size(); j++) {
            ll a = line[i][0], b = line[i][1], e = line[i][2];
            ll c = line[j][0], d = line[j][1], f = line[j][2];
            if (a*d == b*c) continue; // 교점 없음

            pll t;
            if ((((b*f - e*d) % (a*d-b*c)) == 0) and (((e*c-a*f)%(a*d-b*c)) == 0)) {
                t = {(b*f-e*d)/(a*d-b*c), (e*c-a*f)/(a*d-b*c)};
                lst.push_back(t);
                mx = {max(mx.first, t.first), max(mx.second, t.second)};
                mn = {min(mn.first, t.first), min(mn.second, t.second)};
            }
        }
    }
    vector<string> answer;
    if (lst.size()) {
        for(int i = 0; i <= mx.second - mn.second; i++) {
            answer.push_back("");
            for(int j = 0; j <= mx.first - mn.first; j++) {
                answer[i] += '.';
            }
        }
        for(pll i : lst) {
            answer[(mx.second-mn.second) - (i.second - mn.second)][i.first - mn.first] = '*';
        }
    }
    return answer;
}
