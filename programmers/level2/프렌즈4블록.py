def check_delete_board(m, n, board, delete_board):

    has_delete = False

    for i in range(m - 1):
        for j in range(n - 1):
            character = board[i][j]

            if character == "0":
                continue

            if (
                board[i + 1][j] == character
                and board[i][j + 1] == character
                and board[i + 1][j + 1] == character
            ):
                delete_board[i][j] = 1
                delete_board[i + 1][j] = 1
                delete_board[i][j + 1] = 1
                delete_board[i + 1][j + 1] = 1
                has_delete = True

    return has_delete


def solution(m, n, board):

    board = [list(line) for line in board]
    delete_cnt = 0

    while True:
        delete_board = [[0 for _ in range(n)] for _ in range(m)]

        rst = check_delete_board(m, n, board, delete_board)

        if not rst:
            break

        for j in range(n):
            stack = []

            for i in range(m):
                if delete_board[i][j] == 0:
                    stack.append(board[i][j])
                else:
                    delete_cnt += 1

            for i in range(m - 1, -1, -1):
                if stack:
                    board[i][j] = stack.pop()
                else:
                    board[i][j] = "0"

    answer = delete_cnt
    return answer
