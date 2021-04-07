N = int(input())

graph = {i: [] for i in range(N)}
visited = [0 for _ in range(N)]

parents = list(map(int, input().split()))
delete_node = int(input())

root = -1
left_node_cnt = 0


def bfs(start):
    global left_node_cnt
    queue = []
    queue.append(start)
    visited[start] = 1

    while queue:
        now = queue.pop(0)

        if now == start and len(graph[now]) == 0:
            left_node_cnt += 1

        if len(graph[now]) == 1 and graph[now][0] == parents[now]:
            left_node_cnt += 1

        for next_node in graph[now]:

            if visited[next_node]:
                continue

            visited[next_node] = 1
            queue.append(next_node)


for idx, parent in enumerate(parents):
    if parent == -1:
        root = idx
        continue
    if idx == delete_node or parent == delete_node:
        continue

    graph[idx].append(parent)
    graph[parent].append(idx)

# print(graph)

if delete_node == root:
    print(0)
else:
    bfs(root)
    print(left_node_cnt)
