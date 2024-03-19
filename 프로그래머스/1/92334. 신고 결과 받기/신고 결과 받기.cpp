#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef long long ll;
int dy[] = {0, 1, 0, -1}, dx[] = {-1, 0, 1, 0};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;

multimap<string, string> mmp; // 각 id가 신고한 id들
set<string> st;
map<string, int> rp; // 각 id별로 받은 신고 횟수

pair<string, string> getUsers(string s) {
    stringstream ss(s);
    string first, second;
    getline(ss, first, ' ');
    getline(ss, second, ' ');

    return {first, second};
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    for(int i = 0; i < report.size(); i++) {
        if(st.find(report[i]) != st.end()) continue;
        st.insert(report[i]);
        auto ps = getUsers(report[i]);
        mmp.insert({ps.first, ps.second});
        if (rp.find(ps.second) == rp.end()) rp[ps.second] = 1;
        else rp[ps.second]++;
    }

    vector<int> answer;

    for(int i = 0; i < id_list.size(); i++) {
        int ans = 0;

        for(auto iter = mmp.lower_bound(id_list[i]); iter != mmp.upper_bound(id_list[i]); iter++) {
            string tmp = iter->second;
            if(rp[tmp] >= k) ans++;
        }

        answer.push_back(ans);
    }

    return answer;
}