T = int(input())

for _ in range(T):
    N = int(input())

    cafes_pos = {}

    max_x = 0

    for _ in range(N):
        x, y = map(int, input().split())
        max_x = max(max_x, x)
        if cafes_pos.get(x):
            cafes_pos[x].append(y)
        else:
            cafes_pos[x] = [y]

    cafes_order = [(-1, 0)]

    for i in range(0, max_x+1):
        if cafes_pos.get(i):
            sorted_cafes_pos = sorted(cafes_pos[i])
            # 이전 카페의 y좌표
            if cafes_order[-1][1] == sorted_cafes_pos[0]:
                for y in sorted_cafes_pos:
                    cafes_order.append((i, y))
            else:
                for y in sorted_cafes_pos[::-1]:
                    cafes_order.append((i, y))

    input_for_answer = list(map(int, input().split()))

    for i in range(1, len(input_for_answer)):
        print(cafes_order[input_for_answer[i]][0],
              cafes_order[input_for_answer[i]][1])
