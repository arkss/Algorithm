import re
from collections import Counter


def solution(str1, str2):
    str1_2 = []
    str2_2 = []

    str1_2 = [str1[idx:idx+2].lower() for idx in range(len(str1)-1)
              if str1[idx:idx+2].isalpha()]
    str2_2 = [str2[idx:idx+2].lower() for idx in range(len(str2)-1)
              if str2[idx:idx+2].isalpha()]

    if not str1_2 and not str2_2:
        return 65536

    str1_counters = Counter(str1_2)
    str2_counters = Counter(str2_2)

    inter_cnt = sum((str1_counters & str2_counters).values())
    union_cnt = sum((str1_counters | str2_counters).values())

    answer = int(inter_cnt / union_cnt * 65536)
    return answer
