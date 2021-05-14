import sys

input = sys.stdin.readline

N, M, V = map(int, input().split())


nodes = list(input().split())

snail_nodes = nodes[V-1:]

for _ in range(M):
    idx = int(input())

    if idx < V:
        print(nodes[idx])
    else:
        print(snail_nodes[(idx-(V-1)) % len(snail_nodes)])
