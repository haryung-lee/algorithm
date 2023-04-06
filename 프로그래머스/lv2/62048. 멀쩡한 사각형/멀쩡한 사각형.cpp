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
ll gcd(ll a, ll b) {
    ll mod = a % b;

    while (mod > 0) {
        a = b;
        b = mod;
        mod = a % b;
    }
    return b;
}

long long solution(int w, int h) {
    ll g = gcd(w, h);
    return ll(w*ll(h)) - (w+h-g);
}
