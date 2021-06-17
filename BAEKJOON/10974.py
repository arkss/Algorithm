
import sys

input = sys.stdin.readline


def backtracking(N, cnt, temp):

    if cnt == N:
        for i in temp:
            print(i, end=" ")
        print()
        return

    for i in range(1, N+1):
        if not visited[i]:
            visited[i] = 1
            temp.append(i)
            backtracking(N, cnt+1, temp)
            temp.pop()
            visited[i] = 0


if __name__ == "__main__":
    N = int(input())
    visited = [0 for _ in range(N+1)]
    backtracking(N, 0, [])
