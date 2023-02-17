#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
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

set<string> store;
set<int> st;
int answer = 0;

bool isSameId(int ix, string bannedId, string userId) { //
    if (bannedId.size() != userId.size()) return false;
    for(int i = 0; i < bannedId.size(); i++) {
        if (bannedId[i] == '*') continue;
        if (bannedId[i] != userId[i]) return false;
    }
    return (st.find(ix) == st.end());
}

void go(int ix, vector<string> bannedId, vector<string> userId) {
    if (st.size() == bannedId.size()) {
        string tmp = "";
        for(int i : st) tmp += char(i);
        sort(tmp.begin(), tmp.end());
        if (store.find(tmp) == store.end()) {
            answer++;
            store.insert(tmp);
        }
    } else {
        for(int i = 0; i < userId.size(); i++) {
            // bannedId[ix]와 같은(*빼고) 아이디를 갖고 있는 사람을 찾아야 함
            // 단, tmp에 있는 사람이면 안됨.
            if (isSameId(i, bannedId[ix], userId[i])) {
                st.insert(i);
                go(ix + 1, bannedId, userId);
                st.erase(st.find(i));
            }
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    go(0,  banned_id, user_id);
    return answer;
}
