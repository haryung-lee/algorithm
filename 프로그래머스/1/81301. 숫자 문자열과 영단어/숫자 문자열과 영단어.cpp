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

pair<string, int> word[] = {{"ze", 4}, {"on", 3}, {"tw", 3}, {"th", 5}, {"fo", 4}, {"fi", 4}, {"si", 3}, {"se", 5}, {"ei", 5}, {"ni", 4}};

int solution(string s) {
    string ans = "";
    int answer = 0;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' and s[i] <= '9') ans += s[i];
        else {
            string tmp = s.substr(i, 2);
            for (int j = 0; j < 10; j++) {
                if (word[j].first == tmp) {
                    ans += to_string(j);
                    i += word[j].second - 1;
                    break;
                }
            }
        }
    }
    ll tmp = 1;
    for(int i = ans.size() - 1; i >= 0; i--) {
        answer += int(ans[i] - '0') * tmp;
        tmp *= 10;
    }
    return answer;
}
