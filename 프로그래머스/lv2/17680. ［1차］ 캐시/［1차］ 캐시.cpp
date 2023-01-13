#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

list<string> lst = {};

string getLower(string a) {
    string ret = "";
    for(char c : a) ret += tolower(c);
    return ret;
}

bool findCity(string a) {
    for(string s : lst) {
        if (s == a) return true;
    }
    return false;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    for(int i = 0; i < cities.size(); i++) {
        string lowerCity = "";
        for(int j = 0; j < cities[i].size(); j++) lowerCity += tolower(cities[i][j]);
        
        if (findCity(lowerCity)) {
            lst.remove(lowerCity);
            answer += 1;
        } else {
            answer += 5;
        }
        lst.push_back(lowerCity);
        if (lst.size() > cacheSize) lst.pop_front();
    }
    return answer;
}