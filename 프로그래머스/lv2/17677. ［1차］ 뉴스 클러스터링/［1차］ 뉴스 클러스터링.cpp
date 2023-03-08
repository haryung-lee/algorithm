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

map<string, int> mp1, mp2;
string s = "";

bool chk(char a) {
    if (a >= 'a' and a <= 'z') return true;
    if (a >= 'A' and a <= 'Z') return true;
    return false;
}

char toLower(char a) {
    if ('A' <= a and 'Z' >= a) a += 32;
    return char(a);
}

int solution(string str1, string str2) {
    int hap = 0, gyo = 0;
    for(int i = 0; i < str1.size(); i++) {
        if ('A' <= str1[i] and str1[i] <= 'Z') str1[i] += 32;
    }
    for(int i = 0; i < str2.size(); i++) {
        if ('A' <= str2[i] and str2[i] <= 'Z') str2[i] += 32;
    }

    for(int i = 0; i < str1.size()-1; i++) {
        if (!chk(str1[i]) or !chk(str1[i+1])) continue;
        s = ""; s += str1[i]; s += str1[i+1];
        mp1[s]++;
    }
    for(int i = 0; i < str2.size()-1; i++) {
        if (!chk(str2[i]) or !chk(str2[i+1])) continue;
        s = ""; s += str2[i]; s += str2[i+1];
        mp2[s]++;
    }
    for(auto i : mp1) {
        if (mp2.find(i.first) != mp2.end()) {
            gyo += min(mp2[i.first], mp1[i.first]);
            hap += max(mp2[i.first], mp1[i.first]);
        } else {
            hap += mp1[i.first];
        }
    }

    for(auto i : mp2) {
        if (mp1.find(i.first) == mp1.end()) hap += mp2[i.first];
    }

    printf("%d %d\n", gyo, hap);
    return gyo == 0 and hap == 0 ? 65536 : floor(double(double(gyo) / hap) * 65536);
}
