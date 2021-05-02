N, M, B = map(int, input().split())

board = []

for _ in range(N):
    board.append(list(map(int, input().split())))


answer = []

for goal_high in range(257):
    invertory = B
    time = 0
    for i in range(N):
        for j in range(M):
            diff = board[i][j] - goal_high

            if diff > 0:
                time += diff * 2
            else:
                time += -diff
            invertory += diff

    if invertory >= 0:
        answer.append((time, goal_high))


answer = sorted(answer, key=lambda x: (x[0], -x[1]))

print(answer[0][0], answer[0][1])
