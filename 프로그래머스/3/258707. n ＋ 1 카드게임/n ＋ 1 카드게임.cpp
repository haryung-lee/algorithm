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

struct card {
    int en, enIdx, cnt;
};

bool compare(const card &a, const card &b) {
    return a.enIdx < b.enIdx;
};


int cardIdx[1001];
int n, stat = 0;
set<int> st;
vector<card> v;

int solution(int coin, vector<int> cards) {
    n = cards.size();
    int round = 1;

    for(int i = 0; i < cards.size(); i++) {
        if (i < n / 3) {
            st.insert(cards[i]);
        }
        cardIdx[cards[i]] = i;
    }

    for(int i = 0; i < cards.size(); i++) {
        int pair = n + 1 - cards[i];

        if (cardIdx[cards[i]] < cardIdx[pair]) continue;

        int cnt = st.find(cards[i]) != st.end() && st.find(pair) != st.end() ? 0 :
                st.find(pair) != st.end() ? 1 : 2;

        if (cnt == 0) {
            stat++;
        } else {
            v.push_back({
                en: cards[i],
                enIdx: cardIdx[cards[i]],
                cnt: cnt,
            });
        }
    }

    sort(v.begin(), v.end(), compare);

    int idx = 0, twoCnt = 0;


    // 실제 게임을 할 때
    for(int i = n/3; i < cards.size(); i += 2) {
        int a = cards[i], b = cards[i+1];



        // 만약, v에 있는게 해당 턴에 있다면
        if (a == v[idx].en) {
            printf("v : %d %d\n", v[idx].en, v[idx].cnt);
            if (v[idx].cnt == 1) {
                if (coin > 0) {
                    coin--;
                    stat++;
                }
            } else {
                twoCnt++;
            }
            idx++;
        }

        if (b == v[idx].en) {
            if (v[idx].cnt == 1) {
                if (coin > 0) {
                    coin--;
                    stat++;
                }
            } else {
                twoCnt++;
            }
            idx++;
        }

        if (stat > 0) {
           stat--;
        } else {
            if (coin >= 2 && twoCnt > 0) {
                twoCnt--;
                coin -= 2;
            } else {
                break;
            }
        }
        round++;

    }

    return round + stat;
}