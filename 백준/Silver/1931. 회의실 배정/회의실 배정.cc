#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#define MOD 10007
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<ll, ll> pll;

pll arr[100001];
ll tmp;
int n, ans = 0;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        arr[i].first = b; // end
        arr[i].second = a; // start
    }
    sort(arr, arr + n);
    tmp = arr[0].second;
    for(int i = 0; i < n; i++) {
        if (arr[i].second >= tmp) {
            tmp = arr[i].first;
            ans++;
        }
    }
    printf("%d", ans);
}