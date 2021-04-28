N = int(input())

queue = []

for _ in range(N):
    num = int(input())

    if num == 0:
        queue.pop()
    else:
        queue.append(num)

print(sum(queue))
