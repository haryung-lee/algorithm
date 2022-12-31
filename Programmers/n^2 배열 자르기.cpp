#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(ll i = left; i <= right; i++) {
        ll a = i / n;
        ll b = i % n;
        answer.push_back(max(a, b) + 1);
    }
    return answer;
}