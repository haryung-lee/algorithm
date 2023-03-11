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

ll go(ll n) {
    ll sum = 0, t = 1, count = 0, tmp = n;
    while(tmp & 1) {
        sum += t;
        t *= 2;
        tmp >>= 1;
        count++;
    }
    if (count == 0) return n + (1LL << count);
    return n + (1LL << count) - (1LL << (count-1));

}

vector<ll> solution(vector<ll> numbers) {
    vector<ll> answer;
    for(ll n : numbers) {
        answer.push_back(go(n));
    }
    return answer;
}
