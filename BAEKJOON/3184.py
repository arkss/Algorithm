import sys

input = sys.stdin.readline


def bfs(i, j):
    #print(f"{i} {j}")
    visited[i][j] = 1
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    queue = [(i, j)]

    wolf_cnt = 0
    sheep_cnt = 0

    while queue:
        # print(queue)
        now_x, now_y = queue.pop(0)

        for i in range(4):
            nx = now_x + dx[i]
            ny = now_y + dy[i]

            if nx < 0 or nx >= R or ny < 0 or ny >= C:
                continue

            if visited[nx][ny]:
                continue

            if board[nx][ny] == '#':
                continue

            if board[nx][ny] == 'v':
                wolf_cnt += 1
            elif board[nx][ny] == 'o':
                sheep_cnt += 1

            visited[nx][ny] = 1
            queue.append((nx, ny))

    if wolf_cnt < sheep_cnt:
        return (sheep_cnt, 0)
    else:
        return (0, wolf_cnt)


if __name__ == "__main__":
    R, C = map(int, input().split())

    board = []

    for _ in range(R):
        board.append(input().strip())

    visited = [[0 for _ in range(C)] for _ in range(R)]

    total_sheep_cnt = 0
    total_wolf_cnt = 0

    for i in range(R):
        for j in range(C):
            if not visited[i][j]:
                sheep_cnt, wolf_cnt = bfs(i, j)

                total_sheep_cnt += sheep_cnt
                total_wolf_cnt += wolf_cnt

    print(f'{total_sheep_cnt} {total_wolf_cnt}')
