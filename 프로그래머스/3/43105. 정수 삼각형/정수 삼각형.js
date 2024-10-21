// dp[i][j] = arr[i][j] + max(dp[i+1][j], dp[i+1][j+1])
let dp = [];
let tri;

function go(i, j) {
    if (i == dp.length - 1) {
        return tri[i][j];
    }
    
    if (dp[i][j] != -1) return dp[i][j];
    
    let ret = tri[i][j] + Math.max(go(i+1, j), go(i+1, j+1));
    
    return dp[i][j] = ret;
}

function solution(triangle) {
    var answer = 0;
    dp = triangle;
    
    for(let i = triangle.length - 2; i >= 0; i--) {
        for(let j = 0; j < triangle[i].length; j++) {
            dp[i][j] = dp[i][j] + Math.max(dp[i+1][j], dp[i+1][j+1]);
        }
    }

    return dp[0][0];
}