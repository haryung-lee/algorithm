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

int n;
vector<ll> v;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        ll tmp;
        scanf("%lld", &tmp);
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    ll tmp = 0;
    for(int i = 0; i < v.size() - 1; i++) {
        tmp += v[i];
    }


    if (tmp >= v[v.size()-1]) printf("%d", (tmp+v[v.size()-1])%2);
    else printf("%lld", v[v.size()-1] - tmp);
}