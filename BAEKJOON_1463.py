X = int(input())

answer = [0,0]

for i in range(2,X+1):
    temp = []
    temp.append(answer[i-1])
    if i % 3 == 0:
        temp.append(answer[i//3])
    if i % 2 == 0:
        temp.append(answer[i//2])
    answer.append(min(temp)+1)

print(answer[X])



