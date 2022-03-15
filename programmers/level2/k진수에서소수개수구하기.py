def decimal_to_n_base_radix(n, k):
    tmp = ""
    while n:
        tmp += str(n % k)
        n = n // k

    return tmp[::-1]


def is_prime(n):
    if n == 1:
        return False

    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True


def solution(n, k):
    n_base_radix = decimal_to_n_base_radix(n, k)

    answer = 0
    for number in n_base_radix.split("0"):
        if number:
            answer += is_prime(int(number))
    return answer


print(solution(437674, 3))
print(solution(110011, 10))
