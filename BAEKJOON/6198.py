N = int(input())

buildings = []

for _ in range(N):
    buildings.append(int(input()))


stack = []
total_cnt = 0
building_idx = 0

while building_idx != N:
    next_building = buildings[building_idx]
    building_idx += 1

    if not stack:
        stack.append(next_building)
    else:
        # 스택이 비거나 마지막 값이 더 클 때까지 pop()
        while stack and stack[-1] <= next_building:
            stack.pop()
        total_cnt += len(stack)
        stack.append(next_building)

print(total_cnt)
