import sys


def is_same(specimen, sample):
    size = len(specimen)

    # sample[i] 부터 비교시 같은 지 확인
    for i in range(size):
        for j in range(size):
            if specimen[j] != sample[(i+j) % size]:
                break
        else:
            return True

    return False


def change_reverse(sample):
    reverse_sample = []

    for dir in sample[::-1]:
        reverse_sample.append(str((int(dir)+1) % 4 + 1))
    return reverse_sample


input = sys.stdin.readline

_ = int(input())

specimen = list(input().split())

N = int(input())

samples = []

for _ in range(N):
    samples.append(list(input().split()))

same_idxs = []

for idx, sample in enumerate(samples):
    if is_same(specimen, sample):
        same_idxs.append(idx)
    elif is_same(specimen, change_reverse(sample)):
        same_idxs.append(idx)
print(len(same_idxs))
for idx in same_idxs:
    for dir in samples[idx]:
        print(dir, end=" ")
    print()
