#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <bitset>
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

string s = "";
int ans = 1;

void getBinary(ll n) {
    if (n / 2 != 0) {
        getBinary(n / 2);
    }
    s += to_string(n % 2);
}

int getSize(ll n) {
    int tmp = 2;
    while(1) {
        if (tmp - 1 >= n) return tmp - 1;
        tmp *= 2;
    }
}

// 가운데가 0인데 양옆에 노드가 0이 아닐경우
void go(int le, int ri) {
    if (le >= ri) {
        return;
    }

    int mi = (le + ri) / 2;
//    printf("le : %d, mi: %d, ri: %d\n", le, mi, ri);

    if (s[mi] == '0') {
        int tmp = (le + mi - 1)/2, tmp2 = (mi + 1 + ri ) / 2;
        if (tmp >= 0 and s[tmp] == '1') {
            ans = 0;
            return;
        }
        if (tmp2 >= 0 and s[tmp2] == '1') {
            ans = 0;
            return;
        }
    }
    go(le, mi - 1);
    go(mi + 1, ri);
}


vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(ll i : numbers) {
        getBinary(i);
        int sz = getSize(s.size());
        for(int i = s.size(); i < sz; i++) s = '0' + s;
//        cout << s << ' ' << sz << endl;
        go(0, s.size() - 1);
//        printf("\n");
        answer.push_back(ans);
        ans = 1;
        s = "";
    }
    return answer;
}
