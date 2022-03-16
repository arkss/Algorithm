def solution(numbers):
    answer = []
    for number in numbers:
        number = int(number)
        binary_number = bin(number)[2:]

        left_one_count = 0
        for bit in reversed(binary_number):
            if bit == '1':
                left_one_count += 1
            else:
                break

        if left_one_count == 0:
            answer.append(number+1)
        else:
            answer.append(number + 2 ** (left_one_count - 1))
    return answer

"""
1 1
2 1
3 2
4 1
5 1
6 1
7 4
8 1
9 1
10 1
11 2
12 1
13 1
14 1
15 8
16 1
17 1
18 1
19 2
20 1
21 1
22 1
23 4
24 1
25 1
26 1
27 2
28 1
29 1
"""