#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef long long ll;
int dy[] = {0, 1, 0, -1}, dx[] = {-1, 0, 1, 0};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;

queue<char> qSkill, qTree;

int idxSkill = 0;

bool isInSkill(string skill, char c) {
    for(int i = 0; i < skill.size(); i++) {
        if (skill[i] == c) return true;
    }
    return false;
}

int getIdx(string skill, char c) {
    for(int i = 0; i < skill.size(); i++) {
        if (skill[i] == c) return i;
    }
    return -1;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i = 0; i < skill_trees.size(); i++) {
        int isAnswer = 1;
        vector<int> v;
        for(int j = 0; j < skill_trees[i].size(); j++) {
            int idx = getIdx(skill, skill_trees[i][j]);
            if (idx == -1) continue;
            v.push_back(idx);
        }
        int pre = -1;
        for(int j = 0; j < v.size(); j++) {
//            printf("%d ", v[j]);
            if (v[j]-pre > 1) isAnswer = 0;
            pre = v[j];
        }
//        printf("\n");
        answer += isAnswer;
    }
    return answer;
}