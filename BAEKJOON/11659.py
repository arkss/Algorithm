
import sys

input = sys.stdin.readline

if __name__ == "__main__":
    N, M = map(int, input().split())

    arr = list(map(int, input().split()))
    arr.insert(0, 0)
    arr_sum = [0 for i in range(N+1)]

    for i in range(1, N+1):
        arr_sum[i] = arr_sum[i-1] + arr[i]

    for _ in range(M):
        front, back = map(int, input().split())
        print(arr_sum[back]-arr_sum[front-1])
