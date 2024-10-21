const dir = {
    "N": {x: -1, y: 0},
    "E": {x: 0, y: 1},
    "S": {x: 1, y: 0},
    "W": {x: 0, y: -1},
}

function solution(park, routes) {
    var answer = [];
    let arr = [];
    let s = {x: 0, y: 0};
    let mx = {x: park.length, y: park[0].length};
    arr.length = park.length;
    
    for(let i = 0; i < arr.length; i++) {
        arr[i] = new Array(park[i].length)
    }
    
    for(let i = 0; i < arr.length; i++) {
        for(let j = 0; j < arr[i].length; j++) {
            arr[i][j] = park[i][j];
            if (arr[i][j] == 'S') {
                s.x = i, s.y = j;
            }
        }
    }
    
    for(let i = 0; i < routes.length; i++) {
        const [op, n] = routes[i].split(' ');
        let canGo = true;
        let x = s.x, y = s.y;
        
        for(let j = 0; j < n; j++) {
            x += dir[op].x, y += dir[op].y;
            if (x < 0 || y < 0 || x >= mx.x || y >= mx.y) {
                canGo = false;
                break;
            }
            if (arr[x][y] == 'X') {
                canGo = false;
                break;
            }
        }
        
        if (canGo) {
            s.x = x, s.y = y;
        }
    }
    return [s.x, s.y];
}