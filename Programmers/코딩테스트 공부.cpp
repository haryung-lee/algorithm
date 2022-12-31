#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int dp[151][151];
pii req[101];
pii rwd[101];
int cost[101];
pii mx = {0 ,0};
int problemSize;

int DP(int alp, int cop) {
    if (alp >= mx.first and cop >= mx.second) {
        return 0;
    }
    if (dp[alp][cop] != -1) return dp[alp][cop];

    int ret = 1e9;
    for(int i = 0; i < problemSize; i++) {
        int sum = 0;
        if (req[i].first > alp) sum += req[i].first - alp;
        if (req[i].second > cop) sum += req[i].second - cop;
        if (sum > 0) {
            ret = min(ret, DP(min(150, max(alp, req[i].first)), min(150, max(cop, req[i].second))) + sum);
        }
        else {
            if (min(150, alp + rwd[i].first) == alp and min(150, cop + rwd[i].second) == cop) continue;
            ret = min(ret, DP(min(150, alp + rwd[i].first), min(150, cop + rwd[i].second)) + cost[i]);
        }
    }

    return dp[alp][cop] = ret;
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    memset(dp, -1 ,sizeof(dp));
    problemSize = problems.size();
    for(int i = 0; i < problemSize; i++) {
        req[i] = {problems[i][0], problems[i][1]};
        rwd[i] = {problems[i][2], problems[i][3]};
        cost[i] = problems[i][4];
        mx = {max(mx.first, req[i].first), max(mx.second, req[i].second)};
    }
    return DP(alp, cop);
}
