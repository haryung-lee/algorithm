function solution(wallpaper) {
    let answer = [50, 50, 0, 0];
    for(let i = 0; i < wallpaper.length; i++) {
        for(let j = 0; j < wallpaper[i].length; j++) {
            if (wallpaper[i][j] == '#') {
                answer[0] = Math.min(answer[0], i);
                answer[1] = Math.min(answer[1], j);
                answer[2] = Math.max(answer[2], i+1);
                answer[3] = Math.max(answer[3], j+1);
            }
        }
    }
    return answer;
}