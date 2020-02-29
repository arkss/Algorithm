case = int(input())

for i in range(case):
    str = input()

    point = 0
    for i in range(len(str)):
        if str[i] == "O":
            j = 1
            while 1:
                if i == 0 or i<j or str[i-j] == "X":
                    break
                if str[i-j] == "O":
                    j += 1
            point += j
    print(point)