input_s = input()

alphabet_count = [0 for _ in range(26)]

for c in input_s:
    alphabet_count[ord(c)-ord('A')] += 1

is_possible = True
odd_alpha = ""
answer = ""

for idx, cnt in enumerate(alphabet_count):
    if cnt == 0:
        continue

    answer += chr(idx + ord('A')) * (cnt // 2)
    if cnt % 2 == 1:
        if odd_alpha != '':
            is_possible = False
            break
        odd_alpha = chr(idx + ord('A'))


if is_possible:
    print(answer + odd_alpha + answer[::-1])
else:
    print("I'm Sorry Hansoo")
