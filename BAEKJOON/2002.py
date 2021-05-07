N = int(input())

deque = []
visited = {}

overtake_cnt = 0

for _ in range(N):
    car_num = input()
    visited[car_num] = False
    deque.append(car_num)

for _ in range(N):
    car_num = input()

    while deque and visited[deque[0]]:
        deque.pop(0)

    if deque and deque[0] == car_num:
        deque.pop(0)
    else:
        visited[car_num] = True
        overtake_cnt += 1

print(overtake_cnt)
