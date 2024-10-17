function createArray(dimensions, initialValue) {
    if (dimensions.length == 0) return initialValue;
    
    const n = dimensions[0];
    const restDimensions = dimensions.slice(1);
    
    const arr = new Array(n).fill(initialValue);
    
    for(let i = 0; i < n; i++) {
        arr[i] = createArray(restDimensions, initialValue);
    }
    
    return arr;
}

const MOD = 1000000007;
const dp = createArray([101, 100001], -1);
let mn, total;

function go(ix, cur) {
    if (ix == -1) {
        if (cur == 0) return 1;
        return 0;
    }
    
    if (dp[ix][cur] != -1) return dp[ix][cur];

    let ret = 0;
    
    if (cur >= mn[ix]) ret = (go(ix, cur - mn[ix]) + go(ix - 1, cur)) % MOD;
    else ret = go(ix - 1, cur) % MOD;
    
    return dp[ix][cur] = ret % MOD;
}

function solution(n, money) {
    var answer = 0;
    mn = money;
    total = n;
        
    return go(mn.length - 1, n);
}