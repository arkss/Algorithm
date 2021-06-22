import sys

input = sys.stdin.readline

if __name__ == "__main__":
    broken_finger = int(input())
    broken_finger_cnt = int(input())
    answer = 0

    if broken_finger == 1:
        answer = 1 + (broken_finger_cnt) * 8
    elif broken_finger == 2:
        if broken_finger_cnt % 2 == 0:
            answer = 2 + (broken_finger_cnt // 2) * 8
        else:
            answer = (broken_finger_cnt // 2 + 1) * 8
    elif broken_finger == 3:
        answer = 3 + (broken_finger_cnt) * 4
    elif broken_finger == 4:
        if broken_finger_cnt % 2 == 0:
            answer = 4 + (broken_finger_cnt // 2) * 8
        else:
            answer = 6 + (broken_finger_cnt // 2) * 8
    elif broken_finger == 5:
        answer = 5 + (broken_finger_cnt) * 8

    answer -= 1
    print(answer)
