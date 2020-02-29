N, M= map(int, input().split())

list = [True] * N
answer_list = []

count = 0
j = 0
for i in range(N):
    while 1:
        if list[j]:
            count += 1
            if count == M:
                list[j] = False
                count = 0
                answer_list.append(j+1)
                break
        j += 1
        if j >= N:
            j %= N

print("<"+", ".join(map(str,answer_list))+">")

# 시간 초과 나온다 ㅠㅠ