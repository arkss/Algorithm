def solution(n, arr1, arr2):
    answer = []
    for i in range(n):
        or_rst = bin(arr1[i] | arr2[i])[2:]
        
        or_rst = or_rst.rjust(n, "0")
        or_rst = or_rst.replace("1", "#")
        or_rst = or_rst.replace("0", " ")

        answer.append(or_rst)

    return answer