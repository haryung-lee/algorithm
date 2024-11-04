const answer = [];
const canBase = {
    2: true,
    3: true,
    4: true,
    5: true,
    6: true,
    7: true,
    8: true,
    9: true
};;

function addInBase(num1, num2, base) {
    const sum = parseInt(num1, base) + parseInt(num2, base);
    return isNaN(sum) ? null : sum.toString(base);
}

function subInBase(num1, num2, base) {
    const sub = parseInt(num1, base) - parseInt(num2, base);
    return isNaN(sub) ? null : sub.toString(base);
}

// s가 주어지면 가능한 result를 return
function go(s) {
    let [front,result] = s.split(' = ');
    
    // + 연산
    if (front.indexOf('+') !== -1) {
        let [num1, num2] = front.split(' + ');
        
        // 각 진수가 만족하는지 확인
        for(let i = 2; i < 10; i++) {
            const r = addInBase(num1, num2, i);
             if (!r || r !== result) {
                canBase[i] = false;
            }
        }
    } else {
        // 각 진수가 만족하는지 확인
        for(let i = 2; i < 10; i++) {
            let [num1, num2] = front.split(' - ');
            const r = subInBase(num1, num2, i);
            if (!r || r !== result) {
                canBase[i] = false;
            }
        }
    }
    
    
}

function solution(expressions) {
    const ret = [];
    for(let i = 0; i < expressions.length; i++) {
        const [front, result] = expressions[i].split(' = ');
        
        if (result == 'X') {
            answer.push(expressions[i]); // 추후 답을 구해야 함
            if (front.indexOf('+') !== -1) {
                const [num1, num2] = front.split(' + ');
                for(let j = 2; j < 10; j++) {
                    if (isNaN(parseInt(num1, j)) || isNaN(parseInt(num2, j))) {
                        canBase[j] = false;
                    }
                }
            } else {
                const [num1, num2] = front.split(' - ');
                for(let j = 2; j < 10; j++) {
                    if (isNaN(parseInt(num1, j)) || isNaN(parseInt(num2, j))) {
                        canBase[j] = false;
                    }
                }
            }
        } else {
            go(expressions[i]);
        }
    }
    

    // 몇진수인지 찾기
    const base = Object.entries(canBase).filter(([key, value]) => value == true).map(([key]) => Number(key));
    
    
    for(let i = 0; i < answer.length; i++) {
        const [front,result] = answer[i].split(' = ');
        let res;
        
        for(let j = 0; j < base.length; j++) {
            if (res == '?') break;
            
            if (front.indexOf('+') !== -1) {
                const [num1, num2] = front.split(' + ');
                const r = addInBase(num1, num2, base[j]);

                if (!!r && !res) {
                    res = r;
                } else if (!!r && r != res) {
                    res = '?';
                }
            } else {
                const [num1, num2] = front.split(' - ');
                const r = subInBase(num1, num2, base[j]);
                 if (!!r && !res) {
                    res = r;
                } else if (!!r && r != res) {
                    res = '?';
                }
            }
        }
        ret.push(front + ' = ' + res);

    }
    
    return ret;
}