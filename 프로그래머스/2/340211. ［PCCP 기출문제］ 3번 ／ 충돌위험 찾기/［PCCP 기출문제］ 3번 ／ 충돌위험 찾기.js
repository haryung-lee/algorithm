// point는 {x, y} 형태
// point1에서 point2로 이동시켜야 함, 한번에 한 스텝만 이동
function move(point1, point2) {
    let s = point1;

    if (point1.x == point2.x) {
        if (point1.y == point2.y) {
            return point1;
        }
        return {x: point1.x, y: point2.y - point1.y > 0 ? point1.y+1 : point1.y-1};
    }
    return {x: point2.x - point1.x > 0 ? point1.x+1 : point1.x-1, y: point1.y};
}

let robot = [];
let point = [];
let now = []; // 로봇별 현재 위치
let ix = [];
let mxIdx = 0;
const mp = new Map();
let ans = 0;

function go() {
    // 로봇별 가야하는 현재 idx
    ix.length = now.length;
    ix.fill(0);
    mxIdx = robot[0].length;
    console.log(mxIdx);
    
    // 로봇별로 이동을 할 것.
    while(true) {
        let isAllFin = true;
        mp.clear();
        for(let i = 0; i < now.length; i++) {
            let nxtNum = (ix[i]+1 == mxIdx) ? robot[i][ix[i]] : robot[i][ix[i]+1];
            const nxt = move(now[i], {x: point[nxtNum-1][0]-1, y: point[nxtNum-1][1]-1});

            
            if (JSON.stringify(nxt) == JSON.stringify(now[i]) && ix[i]+1 == mxIdx) {
                continue;
            }
            
            if (mp.get(JSON.stringify(nxt)) == 1) {
                ans++;
                mp.set(JSON.stringify(nxt), 2);
            } else if (mp.get(JSON.stringify(nxt)) == undefined) {
                mp.set(JSON.stringify(nxt), 1);
            }
            if (JSON.stringify(nxt) == JSON.stringify({x: point[nxtNum-1][0]-1, y: point[nxtNum-1][1]-1})) {
                ix[i] += 1;
            } else {
            }
            now[i] = nxt;
            isAllFin = false;
        }
        
        if (isAllFin) break;
    }
    
}


function solution(points, routes) {
    robot = routes;
    point = points;
    
    // 모든 로봇들 초기값
    for(let i = 0; i < routes.length; i++) {
        now.push({
            x: points[routes[i][0]-1][0]-1,
            y: points[routes[i][0]-1][1]-1
        });
        if (mp.get(JSON.stringify(now[now.length -1])) == undefined) {
            mp.set(JSON.stringify(now[now.length -1]), 1);
        } else if (mp.get(JSON.stringify(now[now.length -1])) == 1){
            ans++;
            mp.set(JSON.stringify(now[now.length -1]), 2);
        }
    }
    
    go();
    
    return ans;
}
