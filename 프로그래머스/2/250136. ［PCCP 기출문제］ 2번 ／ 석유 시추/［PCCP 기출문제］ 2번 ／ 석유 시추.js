class Queue {
  constructor() {
    this.items = [];
    this.front = 0;
    this.rear = 0;
  }

  enqueue(element) {
    this.items[this.rear] = element;
    this.rear++;
  }

  dequeue() {
    if (this.isEmpty()) {
      return null;
    }

    const dequeuedElement = this.items[this.front];
    this.front++;

    // 메모리 관리는 일정한 기준에 따라 처리할 수 있음
    if (this.front > this.rear) {
        this.front = 0; this.rear = 0;
    }
    return dequeuedElement;
  }

  isEmpty() {
    return this.rear === this.front;
  }
}

function solution(land) {
  let ans = 0;
  const n = land.length;
  const m = land[0].length;
  
  vis = Array.from({ length: n }, () => Array(m).fill(0));
  const numByTt = [];
  const dx = [0, 0, 1, -1], dy = [1, -1, 0, 0];

  function go(i, j) {
    let cnt = 1;
    const qu = new Queue();
    qu.enqueue([i, j]);
    vis[i][j] = [1, numByTt.length];

    while (!qu.isEmpty()) {
      const [x, y] = qu.dequeue();

      for (let k = 0; k < 4; k++) {
        const nx = x + dx[k], ny = y + dy[k];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (land[nx][ny] === 0 || vis[nx][ny][0]) continue;

        vis[nx][ny] = [1, numByTt.length];
        cnt++;
        qu.enqueue([nx, ny]);
      }
    }

    numByTt.push(cnt);
  }

  for (let j = 0; j < m; j++) {
    let tmp = 0;
    const set = new Map();

    for (let i = 0; i < n; i++) {
      if (land[i][j] === 0) continue;

      if (vis[i][j] === 0) vis[i][j] = [0, 0];

      if (vis[i][j][0]) {
        if (!set.has(vis[i][j][1])) {
          tmp += numByTt[vis[i][j][1]];
          set.set(vis[i][j][1], true);
        }
        continue;
      }

      go(i, j);
      tmp += numByTt[vis[i][j][1]];
      set.set(vis[i][j][1], true);
    }

    ans = Math.max(ans, tmp);
  }

  return ans;
}