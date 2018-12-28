import math

min,max = input().split()
min = int (min)
max = int (max)
num = max - min + 1

def is_prime(n):
    seive = [False, False] + [True] * (n-1)
    
    for (i,e) in enumerate(seive):
        print(i,e)
        if e:
            k = i * 2
            while k<=n:
                seive[k] = False
                k += i
        print(seive)
    return [x**2 for (x,y) in enumerate(seive) if y]
# max 이전까지의 소수를 찾아서 소수의 제곱수가 몇개 있는지 카운팅을 해주자.



for j in is_prime(max):
    count = (max // j) - (min // j)
    num -= count
    
print(num)


    
