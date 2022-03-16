def bfs(start_node, connect_dict):
    queue = [start_node]
    visited = [start_node]
    while queue:
        node = queue.pop(0)
        for next_node in connect_dict[node]:
            if next_node not in visited:
                queue.append(next_node)
                visited.append(next_node)

    return len(visited)

def solution(n, wires):

    min_diff_count = 987654321
    for cut_wire_idx in range(len(wires)):

        connect_dict = {}
        for node in range(1, n + 1):
            connect_dict[node] = []

        for idx, wire in enumerate(wires):
            if idx == cut_wire_idx:
                continue
            connect_dict[wire[0]].append(wire[1])
            connect_dict[wire[1]].append(wire[0])

        connect_node_count = bfs(1, connect_dict)

        min_diff_count = min(min_diff_count, abs(n - 2 * connect_node_count))

    return min_diff_count


n = 9
wires = [[1, 3], [2, 3], [3, 4], [4, 5], [4, 6], [4, 7], [7, 8], [7, 9]]

print(solution(n, wires))
