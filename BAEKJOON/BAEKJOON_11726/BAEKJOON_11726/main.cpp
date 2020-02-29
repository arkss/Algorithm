#include <iostream>

int main(int argc, const char * argv[]) {
    int num;
    int i;
    int answer[1001]={0,1,2};
    // 0은 index를 맞춰주기 위함
    // index 자리에는 n이 index일 때의 경우의 수가 온다.
    // n=1) 1가지 n=2) 2가지
    
    std::cin >> num;
    
    for (i=3;i<=num;i++){
        answer[i] = (answer[i-1] + answer[i-2])%10007;
    }
    
    std::cout << answer[num];
    
// %10007을 결과 출력할 때 해주면 안되는거지?
}
