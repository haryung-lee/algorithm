#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
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

map<string, int> st;
set<string> store;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {1, 1000000};
    int le = 0, ri = 0;
    for(int i = 0; i < gems.size(); i++) store.insert(gems[i]);
    while(ri < gems.size()) {
//        for(auto s : st) cout << s.first << " : " << s.second << endl;
//        printf("=========\n");
        if (st.size() == store.size()) {
            if (answer[1] - answer[0] > ri - le - 1) {
                answer[1] = ri, answer[0] = le + 1;
            }
            st[gems[le++]]--; st[gems[ri++]]++;
        } else {
            st[gems[ri++]]++;
            if (st[gems[le]] > 1) {
                st[gems[le++]]--;
            }
        }
        while(store.size() == st.size()) {
            if (answer[1] - answer[0] > ri - le - 1) {
                answer[1] = ri, answer[0] = le + 1;
            }
            st[gems[le]]--;
            if (st[gems[le]] == 0) {
                st.erase(st.find(gems[le]));
            }
            le++;
        }
    }
    while(store.size() == st.size()) {
        if (answer[1] - answer[0] > ri - le - 1) {
            answer[1] = ri, answer[0] = le + 1;
        }
        st[gems[le]]--;
        if (st[gems[le]] == 0) {
            st.erase(st.find(gems[le]));
        }
        le++;
    }
    return answer;
}
