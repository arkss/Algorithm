N = int(input())

graph = {i: [] for i in range(1, N+1)}
parents = [0 for _ in range(N+1)]
visited = [0 for _ in range(N+1)]


def bfs(node):
    queue = []

    queue.append(node)

    visited[node] = 1

    while queue:
        parent = queue.pop(0)

        for next_node in graph[parent]:

            if visited[next_node]:
                continue

            parents[next_node] = parent
            visited[next_node] = 1
            queue.append(next_node)


for _ in range(N-1):
    n1, n2 = map(int, input().split())
    graph[n1].append(n2)
    graph[n2].append(n1)

bfs(1)

for parent in parents[2:]:
    print(parent)
