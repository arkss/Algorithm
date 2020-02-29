x = int(input())

n = 0
while x>0:
    x -= n
    n+= 1

    
count = x + n -1 


if n % 2 == 0:
    print("{}/{}".format(n-count,count))
else:
    print("{}/{}".format(count,n-count))
