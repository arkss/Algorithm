def bfs(i, j):
    queue = []
    queue.append((i, j))
    visited[i][j] = True

    dxs = [0, 0, 1, -1]
    dys = [1, -1, 0, 0]

    wolf_cnt = 0
    sheep_cnt = 0

    while queue:
        x, y = queue.pop(0)

        if board[x][y] == 'v':
            wolf_cnt += 1
        if board[x][y] == 'k':
            sheep_cnt += 1

        for dx, dy in zip(dxs, dys):
            nx = x + dx
            ny = y + dy

            if 0 > nx or nx >= N or 0 > ny or ny >= M:
                continue

            if visited[nx][ny]:
                continue

            if board[nx][ny] == '#':
                continue

            visited[nx][ny] = True
            queue.append((nx, ny))

    return (wolf_cnt, sheep_cnt)


N, M = map(int, input().split())

board = []
visited = [[False for _ in range(M)] for _ in range(N)]

for i in range(N):
    row = input()
    board.append(row)


total_wolf_cnt = 0
total_sheep_cnt = 0

for i in range(N):
    for j in range(M):
        if not visited[i][j] and board[i][j] != '#':
            wolf_cnt, sheep_cnt = bfs(i, j)

            if wolf_cnt < sheep_cnt:
                total_sheep_cnt += sheep_cnt
            else:
                total_wolf_cnt += wolf_cnt


print(total_sheep_cnt, total_wolf_cnt)
