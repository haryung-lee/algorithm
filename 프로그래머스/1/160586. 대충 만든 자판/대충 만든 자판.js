function solution(keymap, targets) {
    var answer = [];
    const map = {};
    
    for(let i = 0; i < keymap.length; i++) {
        for(let j = 0; j < keymap[i].length; j++) {
            if (keymap[i][j] in map) {
                map[keymap[i][j]] = Math.min(map[keymap[i][j]], j+1);
            } else {
                map[keymap[i][j]] = j+1;
            }
        }
    }
    
    for(let i = 0; i < targets.length; i++) {
        let targetSum = 0;
        for(let j = 0; j < targets[i].length; j++) {
            if (targets[i][j] in map) {
                targetSum += map[targets[i][j]];
            } else {
                targetSum = -1;
                break;
            }
        }
        answer.push(targetSum);
    }
    return answer;
}