
#include <iostream>

int dp[101];
// index 0~4까지는 비우고 index와 방의 수를 일치시켜주자.

// 소수의 계수를 세는 함수
int prime_count(int num)
{
    int count = 0;
    int i;
    
    for(i=2;i*i<=num;i++){
        if (num%i==0){
            if (num == i*i)
                count++;
            else
                count += 2;
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
    int T;
    int i;
    std::cin >>T;
    
//    dp 배열을 먼저 만들어준다.
//    i개의 방에 대한 정보는 i-1개의 방에 대한 정보에 i번째 방에 대한 정보만 추가해주면 된다.
//    따라서 i번째 방의 소수의 개수를 구해 계산해주었다.
    dp[5] = 2;
    for(i=6;i<101;i++){
        dp[i] = dp[i-1] + prime_count(i)%2;
    }
    
    for(i=0;i<T;i++){
        int room;
        std::cin >> room;
        std::cout << dp[room] << std::endl;
    }
}
