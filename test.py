N, M= map(int, input().split())

list = list(i for i in range(1,8))
answer_list = []

print(list)

for i in range(1,8):
    index = 3*i - (i)
    
    if index >= len(list):
        index %= len(list)
    print(i,index)
    answer_list.append(list.pop(index))

print(answer_list)