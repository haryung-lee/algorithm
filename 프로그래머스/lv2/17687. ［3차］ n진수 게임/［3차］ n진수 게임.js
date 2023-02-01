function solution(n, t, m, p) {
  var answer = "";
  // 진법 n, 미리 구할 숫자의 갯수 t, 게임에 참가하는 인원 m, 튜브의 순서 p

  // 1. 0부터 t*m까지 n진법으로 변환
  let num = 0;
  let str = "";
  while (num < t * m) {
    // 대문자로 변환
    str += num.toString(n).toUpperCase();

    num++;
  }

  // 2. p번째 숫자부터 t개를 뽑아서 answer에 저장
  let idx = p - 1;
  while (answer.length < t) {
    answer += str[idx];
    idx += m;
  }

  return answer;
}
