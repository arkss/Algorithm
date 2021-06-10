import sys
input = sys.stdin.readline


def find_second_max_num(board, i, j):
    sorted_board = sorted([board[i][j], board[i+1][j],
                           board[i][j+1], board[i+1][j+1]])

    return sorted_board[2]


def pooling(board):
    board_size = len(board)
    if board_size == 1:
        return board[0][0]

    new_board = [[] for _ in range(board_size//2)]

    for i in range(0, board_size, 2):
        for j in range(0, board_size, 2):
            new_board[i//2].append(find_second_max_num(board, i, j))

    return pooling(new_board)


if __name__ == "__main__":
    N = int(input())
    board = []

    for i in range(N):
        board.append(list(map(int, input().split(' '))))

    answer = pooling(board)

    print(answer)
