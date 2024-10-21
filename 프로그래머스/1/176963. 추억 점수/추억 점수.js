const mp = new Map();

function solution(name, yearning, photo) {
    var answer = [];
    
    for(let i = 0; i < name.length; i++) {
        mp.set(name[i], yearning[i]);
    }
    
    for(let i = 0; i < photo.length; i++) {
        let sm = 0;
        for(let j = 0; j < photo[i].length; j++) {
            sm += mp.get(photo[i][j]) ?? 0;
        }
        answer.push(sm);
    }
    return answer;
}