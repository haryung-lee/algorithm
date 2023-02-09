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

vector<pii> v;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0, st = 1, en;
    for(int i : stations) {
        en = i - w - 1;
        if (en > n) en = n;
        if (en >= st) {
            answer += ((en - st + 1) / (2*w + 1));
            answer += (((en - st + 1) % (2*w + 1)) ? 1 : 0);
        }
        st = i + w + 1;
    }

    if (en != n) {
            en = n;
            if (en >= st) {
                answer += ((en - st + 1) / (2*w + 1));
                answer += (((en - st + 1) % (2*w + 1)) ? 1 : 0);
            }


    }

    return answer;
}