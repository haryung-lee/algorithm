const op = ['*', '+', '-'];

function solution(expression) {
  var answer = 0;
  const opArr = [];
  const numArr = [];
  let num = '';
  for (let i = 0; i < expression.length; i++) {
    if (op.includes(expression[i])) {
      numArr.push(Number(num));
      num = '';
      opArr.push(expression[i]);
    } else {
      num += expression[i];
    }
  }
  numArr.push(Number(num));
  const opPer = permutation(op);
  for (let i = 0; i < opPer.length; i++) {
    const tempNum = [...numArr];
    const tempOp = [...opArr];
    for (let j = 0; j < opPer[i].length; j++) {
      for (let k = 0; k < tempOp.length; k++) {
        if (opPer[i][j] === tempOp[k]) {
          tempNum[k] = calc(tempNum[k], tempNum[k + 1], tempOp[k]);
          tempNum.splice(k + 1, 1);
          tempOp.splice(k, 1);
          k--;
        }
      }
    }
    answer = Math.max(answer, Math.abs(tempNum[0]));
  }

  return answer;
}

function calc(num1, num2, op) {
  if (op === '*') return num1 * num2;
  if (op === '+') return num1 + num2;
  if (op === '-') return num1 - num2;
}

function permutation(arr) {
  const result = [];
  if (arr.length === 1) return [arr];
  arr.forEach((v, i) => {
    const fixer = v;
    const restArr = arr.filter((_, index) => index !== i);
    const permutationArr = permutation(restArr);
    const combineFixer = permutationArr.map((v) => [fixer, ...v]);
    result.push(...combineFixer);
  });
  return result;
}
