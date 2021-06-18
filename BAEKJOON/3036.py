import sys

input = sys.stdin.readline


def cal_gcd(n1, n2):

    while 1:
        temp = n2
        n2 = n1 % n2
        n1 = temp

        if n2 == 0:
            break

    return n1


if __name__ == "__main__":
    N = int(input())

    arr = list(map(int, input().split()))

    first_ring = arr[0]

    for ring in arr[1:]:
        gcd = cal_gcd(first_ring, ring)
        print(f'{first_ring//gcd}/{ring//gcd}')
