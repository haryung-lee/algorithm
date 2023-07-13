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

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<int> q1, q2;
    ll one = 0, two = 0, mx = 0;
    for(int i : queue1) {
        q1.push(i);
        one += i;
        mx = max(mx, ll(i));
    }
    for(int i : queue2) {
        q2.push(i);
        two += i;
        mx = max(mx, ll(i));
    }

    if ((one+two) % 2) return -1;
    if (mx > (one + two) / 2) return -1;

    while(1) {
        if (one == two) break;
        if (answer >= 600000) {
            answer = -1;
            break;
        }        if (q1.empty() or q2.empty()) {
            answer = -1;
            break;
        }
        if (one < two) {
            int tmp = q2.front(); q2.pop();
            one += tmp; two -= tmp;
            q1.push(tmp);
            answer++;
        } else if (one > two) {
            int tmp = q1.front(); q1.pop();
            one -= tmp; two += tmp;
            q2.push(tmp);
            answer++;
        }
    }

    return answer;
}
