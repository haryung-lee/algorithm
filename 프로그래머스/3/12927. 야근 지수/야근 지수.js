class PriorityQueue {
    constructor() {
        this.heap = [];
    }
    
    enqueue(value) {
        this.heap.push(value);
        this.bubbleUp();
    }
    
    dequeue(value) {
        if (this.heap.length === 0) return null;
        if (this.heap.length === 1) return this.heap.pop();
        
        const max = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.bubbleDown();
        return max;
    }
    
    // 삽입된 요소가 부모보다 큰 경우, 부모와 자리를 교환하여 최대 힙 유지
    bubbleUp() {
        let index = this.heap.length - 1;
        const element = this.heap[index];
        
        while(index > 0) {
            let parentIndex = Math.floor((index - 1)/2);
            let parent = this.heap[parentIndex];
            
            if (element <= parent) break; // 최대 힙의 조건을 만족하면 중지
            
            this.heap[index] = parent;
            index = parentIndex;
        }
        
        this.heap[index] = element;
    }
    
    // 최상단 요소가 제거된 후 자식 요소들과 비교해 올바른 자리에 놓일 때까지 자리 교환
    bubbleDown() {
        let index = 0;
        const length = this.heap.length;
        const element = this.heap[0];
        
        while(true) {
            let leftChildIndex = 2*index + 1;
            let rightChildIndex = 2*index + 2;
            let leftChild, rightChild;
            let swapIndex = null;
            
            if (leftChildIndex < length) {
                leftChild = this.heap[leftChildIndex];
                if (leftChild > element) {
                    swapIndex = leftChildIndex;
                }
            }
            
            if (rightChildIndex < length) {
                rightChild = this.heap[rightChildIndex];
                if (
                    (swapIndex === null && rightChild > element) ||
                    (swapIndex !== null && rightChild > leftChild)
                ) {
                    swapIndex = rightChildIndex;
                }
            }
            
            // swap 할게 없다면, 이미 잘 정렬된 상태이므로 break
            if (swapIndex === null) break;
            
            this.heap[index] = this.heap[swapIndex];
            index = swapIndex;
        }
        
        this.heap[index] = element;
    }
    
    peek() {
        return this.heap[0] || null;
    }
    
    size() {
        return this.heap.length;
    }
}

const pq = new PriorityQueue();

function solution(n, works) {
    let answer = 0;
    
    for(let i = 0; i < works.length; i++) {
        pq.enqueue(works[i]);
    }
    
    while (n--) {
        let t = pq.dequeue(); t--;
        
        if (t > 0) pq.enqueue(t);
    }
    
    while(pq.size()) {
        const t = pq.dequeue();
        answer += t*t;
    }
    
    return answer;
}