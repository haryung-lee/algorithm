let cars = {};

function solution(fees, records) {
  var answer = [];

  records.forEach((record) => {
    const [time, carNum, inOut] = record.split(" ");
    const [hour, minute] = time.split(":");
    const timeInMinute = hour * 60 + minute * 1;
    if (cars[carNum] !== undefined) {
      cars[carNum].push(timeInMinute);
    } else cars[carNum] = [timeInMinute];
  });

  const sortedCarNum = Object.keys(cars).sort((a, b) => a - b);

  for (let carNum of sortedCarNum) {
    if (cars[carNum].length % 2) {
      cars[carNum].push(23 * 60 + 59);
    }

    cars[carNum] = cars[carNum].reduce((acc, cur, idx) => {
      if (idx % 2) {
        return acc + cur - cars[carNum][idx - 1];
      } else return acc;
    }, 0);
    let fee = 0;
    if (cars[carNum] <= fees[0]) {
      fee = fees[1];
    } else {
      fee = fees[1] + Math.ceil((cars[carNum] - fees[0]) / fees[2]) * fees[3];
    }
    answer.push(fee);
  }

  return answer;
}
