def sum_only_number(s):
    total = 0
    for c in s:
        if c.isdigit():
            total += int(c)
    return total


N = int(input())

serial_numbers = []

for _ in range(N):
    serial_numbers.append(input())


sorted_serial_numbers = sorted(
    serial_numbers,
    key=lambda x: (len(x), sum_only_number(x), x)
)


for serial_number in sorted_serial_numbers:
    print(serial_number)
