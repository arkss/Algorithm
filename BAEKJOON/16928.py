def bfs(start):
    visited = [False for _ in range(101)]

    queue = [(start, 0)]
    visited[start] = 1

    while queue:
        now, move_cnt = queue.pop(0)

        if moves.get(now):
            now = moves[now]

        visited[now] = 1

        if now == 100:
            return move_cnt

        for i in range(1, 7):
            if now + i > 100:
                continue
            if not visited[now + i]:
                visited[now + i] = 1
                queue.append((now+i, move_cnt+1))


ladder_cnt, snake_cnt = map(int, input().split())

moves = {}

for _ in range(ladder_cnt+snake_cnt):
    start, end = map(int, input().split())
    moves[start] = end


move_cnt = bfs(1)

print(move_cnt)
