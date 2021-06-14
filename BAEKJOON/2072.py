import sys

input = sys.stdin.readline


def print_board():
    for row in board:
        print(row)

    print()


def check_finish(board, x, y):
    # print_board()

    color = board[x][y]

    dx = [-1, -1, -1, 0, 0, 1, 1, 1]
    dy = [-1, 0, 1, -1, 1, -1, 0, 1]
    counts = [0 for _ in range(8)]

    tempx = x
    tempy = y

    for i in range(8):
        tempx = x
        tempy = y
        while 1:
            tempx += dx[i]
            tempy += dy[i]
            if 0 > tempx or tempx > 18 or 0 > tempy or tempy > 18:
                break
            if board[tempx][tempy] == color:
                counts[i] += 1
            else:
                break

    return counts[0] + counts[7] == 4 or \
        counts[1] + counts[6] == 4 or \
        counts[2] + counts[5] == 4 or \
        counts[3] + counts[4] == 4


if __name__ == "__main__":
    N = int(input())

    board = [[0 for _ in range(19)] for _ in range(19)]

    answer = -1

    for i in range(N):
        x, y = map(int, input().split())
        x -= 1
        y -= 1

        # print(f'{x} {y} / {i}')

        # 흑: 1, 백: 2
        if i % 2 == 0:
            board[x][y] = 1
        else:
            board[x][y] = 2

        is_finish = check_finish(board, x, y)

        if is_finish:
            answer = i+1
            break

        # print_board()

    print(answer)
