case = int(input())

for i in range(case):
    floor = int (input())
    number = int(input())

    apart = [[0]*number for i in range(floor+1)] 

    for i in range(number):
        apart[0][i] = i+1
    
    for j in range(floor):
        for i in range(1,number+1):
            for k in range(i):
                
                apart[j+1][i-1] += apart[j][k]
    
    print(apart[floor][number-1])

    """
    배열을 굳이 2차원 배열로 할 필요가 없었다..
    t=int(input())
for i in range(t):
    k=int(input())
    n=int(input())
    arr=[j for j in range(1,n+1)]
    for l in range(k):
        for j in range(n-1):
            arr[j+1]+=arr[j]
        #print(arr)
    print(arr)
    print(arr[-1])
    """