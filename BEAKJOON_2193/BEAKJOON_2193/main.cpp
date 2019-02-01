
#include <iostream>

int main(int argc, const char * argv[]) {
    int num;
    int i;
    long answer[92] = {0,1,1};
    //2880067194370816120
    // 90번째가 저건데 long보다 더 크지 않나?
    // long의 범위 : -2,147,483,648 ~ 2,147,483,647
    
    std::cin >> num;
    
    for (i=3;i<=num;i++){
        // n 번째 이친수를 구하기 위헤서는 n-1번째 이친수들 뒤에 0을 붙인 것과 n-2번째 이친수들 뒤에 01을 붙인 것과 같다.
        answer[i] = answer[i-1] + answer[i-2];
        
    }
    std::cout << answer[num];
    
}
