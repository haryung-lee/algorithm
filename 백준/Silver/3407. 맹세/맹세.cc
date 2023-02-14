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

int tc;
string s;
int dp[50000];
set<char> st1 = {
        'h', 'b', 'c', 'n', 'o', 'f', 'p', 's', 'k', 'v', 'y', 'i', 'w', 'u', ' '
};
set<string> st2 = {
        "ba", "ca", "ga", "la", "na", "pa", "ra", "ta", "db", "nb", "pb", "rb", "sb", "tb", "yb", "ac",
        "sc", "tc", "cd", "gd", "md", "nd", "pd", "be", "ce", "fe", "ge", "he", "ne", "re", "se", "te",
        "xe", "cf", "hf", "rf", "ag", "hg", "mg", "rg", "sg", "bh", "rh", "th", "bi", "li", "ni", "si",
        "ti", "bk", "al", "cl", "fl", "tl", "am", "cm", "fm", "pm", "sm", "tm", "cn", "in", "mn", "rn",
        "sn", "zn", "co", "ho", "mo", "no", "po", "np", "ar", "br", "cr", "er", "fr", "ir", "kr", "lr",
        "pr", "sr", "zr", "as", "cs", "ds", "es", "hs", "os", "at", "mt", "pt", "au", "cu", "eu", "lu",
        "pu", "ru", "lv", "dy"
};

void getLower() {
    for(int i = 0; i < s.size(); i++) {
        s[i] = tolower(s[i]);
    }
}

int go(int ix) {
    if (ix == s.size()) {
        return 1;
    }
    if (dp[ix] != -1) return dp[ix];
    int ret = 0;
    if (st1.find(s[ix]) != st1.end()) {
        ret = max(ret, go(ix + 1));
    }
    if (ix + 1 < s.size()) {
        string a = ""; a += char(s[ix]), a += char(s[ix+1]);
        if (st2.find(a) != st2.end()) {
            ret = max(ret, go(ix + 2));
        }
    }

    return dp[ix] = ret;
}

int main() {
    scanf("%d", &tc);
    while(tc--) {
        cin >> s;
        getLower();
        memset(dp, -1, sizeof(dp));
        if (go(0)) printf("YES\n");
        else printf("NO\n");
    }
}