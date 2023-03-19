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

int n, m;
int trie[10000 * 500 + 1][26]; // [최대 문자열 개수 * 최대 길이 + 1][알파벳 소문자]
char s[501];
int num = 1;

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%s", s);

        int now = 0;
        for (int j = 0; s[j]; j++) { // 문자열 s만큼
            char t = s[j] - 'a';
            if (trie[now][t] == 0) trie[now][t] = num++;
            now = trie[now][t];
        }
    }

    int ans = 0;
    for(int i = 0; i < m; i++) {
        scanf("%s", s);

        int now = 0, isFind = 1;
        for(int j = 0; s[j]; j++) {
            char t = s[j] - 'a';
            if (trie[now][t] == 0) {
                isFind = 0;
                break;
            }
            now = trie[now][t];
        }
        ans += isFind;
    }
    printf("%d", ans);

}