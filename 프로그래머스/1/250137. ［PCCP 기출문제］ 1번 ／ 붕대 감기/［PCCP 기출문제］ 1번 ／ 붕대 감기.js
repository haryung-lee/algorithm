const atarr = [];
let mx = 0;

function solution(bandage, health, attacks) {
    let answer = health;
    atarr.length = 1001;
    atarr.fill(0);
    
    for(let i = 0; i < attacks.length; i++) {
        atarr[attacks[i][0]] = attacks[i][1];
        mx = Math.max(attacks[i][0], mx);
    }
    
    let preS = 0;
    
    for(let i = 1; i <= mx; i++) {
        // 피해 받을 때
        if (atarr[i]) {
            preS = 0;
            answer -= atarr[i];
            if (answer <= 0) {
                return -1;
            }
        // 피해 받지 않을 때
        } else if (preS < bandage[0]){
            preS++;
            answer = Math.min(health, answer + bandage[1]);
        }
        
        if (preS == bandage[0]) {
            preS = 0;
            answer = Math.min(health, answer + bandage[2]); 
        }

    }
    
    return answer;
}