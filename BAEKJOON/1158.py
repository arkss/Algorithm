N, K = map(int, input().split())

idx = 0  # 사람을 가리키는 인덱스
circle = [i for i in range(1, N+1)]  # 1~N 까지의 사람 배열
answer = []  # 결과 저장

for i in range(N):
    idx = (idx + (K-1)) % len(circle)
    remove_person = circle.pop(idx)
    answer.append(remove_person)

print("<", end="")
for person in answer:
    if person == answer[-1]:
        print(str(person), end="")
    else:
        print(str(person) + ", ", end="")

print(">")
