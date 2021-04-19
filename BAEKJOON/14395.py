start, end = map(int, input().split())


def bfs(start, end):
    queue = []

    queue.append((start, ""))
    visited = set()

    while queue:
        value, operators = queue.pop(0)

        if value == end:
            return operators

        for op in ('*', '+', '/'):
            if op == '*':
                new_s = value * value
            elif op == '+':
                new_s = value + value
            else:
                new_s = 1

            if 0 <= new_s <= end and new_s not in visited:
                visited.add(new_s)
                queue.append([new_s, operators + op])

    return -1


if start == end:
    answer = 0
else:
    answer = bfs(start, end)
print(answer)
