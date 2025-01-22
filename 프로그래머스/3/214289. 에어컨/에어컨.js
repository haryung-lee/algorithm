// dp[시간][현재온도][희망온도][에어컨 틀어진 여부]

let temp, T1, T2, A, B, onb;
const MAX = 1000000000;

const dp = Array.from({ length: 1000 }, () =>
  Array.from({ length: 51 }, () => Array(52).fill(-1)));


function go(ix, curTemp, desiredTemp) {
    if (ix == onb.length) return 0;
    if (curTemp < 0 || curTemp > 50 || desiredTemp < 0 || desiredTemp > 51) {
        return MAX;
    }
    if (onb[ix] && (curTemp < T1 || curTemp > T2)) return MAX;
    if (dp[ix][curTemp][desiredTemp] !== -1) return dp[ix][curTemp][desiredTemp];
    
    let ret = MAX;
    
    if (desiredTemp !== T2+1) { // 에어컨이 켜져있다면
        if (curTemp === desiredTemp) {
            ret = Math.min(go(ix + 1, curTemp, desiredTemp), go(ix + 1, curTemp, T2+1)) + B;
        } else {
            ret = Math.min(go(ix + 1, curTemp + (desiredTemp > curTemp ? 1 : -1), desiredTemp), go(ix + 1, curTemp + (desiredTemp > curTemp ? 1 : -1), T2+1)) + A;
        }
    } else { // 에어컨이 꺼져있다면 
        if (curTemp === temp) {
            for(let i = T1; i <= T2 + 1; i++) {
                ret = Math.min(ret, go(ix + 1, curTemp, i));
            }
        } else {
            for(let i = T1; i <= T2 + 1; i++) {
                ret = Math.min(ret, go(ix + 1, curTemp + (temp > curTemp ? 1 : -1), i));
            }
        }
    }
    
    return dp[ix][curTemp][desiredTemp] = ret;
}

function solution(temperature, t1, t2, a, b, onboard) {

    temp = temperature + 10;
    T1 = t1 + 10;
    T2 = t2 + 10;
    A = a, B = b, onb = onboard;
    
    let ans = 1000000000;
    for(let i = T1; i <= T2 + 1; i++) {
        ans = Math.min(ans, go(0, temp, i));
    }
    
    return ans;
}