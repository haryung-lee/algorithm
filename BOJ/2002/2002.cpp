#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> flowers) {
    int answer = 0;
    int arr[366] = {0,};
    for(int i=0; i<flowers.size(); i++){
        for(int j=flowers[i][0]; j<flowers[i][1]; j++){
            arr[j]++;
        }
    }
    for(int i = 1; i < 366; i++) {
        if (arr[i]) answer++;
    }
    return answer;
}

int main() {
    vector<vector<int>> flowers = {{1, 365}};
    printf("%d", solution(flowers));
}