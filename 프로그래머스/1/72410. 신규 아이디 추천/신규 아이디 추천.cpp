#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    int prev = 0;
    for(int i = 0; i < new_id.length(); i++) {
        // 1. 소문자로 변경
        if (new_id[i] >= 'A' and new_id[i] <= 'Z') new_id[i] += 32;
        
        // 2. 이상한 문자열 없앰
        // 3. 마침표 두번 이상 연속이면 하나로
        // 4. 마침표 처음이나 끝에 위치하면 제거
        if (new_id[i] >= 'a' and new_id[i] <= 'z') continue;
        if (new_id[i] >= '0' and new_id[i] <= '9') continue;
        else if (new_id[i] == '-' or new_id[i] == '_') continue;
        else if (new_id[i] == '.') {
            if (i == 0) {
                new_id = new_id.substr(1, new_id.length());
                i--;
            } else if (i == new_id.length() - 1) {
                new_id = new_id.substr(0, new_id.length() - 1);
            } else {
                if (new_id[i-1] == '.') {
                    new_id = new_id.substr(0, i) + new_id.substr(i+1, new_id.length());
                    i--;
                }
            }
        }
        else {
            new_id = new_id.substr(0, i) + new_id.substr(i+1, new_id.length());
            i--;
            continue;
        }
    }
    
    
    if (new_id == "") new_id = "a";
    if (new_id.length() >= 16) new_id = new_id.substr(0, 15);
    if (new_id[new_id.length() - 1] == '.') new_id = new_id.substr(0, new_id.length() - 1);
    
    if (new_id.length() <= 2) {
        while(new_id.length() != 3) {
            new_id += new_id[new_id.length() - 1];
        }
    }
    
    return new_id;
}