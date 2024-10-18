const vis = new Array();
const arr = new Array();
let answer = 0, N, num;

function go(ix) {
    if (arr.length == 3) {
        let sm = 0;
        for(let i = 0; i < arr.length; i++) {
            sm += arr[i];
        }
        if (sm == 0) answer++;
        return;
    }
    
    for(let i = ix; i < N; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        arr.push(num[i]);
        go(i);
        vis[i] = 0;
        arr.pop();
    }
}

function solution(number) {
    vis.length = number.length;
    vis.fill(0);
    N = number.length;
    num = number;
    go(0);

    
    return answer;
}