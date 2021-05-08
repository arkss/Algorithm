def is_in_board(i, j):
    return 0 <= i and i < N and 0 <= j and j < M


def check_cross(i, j):
    size = 1

    while True:
        # board 내에 있는지 확인
        if is_in_board(i-size, j) and \
                is_in_board(i+size, j) and \
                is_in_board(i, j-size) and \
                is_in_board(i, j+size):
            pass
        else:
            return size-1
        # *인지 확인
        if board[i-size][j] == '*'and \
                board[i+size][j] == '*' and \
                board[i][j-size] == '*' and \
                board[i][j+size] == '*':
            pass
        else:
            return size-1

        visited[i][j] = 1
        visited[i-size][j] = 1
        visited[i+size][j] = 1
        visited[i][j-size] = 1
        visited[i][j+size] = 1
        size += 1


N, M = map(int, input().split())

board = []
visited = [[0 for _ in range(M)] for _ in range(N)]
answers = []

for _ in range(N):
    row = input()
    board.append(row)

for i in range(1, N-1):
    for j in range(1, M-1):
        if board[i][j] == '*':
            size = check_cross(i, j)
            if size:
                answers.append((i+1, j+1, size))


is_possible = True
for i in range(N):
    for j in range(M):
        if board[i][j] == '*' and visited[i][j] == 0:
            is_possible = False
            break
    if not is_possible:
        break


if is_possible:
    print(len(answers))
    for answer in answers:
        print(answer[0], answer[1], answer[2])
else:
    print(-1)
