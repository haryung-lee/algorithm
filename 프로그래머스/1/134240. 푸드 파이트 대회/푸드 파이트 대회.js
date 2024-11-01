function solution(food) {
    let answer = '';
    for(let i = 1; i < food.length; i++) {
        for(let j = 0; j < food[i] - 1; j += 2) {
            answer += i;
        }
    }
    
    const reverse = answer.split('').reverse().join('');
    answer += '0';
    answer += reverse;
    return answer;
}