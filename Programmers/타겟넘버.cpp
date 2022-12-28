#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef long long ll;
int dy[] = {0, 1, 0, -1}, dx[] = {-1, 0, 1, 0};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;

int dp[20][2001];

int sol(vector<int> numbers, int idx, int sum, int target) {
    if (idx == -1) {
        if (sum == 0) return 1;
        return 0;
    }
    if (dp[idx][sum + 1000] != -1) return dp[idx][sum + 1000];
    int ret = sol(numbers, idx - 1, sum - numbers[idx], target) + sol(numbers, idx - 1, sum + numbers[idx], target);
    return dp[idx][sum + 1000] = ret;
}

int solution(vector<int> numbers, int target) {
    memset(dp, -1, sizeof(dp));
    return sol(numbers, numbers.size() - 1, target, target);
}

int main() {
    vector<int> numbers = {4, 1, 2, 1};
    int target = 4;
    solution(numbers, target);

    return 0;
}
