#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, t, ans = 0;
priority_queue<int> pq;

int main() {
    scanf("%d", &n);
    for(int a, i = 0; i < n; i++) {
        scanf("%d", &a);
        if (i == 0) t = a;
        else {
            a -= t;
            if (a >= 0) pq.push(a);
        }
    }
    while (1) {
        int flag = 0;
        if (!pq.empty() and pq.top() >= ans) {
            flag = 1;
            int tmp = pq.top(); tmp--;
            pq.pop();
            pq.push(tmp);
        }
        if (!flag) break;
        ans++;
    }
    printf("%d", ans);
}