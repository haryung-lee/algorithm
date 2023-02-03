#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <sstream>
#include <deque>
#include <set>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef long long ll;
int dy[] = {0, 1, 0, -1}, dx[] = {-1, 0, 1, 0};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(A.begin(), A.end(), greater<>());
    sort(B.begin(), B.end(), greater<>());

    int AIdx = 0, BIdx = 0;
    while (AIdx < A.size() and BIdx < B.size()) {
        while(B[BIdx] <= A[AIdx]) {
            AIdx++;
            if (AIdx == A.size()) break;
        }
        if (AIdx == A.size()) break;
        if (B[BIdx] > A[AIdx]) {
            answer++;
            BIdx++; AIdx++;
        }
    }

    return answer;
}
