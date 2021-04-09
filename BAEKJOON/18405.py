N, K = map(int, input().split())

board = []


for i in range(N):
    rows = list(map(int, input().split()))
    board.append(rows)


S, X, Y = map(int, input().split())
X -= 1
Y -= 1


def bfs(x, y, s, visited):

    answer = []
    queue = []
    queue.append((x, y))
    visited[x][y] = 1
    dx = [0, 0, -1, 1]
    dy = [1, -1, 0, 0]

    while queue:
        now_x, now_y = queue.pop(0)

        for cx, cy in zip(dx, dy):
            next_x = now_x + cx
            next_y = now_y + cy

            if next_x < 0 or next_x >= N or next_y < 0 or next_y >= N:
                continue

            if visited[next_x][next_y]:
                continue

            visited[next_x][next_y] = visited[now_x][now_y] + 1

            if visited[next_x][next_y] > s+1:
                return answer

            if board[next_x][next_y]:
                answer.append((board[next_x][next_y], visited[next_x][next_y]))
            queue.append((next_x, next_y))

    return answer


if board[X][Y]:
    print(board[X][Y])
else:
    visited = [[0 for _ in range(N)] for _ in range(N)]
    answer = bfs(X, Y, S, visited)

    if not answer:
        print(0)
    else:
        answer = sorted(answer, key=lambda x: (x[1], x[0]))
        print(answer[0][0])
