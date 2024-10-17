function solution(sizes) {
    var w = 0, h = 0;
    
    for(let i = 0; i < sizes.length; i++) {
        if (sizes[i][0] > sizes[i][1]) {
            [sizes[i][0], sizes[i][1]] = [sizes[i][1], sizes[i][0]];
        }
    }
    
    for(let i = 0; i < sizes.length; i++) {
        w = Math.max(w, sizes[i][0]);
        h = Math.max(h, sizes[i][1]);
    }
    return w * h;
}