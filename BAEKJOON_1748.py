N = int(input())

count = 0

N_length = len(str(N))

for i in range(1,N_length):
    count += i * 9 * 10 ** (i-1)

rest = N - (10 ** (N_length-1)) + 1

count += rest*N_length

print(count)

