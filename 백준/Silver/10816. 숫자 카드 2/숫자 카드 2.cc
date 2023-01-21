#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int n, m, k, h[20000001];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        h[k + 10000000]++;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &k);
        printf("%d ", h[k + 10000000]);
    }
    return 0;
}