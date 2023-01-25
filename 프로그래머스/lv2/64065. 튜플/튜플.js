function solution(s) {
  const answer = [];
  const arr = s.slice(2, s.length - 2).split("},{");
  arr.sort((a, b) => a.length - b.length);
  for (let i = 0; i < arr.length; i++) {
    const temp = arr[i].split(",");
    for (let j = 0; j < temp.length; j++) {
      if (!answer.includes(Number(temp[j]))) {
        answer.push(Number(temp[j]));
      }
    }
  }
  return answer;
}
