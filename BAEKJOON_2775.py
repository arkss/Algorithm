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