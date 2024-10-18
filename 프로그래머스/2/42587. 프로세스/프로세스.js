class Queue {
    constructor() {
        this.storage = new Object();
        this.front = 0;
        this.end = 0;
    }
    
    size() {
        return this.end - this.front;
    }
    
    enqueue(element) {
        this.storage[this.end] = element;
        this.end++;
    }
    
    dequeue() {
        const removed = this.storage[this.front];
        delete this.storage[this.front];
        this.front++;
        
        if (this.front === this.rear) {
            this.front = 0;
            this.end = 0;
        }
        
        return removed;
    }
}

function solution(priorities, location) {
    var answer = 0;
    const mp = new Array(10).fill(0);
    let mx = 0;
    const arr = new Array();
    
    for(let i = 0; i < priorities.length; i++) {
        arr.push([priorities[i], i]);
        mp[priorities[i]]++;
        mx = Math.max(mx, priorities[i]);
    }
    
    
    while(arr.length) {
        const t = arr.shift();

        if (t[0] < mx) {
            arr.push(t);
        } else {
            mp[mx]--;
            answer++;
            if (t[1] == location) break;
            while(mp[mx] == 0) {
                mx--;
            }
        }
    }


    
    return answer;
}