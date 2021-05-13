import sys


def calcurate_handshake_cnt(N, M, board):
    dxs = [0, 1, 1, 1]
    dys = [1, -1, 0, 1]
    cnt = 0
    for i in range(N):
        for j in range(M):
            if board[i][j] == 'o':
                for dx, dy in zip(dxs, dys):

                    if i+dx < 0 or i+dx >= N or j+dy < 0 or j+dy >= M:
                        continue
                    if board[i+dx][j+dy] == 'o':
                        cnt += 1
    return cnt


input = sys.stdin.readline

N, M = map(int, input().split())

board = []

empty_pos = []

for i in range(N):
    row = input()
    temp = []

    for j in range(M):
        if row[j] == '.':
            empty_pos.append((i, j))
        temp.append(row[j])

    board.append(temp)

max_cnt = 0

if empty_pos:

    for pos in empty_pos:
        board[pos[0]][pos[1]] = 'o'
        max_cnt = max(calcurate_handshake_cnt(N, M, board), max_cnt)
        board[pos[0]][pos[1]] = '.'

else:
    max_cnt = max(calcurate_handshake_cnt(N, M, board), max_cnt)

print(max_cnt)
