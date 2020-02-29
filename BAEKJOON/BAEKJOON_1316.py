N = int (input())

count = 0
for i in range(N):
    string = list(input())
    while 1:
        if len(string) == 1:
            count += 1
            break
        pop_one = string.pop(0)
        if pop_one == string[0]:
            continue
        if pop_one in string:
            break
        
print(count)