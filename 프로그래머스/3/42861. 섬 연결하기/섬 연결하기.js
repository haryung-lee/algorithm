class PriorityQueue {
    constructor() {
        this.heap = [];
    }
    
    enqueue(value) {
        this.heap.push(value);
        this.bubbleUp();
    }
    
    dequeue() {
        if (this.heap.length === 0) return null;
        if (this.heap.length === 1) return this.heap.pop();
        
        const min = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.bubbleDown();
        return min;
    }
    
    
    // 삽입된 요소가 부모보다 작다면, 부모와 자리를 교환하여 최소힙 유지
    bubbleUp() {
        let index = this.heap.length - 1;
        const element = this.heap[index];
        const elN = element[0];
        
        while(index > 0) {
            let parentIndex = Math.floor((index-1) / 2);
            let parent = this.heap[parentIndex];
            let paN = parent[0];
            
            if (elN >= paN) break;
            
            this.heap[index] = parent;
            index = parentIndex;
        }
        
        this.heap[index] = element;
    }
    
    bubbleDown() {
        let index = 0;
        const length = this.heap.length;
        const element = this.heap[0];
        const elN = element[0];
        
        while(true) {
            let leftChildIndex = 2*index + 1;
            let rightChildIndex = 2*index + 2;
            let leftChild, rightChild;
            let leN, riN;
            let swapIndex = null;
            
            if (leftChildIndex < length) {
                leftChild = this.heap[leftChildIndex];
                leN = leftChild[0];
                if (elN > leN) {
                    swapIndex = leftChildIndex;
                }
            }
            
            if (rightChildIndex < length) {
                rightChild = this.heap[rightChildIndex];
                riN = rightChild[0];
                if ((swapIndex === null && elN > riN) ||
                    (swapIndex !== null && leN > riN)
                   ) {
                    swapIndex = rightChildIndex;
                }
            }
            
            if (swapIndex === null) break;
            this.heap[index] = this.heap[swapIndex]
            index = swapIndex;
        }
        
        this.heap[index] = element;
    }
    
    empty() {
        return this.heap.length === 0;
    }
}

const pq = new PriorityQueue();
const v = Array.from({length: 100}, () => []);
const vis = new Array(100).fill(0);


function solution(n, costs) {
    let answer = 0;
    
    // costs로 그래프 만들기
    for(let i = 0; i < costs.length; i++) {
        const [st, en, co] = costs[i];
        v[st].push([en, co]);
        v[en].push([st, co]);
    }
    
    pq.enqueue([0, 0]); // 시작점 0
    
    
    while(!pq.empty()) {
        const t = pq.dequeue();
        const [co, node] = t;
        
        if (vis[node])continue;
        vis[node] = 1;
        answer += co;
        
        for(let i = 0; i < v[node].length; i++) {
            const [tar, c] = v[node][i];
            
            if (vis[tar]) continue;
            pq.enqueue([c, tar]);
        }
    }
    
    return answer;
}