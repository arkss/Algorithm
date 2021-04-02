from queue import PriorityQueue

INF = 987654321


def dijsktra(dist, adjust, K):

    pq = PriorityQueue()
    pq.put((0, 1))
    dist[1] = 0

    while not pq.empty():
        now = pq.get()
        now_dist = -now[0]
        now_node = now[1]

        for next in adjust[now_node]:
            cost = now_dist + next[1]

            if cost < dist[next[0]]:
                dist[next[0]] = cost
                pq.put((-cost, next[0]))


def solution(N, roads, K):

    dist = [INF for _ in range(N+1)]
    adjust = [[] for _ in range(N+1)]

    for road in roads:
        s = road[0]
        e = road[1]
        w = road[2]
        adjust[s].append((e, w))
        adjust[e].append((s, w))

    dijsktra(dist, adjust, K)

    answer = 0

    for i in range(1, N+1):
        if dist[i] <= K:
            answer += 1

    return answer
