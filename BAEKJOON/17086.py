
N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

dx = [-1, -1, -1, 0, 0, 1, 1, 1]
dy = [-1, 0, 1, -1, 1, -1, 0, 1]


def bfs(i, j):
    queue = [(i, j)]
    visited = [[0 for _ in range(M)] for _ in range(N)]

    visited[i][j] = 1

    while queue:
        now_x, now_y = queue.pop(0)

        if board[now_x][now_y]:
            return visited[now_x][now_y]

        for x, y in zip(dx, dy):
            new_x = now_x + x
            new_y = now_y + y

            if 0 > new_x or new_x >= N or 0 > new_y or new_y >= M:
                continue

            if visited[new_x][new_y]:
                continue

            visited[new_x][new_y] = visited[now_x][now_y] + 1
            queue.append((new_x, new_y))

    return 987654321


safe_distance = 0
for i in range(N):
    for j in range(M):
        if board[i][j] != 1:
            safe_distance = max(bfs(i, j), safe_distance)


print(safe_distance-1)
