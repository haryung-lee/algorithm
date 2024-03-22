#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
int dy[] = {0, 1, 0, -1}, dx[] = {-1, 0, 1, 1};
struct axis {int x, y;};

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size() - 1; i++) {
        string tmp = phone_book[i+1].substr(0, phone_book[i].length());
        if(phone_book[i] == tmp) return false;
    }
    return answer;
}