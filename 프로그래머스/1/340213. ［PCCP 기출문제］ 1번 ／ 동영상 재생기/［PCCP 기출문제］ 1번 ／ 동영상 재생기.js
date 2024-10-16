function getSeconds(time) {
    return Number(time[0]) * 10 * 60 + Number(time[1]) * 60 + Number(time[3]) * 10 + Number(time[4]);
}

function secondsToTime(s) {
    const minutes = Math.floor(s / 60);
    const seconds = s % 60;

    return minutes.toString().padStart(2, '0') + ":" + seconds.toString().padStart(2, '0');
}

function solution(video_len, pos, op_start, op_end, commands) {
    var answer = '';
    // 전부 초 단위로 변경
    const videoS = getSeconds(video_len);
    const posS = getSeconds(pos);
    const opStartS = getSeconds(op_start);
    const opEndS = getSeconds(op_end);
    answer = posS;
    
    if (answer >= opStartS && answer <= opEndS) {
        answer = opEndS;
    }

    for(let i = 0; i < commands.length; i++) {
        if (commands[i] == "prev") {
             answer = Math.max(0, answer - 10);
        } else {
             answer = Math.min(videoS, answer + 10);
        }

        if (answer >= opStartS && answer <= opEndS) {
            answer = opEndS;
        }
    }
    
    return secondsToTime(answer);
}