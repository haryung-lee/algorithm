let N; // 주사위 개수
let D; // 주사위
let ans; // 정답
let ansSum = 0;

let A_주사위_종류, B_주사위_종류;
let A_점수, B_점수;

let A_배열 = [], B_배열 = [];

function go3(ix, sm, cnt) {
    let B_합, B_개수;
    if (ix === B_주사위_종류.length) {
        B_합 = sm;
        B_개수 = cnt;
        
        B_배열[sm] += cnt;
    } else {
        Object.entries(D[B_주사위_종류[ix] - 1]).forEach(([key, value]) => {
            go3(ix+1, sm + Number(key), cnt * value);
        });
    }
}



function go2(ix, sm, cnt) {
    let A_합, A_개수;
    if (ix === A_주사위_종류.length) {
        A_합 = sm;
        A_개수 = cnt;
        
        A_배열[sm] += cnt;
    } else {
        Object.entries(D[A_주사위_종류[ix] - 1]).forEach(([key, value]) => {
            go2(ix+1, sm + Number(key), cnt * value);
        });
    }
}



function go(arr) {
    if (arr.length === N / 2) {
        A_주사위_종류 = arr.slice();
        A_점수 = 0;
        B_점수 = 0;
        A_배열 = Array.from({length: 501}, () => 0);
        B_배열 = Array.from({length: 501}, () => 0);

        B_주사위_종류 = [];
        let ix = 0;
        for (let i = 0; i < N; i++) {
            if (ix < arr.length && arr[ix] === i + 1) {
                ix++;
            } else {
                B_주사위_종류.push(i + 1);
            }
        }
 
        go2(0, 0, 1);
        go3(0, 0, 1);
                        
        for(let i = 1; i < 501; i++) {
            for(let j = 1; j < 501; j++) {
                if (i < j) B_점수 += B_배열[j] * A_배열[i];
                else if (i > j) A_점수 += A_배열[i] * B_배열[j];
            }
        }
                
        if (A_점수 < B_점수 && ansSum < B_점수) {
            ansSum = B_점수;
            ans = B_주사위_종류.slice();
        } else if (B_점수 < A_점수 && ansSum < A_점수) {
            ansSum = A_점수;
            ans = A_주사위_종류.slice();
        }
        
    } else {
        for (let i = arr.length == 0 ? 0 : arr[arr.length-1]; i < N; i++) {
            arr.push(i + 1);
            go(arr);
            arr.pop();
        }
    }
}

function solution(dice) {
    N = dice.length;
    D = Array.from({ length: N }, () => ({ }));
    
    for(let i = 0; i < dice.length; i++) {
        for(let j = 0; j < dice[i].length; j++) {
            if (D[i][dice[i][j]]) D[i][dice[i][j]]++;
            else D[i][dice[i][j]] = 1;
        }
    }
    

    go([1]);

    return ans;
}
