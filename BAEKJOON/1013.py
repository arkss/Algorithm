import re
p = re.compile('(100+1+|01)+')


N = int(input())

for _ in range(N):
    input_str = input()
    if p.fullmatch(input_str):
        print("YES")
    else:
        print("NO")
