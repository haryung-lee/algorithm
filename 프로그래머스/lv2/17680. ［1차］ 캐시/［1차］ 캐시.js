function solution(cacheSize, cities) {
  let answer = 0;
  const cache = [];

  cities.map((city) => {
    const lowerCity = city.toLowerCase();
    if (cache.includes(lowerCity)) {
      answer += 1;
      cache.splice(cache.indexOf(lowerCity), 1);
    } else {
      answer += 5;
    }
    cache.push(lowerCity);
    if (cache.length > cacheSize) cache.shift();
  });

  return answer;
}