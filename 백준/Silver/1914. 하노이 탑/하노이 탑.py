def hanoi(n, st, vi, en):
    if n == 1:
        print(st, en)
        return
    hanoi(n-1, st, en, vi)
    print(st, en)
    hanoi(n-1, vi, st, en)

N = int(input())
print(2**N - 1)

if N <= 20:
    hanoi(N, 1, 2, 3)