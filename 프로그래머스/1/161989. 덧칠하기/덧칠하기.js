function solution(n, m, section) {
    var answer = 1;
    let en = section[0] + m - 1;
    
    for(let i = 0; i < section.length; i++) {
        if (section[i] <= en) continue;
        answer++;
        en = section[i] + m - 1;
        
    }
    
    
    return answer;
}