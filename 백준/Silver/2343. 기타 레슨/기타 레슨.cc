#include <cstdio>
using namespace std;
typedef long long ll;

int n, m;
int le = 1, ri = 1000000000, mi, ans;
int arr[100000];


int chk() {
    int sum = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        if (arr[i] > mi) return 0;
        if (sum + arr[i] > mi) {
            cnt++; sum = arr[i];
        } else sum += arr[i];
    }
    if (sum) cnt++;
    return cnt <= m ? 1 : 0;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    while(le <= ri) {
        mi = (le + ri) / 2;
        if (chk()) {
            ans = mi;
            ri = mi - 1;
        } else le = mi + 1;
    }
    printf("%d", ans);
}