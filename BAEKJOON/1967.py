import sys
sys.setrecursionlimit(100000)


N = int(input())

graph = {i: [] for i in range(1, N+1)}


for _ in range(N-1):
    n1, n2, w = map(int, input().split())

    graph[n1].append((n2, w))
    graph[n2].append((n1, w))


visited = [0 for _ in range(N+1)]
max_length = -1
max_node = 0


def dfs(start, length):
    global max_length
    global max_node
    if length > max_length:
        max_length = length
        max_node = start
    visited[start] = 1

    for next_node, w in graph[start]:
        if visited[next_node]:
            continue

        visited[next_node] = 1
        dfs(next_node, length+w)


dfs(1, 0)

visited = [0 for _ in range(N+1)]

start_node = max_node
max_length = -1
max_node = 0
dfs(start_node, 0)
print(max_length)
