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

int dp[100000];

int solution(vector<int> sticker)
{
    if (sticker.size() == 1) return sticker[0];
    int answer = 0;
    dp[0] = sticker[0];
    if (sticker.size() > 1) dp[1] = max(sticker[0], sticker[1]);

    for(int i = 2; i < sticker.size() - 1; i++) {
        dp[i] = max(dp[i-2] + sticker[i], dp[i-1]);
    }
    answer = dp[sticker.size() - 2];

    memset(dp, 0, sizeof(dp));
    if (sticker.size() > 1) dp[1] = sticker[1];
    if (sticker.size() > 2) dp[2] = max(sticker[1], sticker[2]);
    for(int i = 3; i < sticker.size(); i++) {
        dp[i] = max(dp[i-2] + sticker[i], dp[i-1]);
    }

    return max(answer, dp[sticker.size()-1]);
}