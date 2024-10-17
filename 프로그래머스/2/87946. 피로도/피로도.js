const arr = [];
const vis = [];
let K, dun, ans = 0;


function go() {
    if (arr.length == dun.length) {
        let init = K;
        let cnt = 0;
        for(let i = 0; i < arr.length; i++) {
            if (arr[i][0] > init) {
                break;
            }
            init -= arr[i][1];
            cnt++;
        }
        
        ans = Math.max(ans, cnt);
        return 0;
    }
    
    for(let i = 0; i < dun.length; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        arr.push(dun[i]);
        go();
        vis[i] = 0;
        arr.pop();
    }
  
}

function solution(k, dungeons) {
    K = k;
    dun = dungeons;
    vis.length = dun.length;
    vis.fill(0);
    
    go();

    return ans;
}