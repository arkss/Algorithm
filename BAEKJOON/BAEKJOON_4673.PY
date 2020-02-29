temp = list(range(1,10001))
answer = list(range(1,10001))

for i in temp:
    num = str(i)
    length = len(num)
    
    result = i
    for j in range(length):
        result += int(num[j])
    if result in answer:
        answer.remove(result)

for i in answer:
    print(i)
   