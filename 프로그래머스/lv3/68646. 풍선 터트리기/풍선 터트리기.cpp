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


int solution(vector<int> a) {
    vector<int> tmp = a;
    sort(tmp.begin(), tmp.end());
    int mn = tmp[0];

    int answer = 0;
    int leftMn = 1000000001, rightMn = 1000000001;
    vector<int> le, ri;

    int index = 0;
    while(a[index] != mn) {
        if (leftMn > a[index]) {
            answer++;
            leftMn = a[index];
        }
        index++;
    }

    index = a.size() - 1;
    while(a[index] != mn) {
        if (rightMn > a[index]) {
            answer++;
            rightMn = a[index];
        }
        index--;
    }
    
    return answer + 1;
}
