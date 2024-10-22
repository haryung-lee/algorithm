function solution(s) {
    const answer = [10000000000, -10000000000];
    const arr = s.split(" ");
    
    for(let i = 0; i < arr.length; i++) {
        answer[0] = Math.min(answer[0], arr[i]);
        answer[1] = Math.max(answer[1], arr[i]);
    }
    
    return answer.join(' ');
}