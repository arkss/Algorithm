import sys

input = sys.stdin.readline
INF = 987654321


def floyd():
    for mid in range(N):
        for start in range(N):
            for end in range(N):
                if board[start][end] > board[start][mid] + board[mid][end]:
                    board[start][end] = board[start][mid] + board[mid][end]


if __name__ == "__main__":
    N = int(input())

    board = [[0 for _ in range(N)] for _ in range(N)]

    for i in range(N):
        row = input().strip()

        for j in range(N):

            if i == j:
                continue
            if row[j] == 'Y':
                board[i][j] = 1
            else:
                board[i][j] = INF

    floyd()
    max_f_cnt = 0
    for i in range(N):
        f_cnt = 0
        for j in range(N):
            if 0 < board[i][j] < 3:
                f_cnt += 1

        max_f_cnt = max(max_f_cnt, f_cnt)

    print(max_f_cnt)
