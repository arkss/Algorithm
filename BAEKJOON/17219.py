N, M = map(int, input().split())

passwords = {}

for _ in range(N):
    url, password = input().split()

    passwords[url] = password


for _ in range(M):
    url = input()
    print(passwords[url])
