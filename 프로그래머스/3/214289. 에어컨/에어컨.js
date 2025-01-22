// dp[시간][현재온도]

let temp, T1, T2, A, B, onb;
const MAX = 1000000000;

const dp = Array.from({ length: 1000 }, () =>
  Array(51).fill(-1));


function go(ix, curTemp) {
    if (ix == onb.length) return 0;
    if (curTemp < 0 || curTemp > 50) {
        return MAX;
    }
    if (onb[ix] && (curTemp < T1 || curTemp > T2)) return MAX;
    if (dp[ix][curTemp] !== -1) return dp[ix][curTemp];
    
    let ret = MAX;
    
    
    // 에어컨 전원 킴
    ret = Math.min(ret, go(ix + 1, curTemp + 1) + A);
    ret = Math.min(ret, go(ix + 1, curTemp - 1) + A);
    ret = Math.min(ret, go(ix + 1, curTemp) + B);
    
    // 에어컨 전원 끔
    if (curTemp === temp) ret = Math.min(ret, go(ix + 1, curTemp));
    else ret = Math.min(ret, go(ix + 1, curTemp + ((temp > curTemp) ? 1 : -1)));
    
    return dp[ix][curTemp] = ret;
}

function solution(temperature, t1, t2, a, b, onboard) {

    temp = temperature + 10;
    T1 = t1 + 10;
    T2 = t2 + 10;
    A = a, B = b, onb = onboard;
    
    
    return go(0, temp);
}