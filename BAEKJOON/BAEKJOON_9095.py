def plus(n):
    if n == 1:
        return 1
    if n == 2:
        return 2
    if n == 3:
        return 4
    return plus(n-1) + plus(n-2) + plus(n-3)
N = int(input())
for i in range(N):
   answer=plus(int(input()))
   print(answer)
