#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <deque>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef long long ll;
int dy[] = {0, 1, 0, -1}, dx[] = {-1, 0, 1, 0};
struct axis { int x, y; };
typedef pair<string, int> psi;
typedef pair<axis, psi> pas;


string s;
stack<string> st;

int main() {
    string ctos = "";

    cin >> s;
    ll ans = 0;
    for(int i = 0; i < s.size(); i++) {

        if (s[i] == '(' or s[i] == '[') st.push(ctos + s[i]);
       else if (s[i] == ')') {
           ll tmp = 1;
           while(!st.empty() and st.top() != "(") {
               string tp = st.top(); st.pop();
               if (tp == "[") { // 잘못된 문자열
                   printf("0");
                   return 0;
               }

               ll t = stoll(tp);
               tmp *= t;
           }
           if (st.empty()) {
               printf("0");
               return 0;
           }
           st.pop();
           tmp *= 2;

           while(!st.empty() and st.top() != "(" and st.top() != "[") {
               string tp = st.top(); st.pop();
               ll t = stoll(tp);
               tmp += t;
           }
           st.push(to_string(tmp));
       } else {
           ll tmp = 1;
           while(!st.empty() and st.top() != "[") {
               string tp = st.top(); st.pop();
               if (tp == "(") {
                   printf("0");
                   return 0;
               }

               ll t = stoll(tp);
               tmp *= t;
           }
           if (st.empty()) {
               printf("0");
               return 0;
           }
           st.pop();
           tmp *= 3;
           while(!st.empty() and st.top() != "(" and st.top() != "[") {
               string tp = st.top(); st.pop();
               ll t = stoll(tp);
               tmp += t;
           }

           st.push(to_string(tmp));
       }

    }

    while(!st.empty()) {
        string tp = st.top(); st.pop();
        if (tp == "(" or tp == "[") {
            printf("0");
            return 0;
        }
        ans += stoll(tp);
    }
    printf("%lld", ans);
}