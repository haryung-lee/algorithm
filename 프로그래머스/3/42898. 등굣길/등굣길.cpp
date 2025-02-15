#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int road[100][100];
    
    // 0. 전체를 -1로 초기화
    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < 100; ++j)
            road[i][j] = -1;
    }
    
    // 1. 시작 지점을 1로 바꿈
    road[0][0] = 1;
    
    // 2. 물에 잠긴 지역 0으로 바꿈
    for(int i = 0; i < puddles.size(); ++i)
        road[puddles[i][0]-1][puddles[i][1]-1] = 0;
    
    // 3. 인덱스가 -1이면 더하지 않고, 물에 잠긴 지역은 변경X, 각 방법이 int범위를 초과할 수 있으므로 넣을 때마다 모듈러처리
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(road[i][j] == -1){
                if(i == 0 && j == 0)
                    continue;
                else if(i == 0)
                    road[i][j] = road[i][j-1] % 1000000007;
                else if(j == 0)
                    road[i][j] = road[i-1][j] % 1000000007;
                else
                    road[i][j] = (road[i][j-1] + road[i-1][j]) % 1000000007;
            }
        }
    }
    
    answer = road[m-1][n-1];
    return answer;
}

