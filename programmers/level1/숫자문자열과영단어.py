import sys

input = sys.stdin.readline


def solution(s):
    num_dic = {"zero": "0", "one": "1", "two": "2", "three": "3", "four": "4",
               "five": "5", "six": "6", "seven": "7", "eight": "8", "nine": "9"}
    answer = s
    for key, value in num_dic.items():
        answer = answer.replace(key, value)
    return int(answer)


if __name__ == "__main__":
    # print(solution("one4seveneight"))
    print(solution("23four5six7"))
