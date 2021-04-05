parent = []


def find(u):
    if u != parent[u]:
        parent[u] = find(parent[u])
    return parent[u]


def union(u, v):
    root1 = find(u)
    root2 = find(v)

    parent[root2] = root1


def solution(n, costs):

    for i in range(n):
        parent.append(i)

    costs = sorted(costs, key=lambda x: x[2])

    edge_cnt = 0
    answer = 0

    while True:
        if edge_cnt == n-1:
            break

        u, v, cost = costs.pop(0)
        print(u, v, cost)
        print(edge_cnt)

        if find(u) != find(v):
            union(u, v)
            answer += cost
            edge_cnt += 1

    return answer


solution(4, [[0, 1, 1], [0, 2, 2], [1, 2, 5], [1, 3, 1], [2, 3, 8]])
