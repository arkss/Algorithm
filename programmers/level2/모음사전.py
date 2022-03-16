def backtracking(x, tmp, arr, vowel):
    if x == len(vowel):
        arr.append(tmp)
        return

    for i in range(0, len(vowel)):
        tmp += vowel[i]
        backtracking(x+1, tmp, arr, vowel)
        tmp = tmp[:-1]

def solution(word):
    arr = []
    vowel = ["A", "E", "I", "O", "U"]
    for i in range(len(vowel)):
        backtracking(i, "", arr, vowel)

    sorted_arr = sorted(arr)
    return sorted_arr.index(word) + 1


print(solution("AAAAE"))
print(solution("AAAE"))
print(solution("I"))
print(solution("EIO"))


